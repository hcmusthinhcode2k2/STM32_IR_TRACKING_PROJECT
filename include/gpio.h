#ifndef _GPIO_H_
#define _GPIO_H_

#include <define.h>
//                                      |       //Address       Default         Description
typedef struct
{
  BUNION(CRL, unsigned long,                    //              0x4444'4444     Port configuration register
      MODE_0                            , 2,    //0-1           0                       0: Input mode (reset state)
                                                //                                      1: Output mode, max speed 10 MHz.
                                                //                                      2: Output mode, max speed 2 MHz.
                                                //                                      3: Output mode, max speed 50 MHz
       CNF_0                            , 2,    //2-3           1               In input mode:
                                                //                                      0: Analog mode
                                                //                                      1: Floating input (reset state)
                                                //                                      2: Input with pull-up / pull-down
                                                //                              In output mode:
                                                //                                      0: General purpose output push-pull
                                                //                                      1: General purpose output Open-drain
                                                //                                      2: Alternate function output Push-pull
                                                //                                      3: Alternate function output Open-drain
      MODE_1                            , 2,    //4-5
       CNF_1                            , 2,    //6-7
      MODE_2                            , 2,    //8-9
       CNF_2                            , 2,    //10-11
      MODE_3                            , 2,    //12-13
       CNF_3                            , 2,    //14-15
      MODE_4                            , 2,    //16-17
       CNF_4                            , 2,    //18-19
      MODE_5                            , 2,    //20-21
       CNF_5                            , 2,    //22-23
      MODE_6                            , 2,    //24-25
       CNF_6                            , 2,    //26-27
      MODE_7                            , 2,    //28-29
       CNF_7                            , 2);   //30-31
  BUNION(CRH, unsigned long,                    //              0x4444'4444     
      MODE_8                            , 2,    //0-1
       CNF_8                            , 2,    //2-3
      MODE_9                            , 2,    //4-5
       CNF_9                            , 2,    //6-7
      MODE_10                           , 2,    //8-9
       CNF_10                           , 2,    //10-11
      MODE_11                           , 2,    //12-13
       CNF_11                           , 2,    //14-15
      MODE_12                           , 2,    //16-17
       CNF_12                           , 2,    //18-19
      MODE_13                           , 2,    //20-21
       CNF_13                           , 2,    //22-23
      MODE_14                           , 2,    //24-25
       CNF_14                           , 2,    //26-27
      MODE_15                           , 2,    //28-29
       CNF_15                           , 2);   //30-31   
  BUNION(IDR, unsigned long,                    //              0x0000'----     Port input data register
      xBITS_B(b, 0, 15, 1),                     //
      _reserved                         , 16);  //
  BUNION(ODR, unsigned long,                    //              0x0000'0000     Port output data register
      xBITS_B(b, 0, 15, 1),                     //
      _reserved                         , 16);  //
  union
  {
    unsigned long REG;
    struct
    {
      xBUNION(BSR, unsigned short, b, 0, 15, 1);//              0x0000          Write 1 to set pin output, set has priority 
      xBUNION(BR, unsigned short, b, 0, 15, 1); //              0x0000          Write 1 to clear pin output
    };
  } BSRR;                                       //                              Port bit set/reset register
  BUNION(BRR, unsigned long,                    //              0x0000'0000     Port bit reset register, Write 1 to clear pin output
      xBITS_B(b, 0, 15, 1),                     //
      _reserved                         , 16);  //
  BUNION(LCKR, unsigned long,                   //              0x0000'0000     Port configuration lock register
      xBITS_B(b, 0, 15, 1),                     //
      LOCK                              , 1,    //16            0               LOCK key writing sequence: write 1 -> 0 -> 1 -> read 0 -> 1
      _reserved                         , 15);  //
} GPIO_TypeDef;

