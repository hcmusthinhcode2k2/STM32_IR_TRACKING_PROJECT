#include <stm32f103c8t6.h>

#define IR_STATE_IDLE                   0
#define IR_STATE_START_TRIGG            1
#define IR_STATE_WAIT_FALL              2
#define IR_STATE_WAIT_RISE              3
#define IR_STATE_WAIT_DATA_LOW          4
#define IR_STATE_WAIT_DATA_HIGH         5
#define IR_STATE_IDLE_TEMP              6
#define IR_STATE_ERROR                  7

struct
{
  unsigned char State;
  unsigned char Logic;
  unsigned char TimeHigh;
  unsigned char Count;
  
  unsigned char Buff[9];
  unsigned int* BBPointer;
} IRCapture = {.State = IR_STATE_IDLE, .Logic = 0, .Count = 0};


struct
{
  unsigned char HaveData;
  unsigned char Length;
  unsigned char Buff[9];
} IRReader = {.HaveData = 0, .Length = 0, };

void SysTick_Handler()
{
  if (IRCapture.State == IR_STATE_IDLE_TEMP)
  {
    if (!GPIOA.IDR.BITS.b5)
    {
      IRCapture.State = IR_STATE_WAIT_RISE;
      IRCapture.Logic = GPIOA.IDR.BITS.b5;
      IRCapture.Count = 0;
    }
  }
  if (IRCapture.State == IR_STATE_ERROR)
  {
    if (GPIOA.IDR.BITS.b5)
      IRCapture.State = IR_STATE_IDLE;
    return;
  }
  if (IRCapture.Logic != GPIOA.IDR.BITS.b5)
  {
    IRCapture.Logic = GPIOA.IDR.BITS.b5;
    switch (IRCapture.State)
    {
      case IR_STATE_IDLE:
        IRReader.HaveData = 1;
        IRCapture.State = IR_STATE_START_TRIGG; 
        IRCapture.BBPointer = BITBAND_SRAM_POINTER(IRCapture.Buff, 0);
        for (unsigned long i = 0; i < 9; i++)
          IRCapture.Buff[i] = 0;
        break;
      case IR_STATE_START_TRIGG: IRCapture.State = IR_STATE_WAIT_FALL; break;
      case IR_STATE_WAIT_FALL: IRCapture.State = IR_STATE_WAIT_RISE; break;
      case IR_STATE_WAIT_RISE: IRCapture.State = IR_STATE_WAIT_DATA_LOW; break;
      case IR_STATE_WAIT_DATA_LOW: 
        IRCapture.TimeHigh = IRCapture.Count;
        IRCapture.State = IR_STATE_WAIT_DATA_HIGH;
        break;
      case IR_STATE_WAIT_DATA_HIGH:
        *IRCapture.BBPointer = IRCapture.TimeHigh > (2 * IRCapture.Count);
        IRCapture.BBPointer++;
        
//        if (IRCapture.TimeHigh > (2 * IRCapture.Count))
//        {
//          //capture bit 1
//        }
//        else
//        {
//          //capture bit 0
//        }
        IRCapture.State = IR_STATE_WAIT_DATA_LOW;
        break;
    }
    
    IRCapture.Count = 0;
  }
  else
  {
    IRCapture.Count++;
    if (IRCapture.State == IR_STATE_WAIT_DATA_LOW && IRCapture.Count > 100)
    {
      IRCapture.State = IR_STATE_IDLE_TEMP;
      IRCapture.BBPointer += ((unsigned long)IRCapture.BBPointer / 4) & 7;
      IRCapture.Count = 0;
    }
    if (IRCapture.Count > 240)
    {
      if (IRCapture.Logic)
      {
        IRCapture.State = IR_STATE_IDLE;
        if (IRReader.HaveData)
        {
          IRReader.HaveData = 0;
          unsigned long delta = IRCapture.BBPointer - (BITBAND_SRAM_POINTER(IRCapture.Buff, 0));
          IRReader.Length = (delta / 9) + (delta % 9 ? 1 : 0);
          for (unsigned long i = 0; i < IRReader.Length; i++)
            IRReader.Buff[i] = IRCapture.Buff[i];
        }
      }
      else
        IRCapture.State = IR_STATE_ERROR;
      IRCapture.Count = 0;
    }
  }
}

unsigned char Learn = 0;
unsigned char ToggleRed_Buff[9];


void main()
{
  RCC_BITBAND.APB2_ENR.IOPA = 1;
  GPIOA.ODR.REG = BIT3 | BIT5; 
  
  
  GPIO_Mode(&GPIOA, BIT1 | BIT3 | BIT8, GPIO_MODE_OUTPUT_PUSHPULL_2MHz);
  GPIO_Mode(&GPIOA, BIT5, GPIO_MODE_INPUT_PULL);
  
  
  RCC_BITBAND.APB2_ENR.IOPC = 1;
  GPIO_Mode(&GPIOC, BIT13, GPIO_MODE_OUTPUT_PUSHPULL_2MHz);  
  
  IRCapture.Logic = GPIOA.IDR.BITS.b5;
  
  STK_Init(400);  //System tick 50us
  
   while (1)
  {
    if (IRReader.Length)
    {
      if (Learn)
      {
        unsigned long match = 1;
        for (unsigned long i = 0; i < IRReader.Length; i++)
        {
          if (ToggleRed_Buff[i] != IRReader.Buff[i])
          {
            match = 0;
            break;
          }              
        }
        if (match)
          GPIOC.ODR.BITS.b13 = !GPIOC.ODR.BITS.b13;
      }
      else
      {
        Learn = 1;
        for (unsigned long i = 0; i < IRReader.Length; i++)
          ToggleRed_Buff[i] = IRReader.Buff[i];
      }
      IRReader.Length = 0;
    }
  }
}