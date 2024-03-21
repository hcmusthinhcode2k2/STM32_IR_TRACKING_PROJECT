#include <stm32f103c8t6.h>

#define BUTTON_NONE 0 
#define BUTTON_DOWN 1
#define BUTTON_UP   2
/*system stick*/
struct 
{
  struct 
  {
    unsigned char MsTick;
  }Event;
}System = 
{
  .Event = 
  {
    .MsTick = 1,
  }, 
};
/*Button*/
struct 
{
  unsigned char Event;
  unsigned char Logic;
}Button = {.Event = BUTTON_NONE,};
/* Led */
struct 
{
  unsigned char Blink;
}Led = {.Blink =0,};

void SysTick_Handler()
{
  System.Event.MsTick = 1;
}
void BaseProcess()
{
  if (System.Event.MsTick)
  {
    
    System.Event.MsTick =0;
    //button handle
    static unsigned char  count_10ms =0;
    count_10ms++;
    if (count_10ms>10)
    {
        count_10ms =0;
        if (Button.Logic != GPIOB.IDR.BITS.b8)
        {
          Button.Logic = GPIOB.IDR.BITS.b8;
          Button.Event = Button.Logic + 1;
        }
    }
    //led handle
    if (Led.Blink)
    {
      static unsigned short count_1s = 0;
      count_1s++;
      if (count_1s >= 1000)
      {
        count_1s = 0;
        GPIOB_BITBAND.ODR.b12 = !GPIOB_BITBAND.ODR.b12;
      }
    }
  }
}
void main()
{
    RCC_BITBAND.APB2_ENR.IOPB = 1; // Enable clock for GPIOB

    // Configure PB12 as General purpose output push-pull with max speed 50MHz
    GPIO_Mode(&GPIOB, BIT12, GPIO_MODE_OUTPUT_PUSHPULL_50MHz);

    // Configure PB8 as input with pull-up / pull-down (previously set to pull-up explicitly)
    GPIO_Mode(&GPIOB, BIT8, GPIO_MODE_INPUT_PULL);
    GPIOB.ODR.BITS.b8 = 1; // Ensure pull-up is enabled

    Button.Logic = GPIOB.IDR.BITS.b8;

    // System Tick Timer Configuration
    STK.LOAD = 1000; // Load value for 1ms tick
    STK.CTRL.BITS.TICK_INT = 1; // Enable SysTick interrupt
    STK.CTRL.BITS.CLK_SOURCE = 1; // Select processor clock
    STK.CTRL.BITS.ENABLE = 1; // Enable SysTick timer

    while (1)
    {
        BaseProcess();
        if (Button.Event == BUTTON_DOWN)
        {
            Button.Event = BUTTON_NONE;
            Led.Blink = !Led.Blink;
        }
    }
}
