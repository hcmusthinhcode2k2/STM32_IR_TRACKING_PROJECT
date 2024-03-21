#ifndef _ADVANCED_TIMER_H_
#define _ADVANCED_TIMER_H_

#include <base_timer.h>
#include <common.h>
#include <define.h>
//                                      |       //Address       Default         Description
typedef struct
{
  BUNION(CR1, unsigned int,                     //              0x0000'0000     TIM1 and TIM8 control register 1
    CEN                                 , 1,    //0             0               Counter enable
    UDIS                                , 1,    //1             0               Update disable
    URS                                 , 1,    //2             0               Update request source
    OPM                                 , 1,    //3             0               One pulse mode
    DIR                                 , 1,    //4             0               Direction
    CMS                                 , 2,    //5-6           0               Center-aligned mode selection
    APRE                                , 1,    //7             0               Auto-reload preload enable
    CKD                                 , 2,    //8-9           0               Clock division
    _reserved                           , 22);
  BUNION(CR2, unsigned int,                     //              0x0000.0000     TIM1 and TIM8 control register 2
    CCPC                                , 1,    //0             0               Capture/compare preloaded control
    _reserved                           , 1,
    CCUS                                , 1,    //2             0               Capture/compare control update selection
    CCDS                                , 1,    //3             0               Capture/compare DMA selection
    MMS                                 , 3,    //4:6           0               Master mode selection
    TI1S                                , 1,    //7             0               TI1 selection
    OIS1                                , 1,    //8             0               Output Idle state 1 (OC1 output)
    OIS1N                               , 1,    //9             0               Output Idle state 1 (OC1N output)
    OI2S                                , 1,    //10            0               Output Idle state 2 (OC2 output)
    OIS2N                               , 1,    //11            0               Output Idle state 2 (OC2N output)
    OIS3                                , 1,    //12            0               Output Idle state 3 (OC3 output)
    OIS3N                               , 1,    //13            0               Output Idle state 3 (OC3N output)
    OIS4                                , 1,    //14            0               Output Idle state 4 (OC4 output)
    _reserved1                          , 17);
  BUNION(SMCR, unsigned int,                    //              0x0000.0000     TIM1 and TIM8 slave mode control register
    SMS                                 , 3,    //0:2           0               Slave mode selection
    _reserved                           , 1,
    TS                                  , 3,    //4:6           0               Trigger selection
    MSM                                 , 1,    //7             0               Master/slave mode
    ETF                                 , 4,    //8:11          0               External trigger filter
    ETPS                                , 2,    //12-13         0               External trigger prescaler
    ECE                                 , 1,    //14            0               External clock enable
    ETP                                 , 1,    //15            0               External trigger polarity
    _reserved1                          , 16);
  BUNION(DIER, unsigned int,                    //              0x0000'0000     TIM1 and TIM8 DMA/interrupt enable register
    UIE                                 , 1,    //0             0               Update interrupt enable
    CC1IE                               , 1,    //1             0               Capture/Compare 1 interrupt enable
    CC2IE                               , 1,    //2             0               Capture/Compare 2 interrupt enable
    CC3IE                               , 1,    //3             0               Capture/Compare 3 interrupt enable
    CC4IE                               , 1,    //4             0               Capture/Compare 4 interrupt enable
    COMIE                               , 1,    //5             0               COM interrupt enable
    TIE                                 , 1,    //6             0               Trigger interrupt enable
    BIE                                 , 1,    //7             0               Break interrupt enable
    UDE                                 , 1,    //8             0               Update DMA request enable
    CC1DE                               , 1,    //9             0               Capture/Compare 1 DMA request enable
    CC2DE                               , 1,    //10            0               Capture/Compare 2 DMA request enable
    CC3DE                               , 1,    //11            0               Capture/Compare 3 DMA request enable
    CC4DE                               , 1,    //12            0               Capture/Compare 4 DMA request enable
    COMDE                               , 1,    //13            0               COM DMA request enable
    TDE                                 , 1,    //14            0               Trigger DMA request enable
    _reserved                           , 17);
  BUNION(SR, unsigned int,                      //              0x0000'0000     TIM1 and TIM8 status register
    UIF                                 , 1,    //0             0               Update interrupt flag
    CC1IF                               , 1,    //1             0               Capture/Compare 1 interrupt flag
    CC2IF                               , 1,    //2             0               Capture/Compare 2 interrupt flag
    CC3IF                               , 1,    //3             0               Capture/Compare 3 interrupt flag
    CC4IF                               , 1,    //4             0               Capture/Compare 4 interrupt flag
    COMIF                               , 1,    //5             0               COM interrupt flag
    TIF                                 , 1,    //6             0               Trigger interrupt flag
    BIF                                 , 1,    //7             0               Break interrupt flag
    _reserved                           , 1,
    CC1OF                               , 1,    //9             0               Capture/Compare 1 overcapture flag
    CC2OF                               , 1,    //10            0               Capture/Compare 2 overcapture flag
    CC3OF                               , 1,    //11            0               Capture/Compare 3 overcapture flag
    CC4OF                               , 1,    //12            0               Capture/Compare 4 overcapture flag
    _reserved1                          , 19);
  BUNION(EGR, unsigned int,                     //              0x0000.0000     TIM1 and TIM8 event generation register
    UG                                  , 1,    //0             0               Update generation
    CC1G                                , 1,    //1             0               Capture/Compare 1 generation
    CC2G                                , 1,    //2             0               Capture/Compare 2 generation
    CC3G                                , 1,    //3             0               Capture/Compare 3 generation
    CC4G                                , 1,    //4             0               Capture/Compare 4 generation
    COMG                                , 1,    //5             0               Capture/Compare control update generation
    TG                                  , 1,    //6             0               Trigger generation
    BG                                  , 1,    //7             0               Break generation
    _reserved                           , 24);
  union
  {
    union
    {
      unsigned int REGS[2];
      struct
      {
        BUNION(, unsigned char,
          CCS                           , 2,    //0-1           0               Capture/Compare 1 selection
          OCFE                          , 1,    //2             0               Output Compare 1 fast enable
          OCPE                          , 1,    //3             0               Output Compare 1 preload enable
          OCM                           , 3,    //4:6           0               Output Compare 1 mode
          OCCE                          , 1)    //7             0               Output Compare 1 clear enable
            CH1, CH2, _reserved[2],
            CH3, CH4, _reserved1[2];
      };
    } OUTPUT;
    union
    {
      unsigned int REGS[2];
      struct
      {
        BUNION(, unsigned char,
          CCS                           , 2,    //0-1           0               Capture/Compare 1 Selection
          ICPSC                         , 2,    //2-3           0               Input capture 1 prescaler
          ICF                           , 4)    //4:7           0               Input capture 1 filter
            CH1, CH2, _reserved[2],
            CH3, CH4, _reserved1[2];
      };
    } INPUT;
  } CCMR;
  BUNION(CCER, unsigned int,                    //              0x0000.0000     TIM1 and TIM8 capture/compare enable register
    CC1E                                , 1,    //0             0               Capture/Compare 1 output enable
    CC1P                                , 1,    //1             0               Capture/Compare 1 output polarity
    CC1NE                               , 1,    //2             0               Capture/Compare 1 complementary output enable
    CC1NP                               , 1,    //3             0               Capture/Compare 1 complementary output polarity
    CC2E                                , 1,    //4             0               Capture/Compare 2 output enable
    CC2P                                , 1,    //5             0               Capture/Compare 2 output polarity
    CC2NE                               , 1,    //6             0               Capture/Compare 2 complementary output enable
    CC2NP                               , 1,    //7             0               Capture/Compare 2 complementary output polarity
    CC3E                                , 1,    //8             0               Capture/Compare 3 output enable
    CC3P                                , 1,    //9             0               Capture/Compare 3 output polarity
    CC3NE                               , 1,    //10            0               Capture/Compare 3 complementary output enable
    CC3NP                               , 1,    //11            0               Capture/Compare 3 complementary output polarity
    CC4E                                , 1,    //12            0               Capture/Compare 4 output enable
    CC4P                                , 1,    //13            0               Capture/Compare 4 output polarity
    _reserved                           , 18);
  unsigned int CNT;                             //              0x0000.0000     TIM1 and TIM8 counter
  unsigned int PSC;                             //              0x0000.0000     TIM1 and TIM8 prescaler
  unsigned int ARR;                             //              0x0000.FFFF     TIM1 and TIM8 auto-reload register
  unsigned int RCR;                             //              0x0000.0000     TIM1 and TIM8 repetition counter register
  unsigned int CCR1;                            //              0x0000.0000     TIM1 and TIM8 capture/compare register
  unsigned int CCR2;                            //              0x0000.0000     TIM1 and TIM8 capture/compare register
  unsigned int CCR3;                            //              0x0000.0000     TIM1 and TIM8 capture/compare register
  unsigned int CCR4;                            //              0x0000.0000     TIM1 and TIM8 capture/compare register
  BUNION(BDTR, unsigned int,                    //              0x0000.0000     TIM1 and TIM8 break and dead-time register
    DT                                  , 8,    //0:7           0               Dead-time generator setup
    LOCK                                , 2,    //8-9           0               Lock configuration
    OSSI                                , 1,    //10            0               Off-state selection for Idle mode
    OSSR                                , 1,    //11            0               Off-state selection for Run mode
    BKE                                 , 1,    //12            0               Break enable
    BKP                                 , 1,    //13            0               Break polarity
    AOE                                 , 1,    //14            0               Automatic output enable
    MOE                                 , 1,    //15            0               Main output enable
    _reserved                           , 16);
  BUNION(DCR, unsigned int,                     //              0x0000.0000     TIM1 and TIM8 DMA control register
    DBA                                 , 5,    //0:4           0               DMA base address
    _reserved                           , 3,
    DBL                                 , 5,    //8:11          0               DMA burst length
    _reserved1                          , 19);
  unsigned int DMAR;                            //0x0000.0000                   TIM1 and TIM8 DMA address for full transfer
} ADVANCED_TIMER_TypeDef;

