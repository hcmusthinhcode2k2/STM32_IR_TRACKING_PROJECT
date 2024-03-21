#ifndef _BASIC_TIMER_H_
#define _BASIC_TIMER_H_

#include <common.h>
#include <define.h>
//                                      |       //Address       Default         Description
typedef struct
{
  BUNION(CR1, unsigned int,                     //              0x0000.0000     TIMx control register 1
    CEN                                 , 1,    //0             0               Counter enable
    UDIS                                , 1,    //1             0               Update disable
    URS                                 , 1,    //2             0               Update request source
    OPM                                 , 1,    //3             0               One pulse mode
    _Reserved                           , 3,
    APRE                                , 1,    //7             0               Auto-reload preload enable
    _Reserved1                          , 24);
  BUNION(CR2, unsigned int,                     //              0x0000.0000     TIMx control register 2
    _Reserved                           , 4,
    MMS                                 , 3,    //4:6           0               Master mode selection
    _Reserved1                          , 25);
  unsigned int _Reserved;
  BUNION(DIER, unsigned int,                    //              0x0000.0000     TIMx DMA/interrupt enable register
    UIE                                 , 1,    //0             0               Update interrupt enable
    _Reserved                           , 7,
    UDE                                 , 1,    //8             0               Update DMA request enable
    _Reserved1                          , 23);
  BUNION(SR, unsigned int,                      //              0x0000.0000     TIMx status register
    UIF                                 , 1,    //0             0               Update interrupt flag
    _Reserved                           , 31);
  BUNION(EGR, unsigned int,                     //              0x0000.0000     TIMx event generation register
    UG                                  , 1,    //0             0               Update generation
    _Reserved                           , 31);
  unsigned int _Reserved1[3];
  unsigned int CNT;                             //              0x0000.0000     TIMx counter
  unsigned int PSC;                             //              0x0000.0000     TIMx prescaler
  unsigned int ARR;                             //              0x0000.FFFF     TIMx auto-reload register
} BASIC_TIMER_TypeDef;

typedef struct
{
  RSTRUCT(CR1, unsigned int,                    //              0x0000.0000     TIMx control register 1
    CEN                                    ,    //0             0               Counter enable
    UDIS                                   ,    //1             0               Update disable
    URS                                    ,    //2             0               Update request source
    OPM                                    ,    //3             0               One pulse mode
    _Reserved                           [3],
    APRE                                   ,    //7             0               Auto-reload preload enable
    _Reserved1                          [24]);
  RSTRUCT(CR2, unsigned int,                    //              0x0000.0000     TIMx control register 2
    _Reserved                           [4],
    MMS                                 [3],    //4:6           0               Master mode selection
    _Reserved1                          [25]);
  unsigned int _Reserved;
  RSTRUCT(DIER, unsigned int,                   //              0x0000.0000     TIMx DMA/interrupt enable register
    UIE                                    ,    //0             0               Update interrupt enable
    _Reserved                           [7],
    UDE                                    ,    //8             0               Update DMA request enable
    _Reserved1                          [23]);
  RSTRUCT(SR, unsigned int,                     //              0x0000.0000     TIMx status register
    UIF                                    ,    //0             0               Update interrupt flag
    _Reserved                           [31]);
  RSTRUCT(EGR, unsigned int,                    //              0x0000.0000     TIMx event generation register
    UG                                     ,    //0             0               Update generation
    _Reserved                           [31]);
  unsigned int _Reserved1[3][32];
  unsigned int CNT[32];                         //              0x0000.0000     TIMx counter
  unsigned int PSC[32];                         //              0x0000.0000     TIMx prescaler
  unsigned int ARR[32];                         //              0x0000.FFFF     TIMx auto-reload register
} BASIC_TIMER_BITBAND_TypeDef;
//==============================================================================================================================================================
//===========================================================       LEVEL 1      ===============================================================================
//==============================================================================================================================================================
/*
+) NOTE:
  -NVIC must enable
  -IRQ function must clear flag
*/
#define BASIC_TIMER_EnableInterrupt(TIMER)              ((BASIC_TIMER_TypeDef*)(TIMER))->DIER.REG |= BIT0
#define BASIC_TIMER_DisableInterrupt(TIMER)             ((BASIC_TIMER_TypeDef*)(TIMER))->DIER.REG &= ~BIT0
//==============================================================================================================================================================
#define BASIC_TIMER_EnableDMA(TIMER)                    ((BASIC_TIMER_TypeDef*)(TIMER))->DIER.REG |= BIT8
#define BASIC_TIMER_DisableDMA(TIMER)                   ((BASIC_TIMER_TypeDef*)(TIMER))->DIER.REG &= ~BIT8
//==============================================================================================================================================================
/*
+) Timer overflow:
    ((Prescale + 1) / F_TIMER) * (ReloadValue + 1) (ms)    //F_TIMER: KHz
*/
#define BASIC_TIMER_Init(TIMER, Prescale, ReloadValue)  BASE_TIMER_Init(TIMER, Prescale, ReloadValue)
//==============================================================================================================================================================

#endif