typedef struct
{
  RSTRUCT(CRL, unsigned long,                   //              0x4444'4444     Port configuration register
      MODE_0                            [2],    //0-1           0                       0: Input mode (reset state)
                                                //                                      1: Output mode, max speed 10 MHz.
                                                //                                      2: Output mode, max speed 2 MHz.
                                                //                                      3: Output mode, max speed 50 MHz
       CNF_0                            [2],    //2-3           1               In input mode:
                                                //                                      0: Analog mode
                                                //                                      1: Floating input (reset state)
                                                //                                      2: Input with pull-up / pull-down
                                                //                              In output mode:
                                                //                                      0: General purpose output push-pull
                                                //                                      1: General purpose output Open-drain
                                                //                                      2: Alternate function output Push-pull
                                                //                                      3: Alternate function output Open-drain
      MODE_1                            [2],    //
       CNF_1                            [2],    //
      MODE_2                            [2],    //
       CNF_2                            [2],    //
      MODE_3                            [2],    //
       CNF_3                            [2],    //
      MODE_4                            [2],    //
       CNF_4                            [2],    //
      MODE_5                            [2],    //
       CNF_5                            [2],    //
      MODE_6                            [2],    //
       CNF_6                            [2],    //
      MODE_7                            [2],    //
       CNF_7                            [2]);   //
  RSTRUCT(CRH, unsigned long,                   //              0x4444'4444     
      MODE_8                            [2],    //
       CNF_8                            [2],    //
      MODE_9                            [2],    //
       CNF_9                            [2],    //
      MODE_10                           [2],    //
       CNF_10                           [2],    //
      MODE_11                           [2],    //
       CNF_11                           [2],    //
      MODE_12                           [2],    //
       CNF_12                           [2],    //
      MODE_13                           [2],    //
       CNF_13                           [2],    //
      MODE_14                           [2],    //
       CNF_14                           [2],    //
      MODE_15                           [2],    //
       CNF_15                           [2]);   //  
  RSTRUCT(IDR, unsigned long,                   //              0x0000'----     Port input data register
      xREGS_R(b, 0, 15, ),                      //
      _reserved                         [16]);  //
  RSTRUCT(ODR, unsigned long,                   //              0x0000'0000     Port output data register
      xREGS_R(b, 0, 15, ),                      //
      _reserved                         [16]);  //
  struct
  {
      xRSTRUCT(BSR, unsigned long, b, 0, 15, ); //              0x0000          Write 1 to set pin output, set has priority 
      xRSTRUCT(BR, unsigned long, b, 0, 15, );  //              0x0000          Write 1 to clear pin output
  } BSRR;                                       //                              Port bit set/reset register
  RSTRUCT(BRR, unsigned long,                   //              0x0000'0000     Port bit reset register, Write 1 to clear pin output
      xREGS_R(b, 0, 15, ),                      //
      _reserved                         [16]);  //
  RSTRUCT(LCKR, unsigned long,                  //              0x0000'0000     Port configuration lock register
      xREGS_R(b, 0, 15, ),                      //
      LOCK                                 ,    //16            0               LOCK key writing sequence: write 1 -> 0 -> 1 -> read 0 -> 1
      _reserved                         [15]);  //
} GPIO_BITBAND_TypeDef;
//==============================================================================================================================================================
//==============================================================================================================================================================
//==============================================================================================================================================================
/*NOTE: default:
  +)JTAG debugger:
    -PA15: JTDI
    -PB3: JTDO
    -PB4: NJTRST
  +)SWD debugger:
    -PA13: SWDIO
    -PA14: SWCLK
  >>config by AFIO:
    RCC_BITBAND.APB2_ENR.AFIO = 1;
    AFIO.MAPR.BITS.SWJ_CFG = 0; //reset state
    AFIO.MAPR.BITS.SWJ_CFG = 1; //x(NJTRST)
    AFIO.MAPR.BITS.SWJ_CFG = 2; //x(JTAG)
    AFIO.MAPR.BITS.SWJ_CFG = 3; //x(JTAG & SWD)

  +)Remeber turn on RCC:
    RCC_BITBAND.APB2_ENR.IOPA = 1;
    RCC_BITBAND.APB2_ENR.IOPB = 1;
    RCC_BITBAND.APB2_ENR.IOPC = 1;
    RCC_BITBAND.APB2_ENR.IOPD = 1;
    RCC_BITBAND.APB2_ENR.IOPE = 1;
    RCC_BITBAND.APB2_ENR.IOPF = 1;
    RCC_BITBAND.APB2_ENR.IOPG = 1;
*/
//==============================================================================================================================================================
typedef enum
{
  GPIO_MODE_INPUT_ANALOG                = (0 << 2) | 0,
  GPIO_MODE_INPUT_FLOAT                 = (1 << 2) | 0,
  GPIO_MODE_INPUT_PULL                  = (2 << 2) | 0,
  
  GPIO_MODE_OUTPUT_PUSHPULL_10MHz       = (0 << 2) | 1,
  GPIO_MODE_OUTPUT_OPEN_10MHz           = (1 << 2) | 1,
  GPIO_MODE_AF_OUTPUT_PUSHPULL_10MHz    = (2 << 2) | 1,
  GPIO_MODE_AF_OUTPUT_OPEN_10MHz        = (3 << 2) | 1,
  
  GPIO_MODE_OUTPUT_PUSHPULL_2MHz        = (0 << 2) | 2,
  GPIO_MODE_OUTPUT_OPEN_2MHz            = (1 << 2) | 2,
  GPIO_MODE_AF_OUTPUT_PUSHPULL_2MHz     = (2 << 2) | 2,
  GPIO_MODE_AF_OUTPUT_OPEN_2MHz         = (3 << 2) | 2,
  
  GPIO_MODE_OUTPUT_PUSHPULL_50MHz       = (0 << 2) | 3,
  GPIO_MODE_OUTPUT_OPEN_50MHz           = (1 << 2) | 3,
  GPIO_MODE_AF_OUTPUT_PUSHPULL_50MHz    = (2 << 2) | 3,
  GPIO_MODE_AF_OUTPUT_OPEN_50MHz        = (3 << 2) | 3,  
} GPIO_MODE;
void GPIO_Mode(volatile GPIO_TypeDef* GPIO, unsigned int PIN, GPIO_MODE Mode);
//==============================================================================================================================================================
/*Fast init GPIO by define, Example:
  GPIO_ModeHigh(&GPIOA, PIN_Clr(11) | PIN_Clr(12), PIN_OutAFOpen50(11) | PIN_OutAFOpen50(12));  //= GPIO_Mode(&GPIOA, BIT11 | BIT12, OUTPUT_AF_PUSHPULL_50MHZ);
  GPIO_ModeHigh(&GPIOB, PIN_Clr(0) | PIN_Clr(1), PIN_OutPush2(0) | PIN_OutPush2(1));            //= GPIO_Mode(&GPIOB, BIT1 | BIT2, OUTPUT_PUSHPULL_50MHZ);
*/
#define PIN_Clr(index)                          (0xFUL << (4 * (index % 8)))
#define PIN_OutPush10(index)                    (0x1UL << (4 * (index % 8)))
#define PIN_OutPush2(index)                     (0x2UL << (4 * (index % 8)))
#define PIN_OutPush50(index)                    (0x3UL << (4 * (index % 8)))
#define PIN_OutOpen10(index)                    (0x5UL << (4 * (index % 8)))
#define PIN_OutOpen2(index)                     (0x6UL << (4 * (index % 8)))
#define PIN_OutOpen50(index)                    (0x7UL << (4 * (index % 8)))
#define PIN_OutAFPush10(index)                  (0x9UL << (4 * (index % 8)))
#define PIN_OutAFPush2(index)                   (0xAUL << (4 * (index % 8)))
#define PIN_OutAFPush50(index)                  (0xBUL << (4 * (index % 8)))
#define PIN_OutAFOpen10(index)                  (0xDUL << (4 * (index % 8)))
#define PIN_OutAFOpen2(index)                   (0xEUL << (4 * (index % 8)))
#define PIN_OutAFOpen50(index)                  (0xFUL << (4 * (index % 8)))
#define PIN_InAnalog(index)                     (0x0UL << (4 * (index % 8)))
#define PIN_InFloat(index)                      (0x4UL << (4 * (index % 8)))
#define PIN_InPushDown(index)                   (0x8UL << (4 * (index % 8)))    //ODR.PIN = 0
#define PIN_InPushUp(index)                     (0x8UL << (4 * (index % 8)))    //ODR.PIN = 1
#define GPIO_ModeLow(GPIO, PIN_Clear, PIN_Mode)   (GPIO)->CRL.REG &= ~(PIN_Clear); (GPIO)->CRL.REG |= (PIN_Mode)        //for pin 0->7
#define GPIO_ModeHigh(GPIO, PIN_Clear, PIN_Mode)  (GPIO)->CRH.REG &= ~(PIN_Clear); (GPIO)->CRH.REG |= (PIN_Mode)        //for pin 8->15      //for pin 8->15

#endif