typedef struct
{
  RSTRUCT(CR1, unsigned int,                    //              0x0000'0000     TIM1 and TIM8 control register 1
    CEN                                    ,    //0             0               Counter enable
    UDIS                                   ,    //1             0               Update disable
    URS                                    ,    //2             0               Update request source
    OPM                                    ,    //3             0               One pulse mode
    DIR                                    ,    //4             0               Direction
    CMS                                 [2],    //5-6           0               Center-aligned mode selection
    APRE                                   ,    //7             0               Auto-reload preload enable
    CKD                                 [2],    //8-9           0               Clock division
    _reserved                           [22]);
  RSTRUCT(CR2, unsigned int,                     //              0x0000.0000     TIM1 and TIM8 control register 2
    CCPC                                   ,    //0             0               Capture/compare preloaded control
    _reserved                              ,
    CCUS                                   ,    //2             0               Capture/compare control update selection
    CCDS                                   ,    //3             0               Capture/compare DMA selection
    MMS                                 [3],    //4:6           0               Master mode selection
    TI1S                                   ,    //7             0               TI1 selection
    OIS1                                   ,    //8             0               Output Idle state 1 (OC1 output)
    OIS1N                                  ,    //9             0               Output Idle state 1 (OC1N output)
    OI2S                                   ,    //10            0               Output Idle state 2 (OC2 output)
    OIS2N                                  ,    //11            0               Output Idle state 2 (OC2N output)
    OIS3                                   ,    //12            0               Output Idle state 3 (OC3 output)
    OIS3N                                  ,    //13            0               Output Idle state 3 (OC3N output)
    OIS4                                   ,    //14            0               Output Idle state 4 (OC4 output)
    _reserved1                          [17]);
  RSTRUCT(SMCR, unsigned int,                    //              0x0000.0000     TIM1 and TIM8 slave mode control register
    SMS                                 [3],    //0:2           0               Slave mode selection
    _reserved                              ,
    TS                                  [3],    //4:6           0               Trigger selection
    MSM                                    ,    //7             0               Master/slave mode
    ETF                                 [4],    //8:11          0               External trigger filter
    ETPS                                [2],    //12-13         0               External trigger prescaler
    ECE                                    ,    //14            0               External clock enable
    ETP                                    ,    //15            0               External trigger polarity
    _reserved1                          [16]);
  RSTRUCT(DIER, unsigned int,                    //              0x0000'0000     TIM1 and TIM8 DMA/interrupt enable register
    UIE                                    ,    //0             0               Update interrupt enable
    CC1IE                                  ,    //1             0               Capture/Compare 1 interrupt enable
    CC2IE                                  ,    //2             0               Capture/Compare 2 interrupt enable
    CC3IE                                  ,    //3             0               Capture/Compare 3 interrupt enable
    CC4IE                                  ,    //4             0               Capture/Compare 4 interrupt enable
    COMIE                                  ,    //5             0               COM interrupt enable
    TIE                                    ,    //6             0               Trigger interrupt enable
    BIE                                    ,    //7             0               Break interrupt enable
    UDE                                    ,    //8             0               Update DMA request enable
    CC1DE                                  ,    //9             0               Capture/Compare 1 DMA request enable
    CC2DE                                  ,    //10            0               Capture/Compare 2 DMA request enable
    CC3DE                                  ,    //11            0               Capture/Compare 3 DMA request enable
    CC4DE                                  ,    //12            0               Capture/Compare 4 DMA request enable
    COMDE                                  ,    //13            0               COM DMA request enable
    TDE                                    ,    //14            0               Trigger DMA request enable
    _reserved                           [17]);
  RSTRUCT(SR, unsigned int,                      //              0x0000'0000     TIM1 and TIM8 status register
    UIF                                    ,    //0             0               Update interrupt flag
    CC1IF                                  ,    //1             0               Capture/Compare 1 interrupt flag
    CC2IF                                  ,    //2             0               Capture/Compare 2 interrupt flag
    CC3IF                                  ,    //3             0               Capture/Compare 3 interrupt flag
    CC4IF                                  ,    //4             0               Capture/Compare 4 interrupt flag
    COMIF                                  ,    //5             0               COM interrupt flag
    TIF                                    ,    //6             0               Trigger interrupt flag
    BIF                                    ,    //7             0               Break interrupt flag
    _reserved                              ,
    CC1OF                                  ,    //9             0               Capture/Compare 1 overcapture flag
    CC2OF                                  ,    //10            0               Capture/Compare 2 overcapture flag
    CC3OF                                  ,    //11            0               Capture/Compare 3 overcapture flag
    CC4OF                                  ,    //12            0               Capture/Compare 4 overcapture flag
    _reserved1                          [19]);
  RSTRUCT(EGR, unsigned int,                    //              0x0000.0000     TIM1 and TIM8 event generation register
    UG                                     ,    //0             0               Update generation
    CC1G                                   ,    //1             0               Capture/Compare 1 generation
    CC2G                                   ,    //2             0               Capture/Compare 2 generation
    CC3G                                   ,    //3             0               Capture/Compare 3 generation
    CC4G                                   ,    //4             0               Capture/Compare 4 generation
    COMG                                   ,    //5             0               Capture/Compare control update generation
    TG                                     ,    //6             0               Trigger generation
    BG                                     ,    //7             0               Break generation
    _reserved                           [24]);
  union
  {
    struct
    {
      RSTRUCT(, unsigned int,
        CCS                             [2],    //0-1           0               Capture/Compare 1 selection
        OCFE                               ,    //2             0               Output Compare 1 fast enable
        OCPE                               ,    //3             0               Output Compare 1 preload enable
        OCM                             [3],    //4:6           0               Output Compare 1 mode
        OCCE                               )    //7             0               Output Compare 1 clear enable
          CH1, CH2, _reserved[2],
          CH3, CH4, _reserved1[2];
    } OUTPUT;
    struct
    {
      RSTRUCT(, unsigned int,
        CCS                             [2],    //0-1           0               Capture/Compare 1 Selection
        ICPSC                           [2],    //2-3           0               Input capture 1 prescaler
        ICF                             [4])    //4:7           0               Input capture 1 filter
          CH1, CH2, _reserved[2],
          CH3, CH4, _reserved1[2];
    } INPUT;
  } CCMR;
  RSTRUCT(CCER, unsigned int,                    //              0x0000.0000     TIM1 and TIM8 capture/compare enable register
    CC1E                                   ,    //0             0               Capture/Compare 1 output enable
    CC1P                                   ,    //1             0               Capture/Compare 1 output polarity
    CC1NE                                  ,    //2             0               Capture/Compare 1 complementary output enable
    CC1NP                                  ,    //3             0               Capture/Compare 1 complementary output polarity
    CC2E                                   ,    //4             0               Capture/Compare 2 output enable
    CC2P                                   ,    //5             0               Capture/Compare 2 output polarity
    CC2NE                                  ,    //6             0               Capture/Compare 2 complementary output enable
    CC2NP                                  ,    //7             0               Capture/Compare 2 complementary output polarity
    CC3E                                   ,    //8             0               Capture/Compare 3 output enable
    CC3P                                   ,    //9             0               Capture/Compare 3 output polarity
    CC3NE                                  ,    //10            0               Capture/Compare 3 complementary output enable
    CC3NP                                  ,    //11            0               Capture/Compare 3 complementary output polarity
    CC4E                                   ,    //12            0               Capture/Compare 4 output enable
    CC4P                                   ,    //13            0               Capture/Compare 4 output polarity
    _reserved                           [18]);
  unsigned int CNT[32];                         //              0x0000.0000     TIM1 and TIM8 counter
  unsigned int PSC[32];                         //              0x0000.0000     TIM1 and TIM8 prescaler
  unsigned int ARR[32];                         //              0x0000.FFFF     TIM1 and TIM8 auto-reload register
  unsigned int RCR[32];                         //              0x0000.0000     TIM1 and TIM8 repetition counter register
  unsigned int CCR1[32];                        //              0x0000.0000     TIM1 and TIM8 capture/compare register
  unsigned int CCR2[32];                        //              0x0000.0000     TIM1 and TIM8 capture/compare register
  unsigned int CCR3[32];                        //              0x0000.0000     TIM1 and TIM8 capture/compare register
  unsigned int CCR4[32];                        //              0x0000.0000     TIM1 and TIM8 capture/compare register
  RSTRUCT(BDTR, unsigned int,                    //              0x0000.0000     TIM1 and TIM8 break and dead-time register
    DT                                  [8],    //0:7           0               Dead-time generator setup
    LOCK                                [2],    //8-9           0               Lock configuration
    OSSI                                   ,    //10            0               Off-state selection for Idle mode
    OSSR                                   ,    //11            0               Off-state selection for Run mode
    BKE                                    ,    //12            0               Break enable
    BKP                                    ,    //13            0               Break polarity
    AOE                                    ,    //14            0               Automatic output enable
    MOE                                    ,    //15            0               Main output enable
    _reserved                           [16]);
  RSTRUCT(DCR, unsigned int,                     //              0x0000.0000     TIM1 and TIM8 DMA control register
    DBA                                 [5],    //0:4           0               DMA base address
    _reserved                           [3],
    DBL                                 [5],    //8:11          0               DMA burst length
    _reserved1                          [19]);
  unsigned int DMAR;                            //0x0000.0000                   TIM1 and TIM8 DMA address for full transfer
} ADVANCED_TIMER_BITBAND_TypeDef;
//==============================================================================================================================================================
//===========================================================       LEVEL 1      ===============================================================================
//==============================================================================================================================================================
/*
+) NOTE:
  -NVIC must enable
  -IRQ function must clear flag
*/
#define ADVANCED_TIMER_EnableInterrupt(TIMER)                           ((ADVANCED_TIMER_TypeDef*)(TIMER))->DIER.REG |= BIT0
#define ADVANCED_TIMER_DisableInterrupt(TIMER)                          ((ADVANCED_TIMER_TypeDef*)(TIMER))->DIER.REG &= ~BIT0
//==============================================================================================================================================================
#define ADVANCED_TIMER_EnableDMA(TIMER)                                 ((ADVANCED_TIMER_TypeDef*)(TIMER))->DIER.REG |= BIT8
#define ADVANCED_TIMER_DisableDMA(TIMER)                                ((ADVANCED_TIMER_TypeDef*)(TIMER))->DIER.REG &= ~BIT8
//==============================================================================================================================================================
/*
+) Timer overflow:
    ((Prescale + 1) / F_TIMER) * (ReloadValue + 1) (ms) //F_TIMER: KHz
*/
#define ADVANCED_TIMER_Init(TIMER, Prescale, ReloadValue)               BASE_TIMER_Init(TIMER, Prescale, ReloadValue)
//-----------------------------------------------------------       LEVEL 1      -------------------------------------------------------------------------------
/*
+) NOTE:
  -GPIO as OUTPUT_AF_PUSHPULL
  -AFIO to remap channel pin
  -Except basic timer
  -if (Channel & BIT6) -> Channel
  -if (Channel & BIT7) -> ChannelN
*/
#define ADVANCED_TIMER_GeneratePWM(TIMER, Channel, Duty, IDLE_IsHigh)   BASE_TIMER_GeneratePWM(TIMER, Channel, Duty, IDLE_IsHigh)

#endif