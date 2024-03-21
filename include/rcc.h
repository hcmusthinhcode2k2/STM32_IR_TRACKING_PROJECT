#ifndef _RCC_H_
#define _RCC_H_

#include <define.h>
//                                      |       //Address       Default         Description
typedef struct
{
  BUNION(CR, unsigned long,                      //                              Clock control register
    HSION                               , 1,    //0             1               longernal high-speed clock enable
    const HSI_RDY                       , 1,    //1             1               longernal high-speed clock ready flag
    _reserved                           , 1,
    HSI_TRIM                            , 5,    //3:7           16              longernal high-speed clock trimming
    const HSI_CAL                       , 8,    //8:15          -               longernal high-speed clock calibration
    HSE_ON                              , 1,    //16            0               HSE clock enable
    const HSE_RDY                       , 1,    //17            0               External high-speed clock ready flag
    HSE_PYB                             , 1,    //18            0               External high-speed clock bypass
    CSS_ON                              , 1,    //19            0               Clock security system enable
    _reserved1                          , 4,
    PLL_ON                              , 1,    //24            0               PLL enable
    const PLL_RDY                       , 1,    //25            0               PLL clock ready flag
    PLL2_ON                             , 1,    //26            0               PLL enable
    const PLL2_RDY                      , 1,    //27            0               PLL clock ready flag
    PLL3_ON                             , 1,    //28            0               PLL enable
    const PLL3_RDY                      , 1,    //29            0               PLL clock ready flag
    _reserved2                          , 2);
  BUNION(CFGR, unsigned long,                    //                              Clock configuration register
    SW                                  , 2,    //0-1           0               System clock switch
    const SWS                           , 2,    //2-3           0               System clock switch status
    AHB_PRE                             , 4,    //4:7           0               AHB prescaler
    APB1_PRE                            , 3,    //8:10          0               APB low-speed prescaler (APB1)
    APB2_PRE                            , 3,    //11:13         0               APB high-speed prescaler (APB2)
    ADC_PRE                             , 2,    //14-15         0               ADC prescaler
    PLL_SRC                             , 1,    //16            0               PLL entry clock source
    PLL_XTPRE                           , 1,    //17            0               HSE divider for PLL entry
    PLL_MUL                             , 4,    //18:21         0               PLL multiplication factor
    USB_PRE                             , 1,    //22            0               USB prescaler
    _reserved                           , 1,
    MCO                                 , 4,    //24:27         0               Microcontroller clock output
    _reserved1                          , 4);
  BUNION(CIR, unsigned long,                     //              0               Clock longerrupt register
    const LSI_RDYF                      , 1,    //0             0               LSI ready longerrupt flag
    const LSE_RDYF                      , 1,    //1             0               LSE ready longerrupt flag
    const HSI_RDYF                      , 1,    //2             0               HSI ready longerrupt flag
    const HSE_RDYF                      , 1,    //3             0               HSE ready longerrupt flag
    const PLL_RDYF                      , 1,    //4             0               PLL ready longerrupt flag
    const PLL2_RDYF                     , 1,    //5             0
    const PLL3_RDYF                     , 1,    //6             0
    const CSSF                          , 1,    //7             0               Clock security system longerrupt flag
    LSI_RDY_IE                          , 1,    //8             0               LSI ready longerrupt enable
    LSE_RDY_IE                          , 1,    //9             0               LSE ready longerrupt enable
    HSI_RDY_IE                          , 1,    //10            0               HSI ready longerrupt enable
    HSE_RDY_IE                          , 1,    //11            0               HSE ready longerrupt enable
    PLL_RDY_IE                          , 1,    //12            0               PLL ready longerrupt enable
    PLL2_RDY_IE                         , 1,    //13            0               PLL2 ready longerrupt enable
    PLL3_RDY_IE                         , 1,    //14            0               PLL3 ready longerrupt enable
    _reserved                           , 1,
    LSI_RDYC                            , 1,    //16            0               LSI ready longerrupt clear
    LSE_RDYC                            , 1,    //17            0               LSE ready longerrupt clear
    HSI_RDYC                            , 1,    //18            0               HSI ready longerrupt clear
    HSE_RDYC                            , 1,    //19            0               HSE ready longerrupt clear
    PLL_RDYC                            , 1,    //20            0               PLL ready longerrupt clear
    PLL2_RDYC                           , 1,    //21            0               PLL2 ready longerrupt clear
    PLL3_RDYC                           , 1,    //22            0               PLL3 ready longerrupt clear
    CSSC                                , 1,    //23            0               Clock security system longerrupt clear
    _reserved1                          , 8);
  BUNION(APB2_RSTR, unsigned long,               //                              APB2 peripheral reset register
    AFIO                                , 1,    //0             0               Alternate function IO reset
    _reserved                           , 1,
    IOPA                                , 1,    //2             0               IO port A reset
    IOPB                                , 1,    //3             0               IO port B reset
    IOPC                                , 1,    //4             0               IO port C reset
    IOPD                                , 1,    //5             0               IO port D reset
    IOPE                                , 1,    //6             0               IO port E reset
    IOPF                                , 1,    //7             0               IO port F reset
    IOPG                                , 1,    //8             0               IO port G reset
    ADC1                                , 1,    //9             0               ADC 1 longerface reset
    ADC2                                , 1,    //10            0               ADC 2 longerface reset
    TIM1                                , 1,    //11            0               TIM1 timer reset
    SPI1                                , 1,    //12            0               SPI1 reset
    TIM8                                , 1,    //13            0               TIM8 timer reset
    UART1                               , 1,    //14            0               UART1 reset
    ADC3                                , 1,    //15            0               ADC3 longerface reset
    _reserved1                          , 3,
    TIM9                                , 1,    //19            0               TIM9 timer reset
    TIM10                               , 1,    //20            0               TIM10 timer reset
    TIM11                               , 1,    //21            0               TIM11 timer reset
    _reserved2                          , 10);
  BUNION(APB1_RSTR, unsigned long,               //                              APB1 peripheral reset register
    TIM2                                , 1,    //0             0               TIM2 timer reset
    TIM3                                , 1,    //1             0               TIM3 timer reset
    TIM4                                , 1,    //2             0               TIM4 timer reset
    TIM5                                , 1,    //3             0               TIM5 timer reset
    TIM6                                , 1,    //4             0               TIM6 timer reset
    TIM7                                , 1,    //5             0               TIM7 timer reset
    TIM12                               , 1,    //6             0               TIM12 timer reset
    TIM13                               , 1,    //7             0               TIM13 timer reset
    TIM14                               , 1,    //8             0               TIM14 timer reset
    _reserved                           , 2,
    WWDG                                , 1,    //11            0               Window watchdog reset
    _reserved1                          , 2,
    SPI2                                , 1,    //14            0               SPI2 reset
    SPI3                                , 1,    //15            0               SPI3 reset
    _reserved2                          , 1,
    UART2                               , 1,    //17            0               UART2 reset
    UART3                               , 1,    //18            0               UART3 reset
    UART4                               , 1,    //19            0               UART4 reset
    UART5                               , 1,    //20            0               UART5 reset
    I2C1                                , 1,    //21            0               I2C1 reset
    I2C2                                , 1,    //22            0               I2C2 reset
    USB                                 , 1,    //23            0               USB reset
    _reserved3                          , 1,
    CAN                                 , 1,    //25            0               CAN reset
    _reserved4                          , 1,
    BKP                                 , 1,    //27            0               Backup longerface reset
    PWR                                 , 1,    //28            0               Power longerface reset
    DAC                                 , 1,    //29            0               DAC longerface reset
    _reserved5                          , 2);
  BUNION(AHB_ENR, unsigned long,                 //                              AHB peripheral clock enable register
    DMA1                                , 1,    //0             0               DMA1 clock enable
    DMA2                                , 1,    //1             0               DMA2 clock enable
    SRAM                                , 1,    //2             1               SRAM longerface clock enable
    _reserved                           , 1,
    FLITF                               , 1,    //4             1               FLITF clock enable
    _reserved1                          , 1,
    CRC                                 , 1,    //6             0               CRC clock enable
    _reserved2                          , 1,
    FSMC                                , 1,    //8             0               FSMC clock enable
    _reserved3                          , 1,
    SDIO                                , 1,    //10            0               SDIO clock enable
    _reserved4                          , 21);
  BUNION(APB2_ENR, unsigned long,                //                              APB2 peripheral clock enable register
    AFIO                                , 1,    //0             0               Alternate function IO clock enable
    _reserved                           , 1,
    IOPA                                , 1,    //2             0               IO port A clock enable
    IOPB                                , 1,    //3             0               IO port B clock enable
    IOPC                                , 1,    //4             0               IO port C clock enable
    IOPD                                , 1,    //5             0               IO port D clock enable
    IOPE                                , 1,    //6             0               IO port E clock enable
    IOPF                                , 1,    //7             0               IO port F clock enable
    IOPG                                , 1,    //8             0               IO port G clock enable
    ADC1                                , 1,    //9             0               ADC 1 longerface clock enable
    ADC2                                , 1,    //10            0               ADC 2 longerface clock enable
    TIM1                                , 1,    //11            0               TIM1 timer clock enable
    SPI1                                , 1,    //12            0               SPI1 clock enable
    TIM8                                , 1,    //13            0               TIM8 Timer clock enable
    UART1                               , 1,    //14            0               UART1 clock enable
    ADC3                                , 1,    //15            0               ADC3 longerface clock enable
    _reserved1                          , 3,
    TIM9                                , 1,    //19            0               TIM9 timer clock enable
    TIM10                               , 1,    //20            0               TIM10 timer clock enable
    TIM11                               , 1,    //21            0               TIM11 timer clock enable
    _reserved2                          , 10);
  BUNION(APB1_ENR, unsigned long,                //                              APB1 peripheral clock enable register
    TIM2                                , 1,    //0             0               TIM2 timer clock enable
    TIM3                                , 1,    //1             0               TIM3 timer clock enable
    TIM4                                , 1,    //2             0               TIM4 timer clock enable
    TIM5                                , 1,    //3             0               TIM5 timer clock enable
    TIM6                                , 1,    //4             0               TIM6 timer clock enable
    TIM7                                , 1,    //5             0               TIM7 timer clock enable
    TIM12                               , 1,    //6             0               TIM12 timer clock enable
    TIM13                               , 1,    //7             0               TIM13 timer clock enable
    TIM14                               , 1,    //8             0               TIM14 timer clock enable
    _reserved                           , 2,
    WWDG                                , 1,    //11            0               Window watchdog clock enable
    _reserved1                          , 2,
    SPI2                                , 1,    //14            0               SPI 2 clock enable
    SPI3                                , 1,    //15            0               SPI 3 clock enable
    _reserved2                          , 1,
    UART2                               , 1,    //17            0               UART2 clock enable
    UART3                               , 1,    //18            0               UART3 clock enable
    UART4                               , 1,    //19            0               UART4 clock enable
    UART5                               , 1,    //20            0               UART5 clock enable
    I2C1                                , 1,    //21            0               I2C1 clock enable
    I2C2                                , 1,    //22            0               I2C2 clock enable
    USB                                 , 1,    //23            0               USB clock enable
    _reserved3                          , 1,
    CAN                                 , 1,    //25            0               CAN clock enable
    _reserved4                          , 1,
    BKP                                 , 1,    //27            0               Backup longerface clock enable
    PWR                                 , 1,    //28            0               Power longerface clock enable
    DAC                                 , 1,    //29            0               DAC longerface clock enable
    _reserved5                          , 2);
  BUNION(BDCR, unsigned long,                    //                              Backup domain control register
    LSE_ON                              , 1,    //0             0               External low-speed oscillator enable
    const LSE_RDY                       , 1,    //1             0               External low-speed oscillator ready
    LSE_BYP                             , 1,    //2             0               External low-speed oscillator bypass
    _reserved                           , 5,
    RTC_SEL                             , 2,    //8-9           0               RTC clock source selection
    _reserved1                          , 5,
    RTC_EN                              , 1,    //15            0               RTC clock enable
    BD_RST                              , 1,    //16            0               Backup domain software reset
    _reserved2                          , 15);
  BUNION(CSR, unsigned long,                     //                              Control/status register
    LSI_ON                              , 1,    //0             0               longernal low-speed oscillator enable
    const LSI_RDY                       , 1,    //1             0               longernal low-speed oscillator ready
    _reserved                           , 22,
    RMVF                                , 1,    //24            0               Remove reset flag
    _reserved1                          , 1,
    PIN_RSTF                            , 1,    //26            1               1: PIN reset flag
    POR_RSTF                            , 1,    //27            1               1: POR/PDR reset flag
    SFT_RSTF                            , 1,    //28            0               Software reset flag
    IWDG_RSTF                           , 1,    //29            0               Independent watchdog reset flag
    WWDG_RSTF                           , 1,    //30            0               Window watchdog reset flag
    LPW_RSTF                            , 1);   //31            0               Low-power reset flag
  BUNION(AHB_STR, unsigned long,                 //                              AHB peripheral clock reset register
    _reserved                           , 12,
    OTGFS_RST                           , 1,    //12            0               USB OTG FS reset
    _reserved1                          , 1,
    ETHMAC_RST                          , 1,    //14            0               Ethernet MAC reset
    _reserved2                          , 17);
  BUNION(CFGR2, unsigned long,                   //                              Clock configuration register 2
    PRE_DIV1                            , 4,    //0:3           0               PREDIV1 division factor
    PRE_DIV2                            , 4,    //4:7           0               PREDIV2 division factor
    PLL2_MUL                            , 4,    //8:11          0               PLL2 Multiplication Factor
    PLL3_MUL                            , 4,    //12:15         0               PLL3 Multiplication Factor
    PRE_DIV1_SRC                        , 1,    //16            0               PREDIV1 entry clock source
    I2S2_SRC                            , 1,    //17            0               I2S2 clock source
    I2S3_SRC                            , 1,    //18            0               I2S3 clock source
    _reserved                           , 13);
} RCC_TypeDef;

typedef struct
{
  RSTRUCT(CR, unsigned long,                     //                              Clock control register
    HSION                                  ,    //0             1               longernal high-speed clock enable
    const HSI_RDY                          ,    //1             1               longernal high-speed clock ready flag
    _reserved                              ,
    HSI_TRIM                            [5],    //3:7           16              longernal high-speed clock trimming
    const HSI_CAL                       [8],    //8:15          -               longernal high-speed clock calibration
    HSE_ON                                 ,    //16            0               HSE clock enable
    const HSE_RDY                          ,    //17            0               External high-speed clock ready flag
    HSE_PYB                                ,    //18            0               External high-speed clock bypass
    CSS_ON                                 ,    //19            0               Clock security system enable
    _reserved1                          [4],
    PLL_ON                                 ,    //24            0               PLL enable
    const PLL_RDY                          ,    //25            0               PLL clock ready flag
    PLL2_ON                                ,    //26            0               PLL enable
    const PLL2_RDY                         ,    //27            0               PLL clock ready flag
    PLL3_ON                                ,    //28            0               PLL enable
    const PLL3_RDY                         ,    //29            0               PLL clock ready flag
    _reserved2                          [2]);
  RSTRUCT(CFGR, unsigned long,                   //                              Clock configuration register
    SW                                  [2],    //0-1           0               System clock switch
    const SWS                           [2],    //2-3           0               System clock switch status
    AHB_PRE                             [4],    //4:7           0               AHB prescaler
    APB1_PRE                            [3],    //8:10          0               APB low-speed prescaler (APB1)
    APB2_PRE                            [3],    //11:13         0               APB high-speed prescaler (APB2)
    ADC_PRE                             [2],    //14-15         0               ADC prescaler
    PLL_SRC                                ,    //16            0               PLL entry clock source
    PLL_XTPRE                              ,    //17            0               HSE divider for PLL entry
    PLL_MUL                             [4],    //18:21         0               PLL multiplication factor
    USB_PRE                                ,    //22            0               USB prescaler
    _reserved                              ,
    MCO                                 [4],    //24:27         0               Microcontroller clock output
    _reserved1                          [4]);
  RSTRUCT(CIR, unsigned long,                    //              0               Clock longerrupt register
    const LSI_RDYF                         ,    //0             0               LSI ready longerrupt flag
    const LSE_RDYF                         ,    //1             0               LSE ready longerrupt flag
    const HSI_RDYF                         ,    //2             0               HSI ready longerrupt flag
    const HSE_RDYF                         ,    //3             0               HSE ready longerrupt flag
    const PLL_RDYF                         ,    //4             0               PLL ready longerrupt flag
    const PLL2_RDYF                        ,    //5             0
    const PLL3_RDYF                        ,    //6             0
    const CSSF                             ,    //7             0               Clock security system longerrupt flag
    LSI_RDY_IE                             ,    //8             0               LSI ready longerrupt enable
    LSE_RDY_IE                             ,    //9             0               LSE ready longerrupt enable
    HSI_RDY_IE                             ,    //10            0               HSI ready longerrupt enable
    HSE_RDY_IE                             ,    //11            0               HSE ready longerrupt enable
    PLL_RDY_IE                             ,    //12            0               PLL ready longerrupt enable
    PLL2_RDY_IE                            ,    //13            0               PLL2 ready longerrupt enable
    PLL3_RDY_IE                            ,    //14            0               PLL3 ready longerrupt enable
    _reserved                              ,
    LSI_RDYC                               ,    //16            0               LSI ready longerrupt clear
    LSE_RDYC                               ,    //17            0               LSE ready longerrupt clear
    HSI_RDYC                               ,    //18            0               HSI ready longerrupt clear
    HSE_RDYC                               ,    //19            0               HSE ready longerrupt clear
    PLL_RDYC                               ,    //20            0               PLL ready longerrupt clear
    PLL2_RDYC                              ,    //21            0               PLL2 ready longerrupt clear
    PLL3_RDYC                              ,    //22            0               PLL3 ready longerrupt clear
    CSSC                                   ,    //23            0               Clock security system longerrupt clear
    _reserved1                          [8]);
  RSTRUCT(APB2_RSTR, unsigned long,              //                              APB2 peripheral reset register
    AFIO                                   ,    //0             0               Alternate function IO reset
    _reserved                              ,
    IOPA                                   ,    //2             0               IO port A reset
    IOPB                                   ,    //3             0               IO port B reset
    IOPC                                   ,    //4             0               IO port C reset
    IOPD                                   ,    //5             0               IO port D reset
    IOPE                                   ,    //6             0               IO port E reset
    IOPF                                   ,    //7             0               IO port F reset
    IOPG                                   ,    //8             0               IO port G reset
    ADC1                                   ,    //9             0               ADC 1 longerface reset
    ADC2                                   ,    //10            0               ADC 2 longerface reset
    TIM1                                   ,    //11            0               TIM1 timer reset
    SPI1                                   ,    //12            0               SPI1 reset
    TIM8                                   ,    //13            0               TIM8 timer reset
    UART1                                  ,    //14            0               UART1 reset
    ADC3                                   ,    //15            0               ADC3 longerface reset
    _reserved1                          [3],
    TIM9                                   ,    //19            0               TIM9 timer reset
    TIM10                                  ,    //20            0               TIM10 timer reset
    TIM11                                  ,    //21            0               TIM11 timer reset
    _reserved2                          [10]);
  RSTRUCT(APB1_RSTR, unsigned long,              //                              APB1 peripheral reset register
    TIM2                                   ,    //0             0               TIM2 timer reset
    TIM3                                   ,    //1             0               TIM3 timer reset
    TIM4                                   ,    //2             0               TIM4 timer reset
    TIM5                                   ,    //3             0               TIM5 timer reset
    TIM6                                   ,    //4             0               TIM6 timer reset
    TIM7                                   ,    //5             0               TIM7 timer reset
    TIM12                                  ,    //6             0               TIM12 timer reset
    TIM13                                  ,    //7             0               TIM13 timer reset
    TIM14                                  ,    //8             0               TIM14 timer reset
    _reserved                           [2],
    WWDG                                   ,    //11            0               Window watchdog reset
    _reserved1                          [2],
    SPI2                                   ,    //14            0               SPI2 reset
    SPI3                                   ,    //15            0               SPI3 reset
    _reserved2                             ,
    UART2                                  ,    //17            0               UART2 reset
    UART3                                  ,    //18            0               UART3 reset
    UART4                                  ,    //19            0               UART4 reset
    UART5                                  ,    //20            0               UART5 reset
    I2C1                                   ,    //21            0               I2C1 reset
    I2C2                                   ,    //22            0               I2C2 reset
    USB                                    ,    //23            0               USB reset
    _reserved3                             ,
    CAN                                    ,    //25            0               CAN reset
    _reserved4                             ,
    BKP                                    ,    //27            0               Backup longerface reset
    PWR                                    ,    //28            0               Power longerface reset
    DAC                                    ,    //29            0               DAC longerface reset
    _reserved5                          [2]);
  RSTRUCT(AHB_ENR, unsigned long,                //                              AHB peripheral clock enable register
    DMA1                                   ,    //0             0               DMA1 clock enable
    DMA2                                   ,    //1             0               DMA2 clock enable
    SRAM                                   ,    //2             1               SRAM longerface clock enable
    _reserved                              ,
    FLITF                                  ,    //4             1               FLITF clock enable
    _reserved1                             ,
    CRC                                    ,    //6             0               CRC clock enable
    _reserved2                             ,
    FSMC                                   ,    //8             0               FSMC clock enable
    _reserved3                             ,
    SDIO                                   ,    //10            0               SDIO clock enable
    _reserved4                          [21]);
  RSTRUCT(APB2_ENR, unsigned long,               //                              APB2 peripheral clock enable register
    AFIO                                   ,    //0             0               Alternate function IO clock enable
    _reserved                              ,
    IOPA                                   ,    //2             0               IO port A clock enable
    IOPB                                   ,    //3             0               IO port B clock enable
    IOPC                                   ,    //4             0               IO port C clock enable
    IOPD                                   ,    //5             0               IO port D clock enable
    IOPE                                   ,    //6             0               IO port E clock enable
    IOPF                                   ,    //7             0               IO port F clock enable
    IOPG                                   ,    //8             0               IO port G clock enable
    ADC1                                   ,    //9             0               ADC 1 longerface clock enable
    ADC2                                   ,    //10            0               ADC 2 longerface clock enable
    TIM1                                   ,    //11            0               TIM1 timer clock enable
    SPI1                                   ,    //12            0               SPI1 clock enable
    TIM8                                   ,    //13            0               TIM8 Timer clock enable
    UART1                                  ,    //14            0               UART1 clock enable
    ADC3                                   ,    //15            0               ADC3 longerface clock enable
    _reserved1                          [3],
    TIM9                                   ,    //19            0               TIM9 timer clock enable
    TIM10                                  ,    //20            0               TIM10 timer clock enable
    TIM11                                  ,    //21            0               TIM11 timer clock enable
    _reserved2                          [10]);
  RSTRUCT(APB1_ENR, unsigned long,               //                              APB1 peripheral clock enable register
    TIM2                                   ,    //0             0               TIM2 timer clock enable
    TIM3                                   ,    //1             0               TIM3 timer clock enable
    TIM4                                   ,    //2             0               TIM4 timer clock enable
    TIM5                                   ,    //3             0               TIM5 timer clock enable
    TIM6                                   ,    //4             0               TIM6 timer clock enable
    TIM7                                   ,    //5             0               TIM7 timer clock enable
    TIM12                                  ,    //6             0               TIM12 timer clock enable
    TIM13                                  ,    //7             0               TIM13 timer clock enable
    TIM14                                  ,    //8             0               TIM14 timer clock enable
    _reserved                           [2],
    WWDG                                   ,    //11            0               Window watchdog clock enable
    _reserved1                          [2],
    SPI2                                   ,    //14            0               SPI 2 clock enable
    SPI3                                   ,    //15            0               SPI 3 clock enable
    _reserved2                             ,
    UART2                                  ,    //17            0               UART2 clock enable
    UART3                                  ,    //18            0               UART3 clock enable
    UART4                                  ,    //19            0               UART4 clock enable
    UART5                                  ,    //20            0               UART5 clock enable
    I2C1                                   ,    //21            0               I2C1 clock enable
    I2C2                                   ,    //22            0               I2C2 clock enable
    USB                                    ,    //23            0               USB clock enable
    _reserved3                             ,
    CAN                                    ,    //25            0               CAN clock enable
    _reserved4                             ,
    BKP                                    ,    //27            0               Backup longerface clock enable
    PWR                                    ,    //28            0               Power longerface clock enable
    DAC                                    ,    //29            0               DAC longerface clock enable
    _reserved5                          [2]);
  RSTRUCT(BDCR, unsigned long,                   //                              Backup domain control register
    LSE_ON                                 ,    //0             0               External low-speed oscillator enable
    const LSE_RDY                          ,    //1             0               External low-speed oscillator ready
    LSE_BYP                                ,    //2             0               External low-speed oscillator bypass
    _reserved                           [5],
    RTC_SEL                             [2],    //8-9           0               RTC clock source selection
    _reserved1                          [5],
    RTC_EN                                 ,    //15            0               RTC clock enable
    BD_RST                                 ,    //16            0               Backup domain software reset
    _reserved2                          [15]);
  RSTRUCT(CSR, unsigned long,                    //                              Control/status register
    LSI_ON                                 ,    //0             0               longernal low-speed oscillator enable
    const LSI_RDY                          ,    //1             0               longernal low-speed oscillator ready
    _reserved                           [22],
    RMVF                                   ,    //24            0               Remove reset flag
    _reserved1                             ,
    PIN_RSTF                               ,    //26            1               1: PIN reset flag
    POR_RSTF                               ,    //27            1               1: POR/PDR reset flag
    SFT_RSTF                               ,    //28            0               Software reset flag
    IWDG_RSTF                              ,    //29            0               Independent watchdog reset flag
    WWDG_RSTF                              ,    //30            0               Window watchdog reset flag
    LPW_RSTF                               );   //31            0               Low-power reset flag
  RSTRUCT(AHB_STR, unsigned long,                //                              AHB peripheral clock reset register
    _reserved                           [12],
    OTGFS_RST                              ,    //12            0               USB OTG FS reset
    _reserved1                             ,
    ETHMAC_RST                             ,    //14            0               Ethernet MAC reset
    _reserved2                          [17]);
  RSTRUCT(CFGR2, unsigned long,                  //                              Clock configuration register 2
    PRE_DIV1                            [4],    //0:3           0               PREDIV1 division factor
    PRE_DIV2                            [4],    //4:7           0               PREDIV2 division factor
    PLL2_MUL                            [4],    //8:11          0               PLL2 Multiplication Factor
    PLL3_MUL                            [4],    //12:15         0               PLL3 Multiplication Factor
    PRE_DIV1_SRC                           ,    //16            0               PREDIV1 entry clock source
    I2S2_SRC                               ,    //17            0               I2S2 clock source
    I2S3_SRC                               ,    //18            0               I2S3 clock source
    _reserved                           [13]);
} RCC_BITBAND_TypeDef;
//==============================================================================================================================================================
//===========================================================       LEVEL 1      ===============================================================================
//==============================================================================================================================================================
typedef struct
{
  enum
  {
    RCC_SOURCE_HSI              = 0,
    RCC_SOURCE_HSE              = 1,
    RCC_SOURCE_PLL              = 2,
  } Source;                                     //0-1           0
  union
  {
    unsigned long REG;
    struct
    {
      unsigned long _reserved            : 16;
      enum
      {
        PLL_SOURCE_HSI_DIV_2    = 0,
        PLL_SOURCE_HSE          = 1,
        PLL_SOURCE_HSE_DIV_2    = 3,
      } Source                          : 2;    //16-17         0
      unsigned long Multiple             : 4;    //18:21         (16 - 2)        F_SYS = F_PLL * (Multiple + 2)
      unsigned long _reserved1           : 10;
    } BITS;
  } PLL;
  union
  {
    unsigned long REG;
    struct
    {
      unsigned long _reserved            : 4;
      enum
      {
        AHB_PRESCALE_1          = 0 ,
        AHB_PRESCALE_2          = 8 ,
        AHB_PRESCALE_4          = 9 ,
        AHB_PRESCALE_8          = 10,
        AHB_PRESCALE_16         = 11,
        AHB_PRESCALE_64         = 12,
        AHB_PRESCALE_128        = 13,
        AHB_PRESCALE_256        = 14,
        AHB_PRESCALE_512        = 15,
      } AHB                             : 4;    //4:7           0               max 72MHz
      enum
      {
        APB_PRESCALE_1          = 0,
        APB_PRESCALE_2          = 4,
        APB_PRESCALE_4          = 5,
        APB_PRESCALE_8          = 6,
        APB_PRESCALE_16         = 7,
      } APB1                            : 3,    //8:10          4               max 36MHz
        APB2                            : 3;    //11:13         0               max 72MHz
      enum
      {
        ADC_PRESCALE_2          = 0,
        ADC_PRESCALE_4          = 1,
        ADC_PRESCALE_6          = 2,
        ADC_PRESCALE_8          = 3,
      } ADC                             : 2;    //14-15         0               max 14MHz
      unsigned long _reserved1           : 6;
      unsigned long USB_NotDiv           : 1;    //22            1               0 : USB = F_SYS / 1.5
      unsigned long _reserved2           : 9;
    } BITS;
  } Prescale;
} RCCInit_TypeDef;
/*
+) EXAMPLE:
//RCC: Source = HSI (8MHz); PLL: Source = HSI/2 (4MHz) & Multiple = 16; AHB = 8MHz (max 72Mhz), APB1 = 4MHz (max 36MHz), APB2 = 8MHz (max 72Mhz), ADC = 4MHz (max 14Mhz), USB = must 48MHz
RCCInit_TypeDef RCCInit = (RCCInit_TypeDef){
  .Source = RCC_SOURCE_HSI,
  .PLL = {.BITS = { .Source = PLL_SOURCE_HSI_DIV_2, .Multiple = 14, }},         //Real multiple += 2
  .Prescale = {.BITS = { .AHB = AHB_PRESCALE_1, .APB1 = APB_PRESCALE_2, .APB2 = APB_PRESCALE_1, .ADC = ADC_PRESCALE_2, .USB_NotDiv = 1, }},     
};
RCC_Init(&RCC, &RCCInit);
+) NOTE:
FSYS > 24MHz, "FLASH.ACR.BITS.LATENCY = 1;" (wait 1 cycle to access flash)
FSYS > 48MHz, "FLASH.ACR.BITS.LATENCY = 2;" (wait 2 cycle to access flash)
*/
void RCC_Init(volatile RCC_TypeDef* RCC, const RCCInit_TypeDef* RCCInit);
//==============================================================================================================================================================

#endif