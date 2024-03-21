#ifndef _AFIO_H_
#define _AFIO_H_

#include <common.h>
#include <define.h>
//                                      |       //Address       Default         Description
typedef struct
{                                       
  BUNION(EVCR, unsigned int,                    //              0x0000'0000     Event control register
    PIN                                 , 4,    //0:3           0               Pin selection
    PORT                                , 3,    //4:6           0               Port selection
    EVOE                                , 1,    //7             0               Event output enable
    _reserved                           , 24);
  BUNION(MAPR, unsigned int,                    //              0x0000'0000     AF remap and debug I/O configuration register
    SPI1                                , 1,    //0             0               SPI1 remapping:         NSS     SCK     MISO    MOSI
                                                //                                                 0    PA4     PA5     PA6     PA7
                                                //                                                 1    PA15    PB3     PB4     PB5
    I2C1                                , 1,    //1             0               I2C1 remapping:         SCL     SDA
                                                //                                                 0    PB6     PB7
                                                //                                                 1    PB8     PB9
    USART1                              , 1,    //2             0               USART1 remapping:       TX      RX
                                                //                                                 0    PA9     PA10
                                                //                                                 1    PB6     PB7
    USART2                              , 1,    //3             0               USART2 remapping:       CTS     RTS     TX      RX      CK
                                                //                                                 0    PA0     PA1     PA2     PA3     PA4
                                                //                                                 1    PD3     PD4     PD5     PD6     PD7
    USART3                              , 2,    //4-5           00              USART3 remapping:       TX      RX      CK      CTS     RTS
                                                //                                                 00   PB10    PB11    PB12    PB13    PB14
                                                //                                                 01   PC10    PC11    PC12    PB13    PB14
                                                //                                                 11   PD8     PD9     PD10    PD11    PD12
    TIM1                                , 2,    //6-7           00              TIM1 remapping:         ETR     CH1     CH2     CH3     CH4     BKIN    CH1N    CH2N    CH3N
                                                //                                                00    PA12    PA8     PA9     PA10    PA11    PB12    PB13    PB14    PB15
                                                //                                                01    PA12    PA8     PA9     PA10    PA11    PA6     PA7     PB0     PB1
                                                //                                                11    PE7     PE9     PE11    PE13    PE14    PE15    PE8     PE10    PE12
    TIM2                                , 2,    //8-9           00              TIM2 remapping:         CH1/ETR CH2     CH3     CH4
                                                //                                                00    PA0     PA1     A2      PA3
                                                //                                                01    PA15    PB3     PA2     PA3
                                                //                                                10    PA0     PA1     PB10    PB11
                                                //                                                11    PA15    PB3     PB10    PB11
    TIM3                                , 2,    //10-11         0               TIM3 remapping          CH1     CH2     CH3     CH4
                                                //                                                00    PA6     PA7     PB0     PB1
                                                //                                                10    PB4     PB5     PB0     PB1
                                                //                                                11    PC6     PC7     PC8     PC9
    TIM4                                , 1,    //12            0               TIM4 remapping:         CH1     CH2     CH3     CH4
                                                //                                                0     PB6     PB7     PB8     PB9
                                                //                                                1     PD12    PD13    PD14    PD15
    CAN1                                , 2,    //13-14         00              CAN remapping:          RX      TX
                                                //                                                00    PA11    PA12
                                                //                                                10    PB8     PB9 (x 36-pin package)
                                                //                                                11    PD0     PD1
    PD01                                , 1,    //15            0               Port D0/Port D1 mapping on OSC_IN/OSC_OUT, 1 as GPIO
    TIM5_CH4_ITN                        , 1,    //16            0               TIM5 channel4 internal remap
    /*** low-medium-high-XLdensity devices ***/
    ADC1_EX_TRG_INJ                     , 1,    //17            0               ADC 1 External trigger injected conversion remapping
    ADC1_EX_TRG_REG                     , 1,    //18            0               ADC 1 external trigger regular conversion remapping
    ADC2_EX_TRG_INJ                     , 1,    //19            0               ADC 2 external trigger injected conversion remapping
    ADC2_EX_TRG_REG                     , 1,    //20            0               ADC 2 external trigger regular conversion remapping
    /*** low-medium-high-XLdensity devices ***/
    /*** connectivity line devices ***/
    ETH                                 , 1,    //21            0               Ethernet MAC remapping: RX_DV-CRS_DV    RXD0    RXD1    RXD2    RXD3
                                                //                                                0     PA7             PC4     PC5     PB0     PB1
                                                //                                                1     PD8             PD9     PD10    PD11    PD12
    CAN2                                , 1,    //22            0               CAN2 I/O remapping:     RX      TX
                                                //                                                0     PB12    PB13
                                                //                                                1     PB5     PB6
    MII_RMII_SEL                        , 1,    //23            0               MII or RMII selection
    /*** connectivity line devices ***/
    SWJ_CFG                             , 3,    //24:26         0               Serial wire JTAG configuration
    /*** connectivity line devices ***/
    _reserved                           , 1,
    SPI3                                , 1,    //28            0               SPI3/I2S3 remapping:    NSS     SCK     MISO    MOSI
                                                //                                                0     PA15    PB3     PB4     PB5
                                                //                                                1     PA4     PC10    PC11    PC12
    TIM2_INT_TRG1                       , 1,    //29            0               TIM2 internal trigger 1 remapping
    PTP_PPS                             , 1,    //30            0               Ethernet PTP PPS remapping
    /*** connectivity line devices ***/
    _reserved1                          , 1);
  union
  {
    RSTRUCT(REGS, unsigned int, r1, r2, r3, r4);
    BSTRUCT(BITS, unsigned int,
      EXTI0                             , 4,    //0:3
      EXTI1                             , 4,    //4:7
      EXTI2                             , 4,    //8:11
      EXTI3                             , 4,    //12:15
      _reserved                         , 16,
      EXTI4                             , 4,    //0:3
      EXTI5                             , 4,    //4:7
      EXTI6                             , 4,    //8:11
      EXTI7                             , 4,    //12:15
      _reserved1                        , 16,
      EXTI8                             , 4,    //0:3
      EXTI9                             , 4,    //4:7
      EXTI10                            , 4,    //8:11
      EXTI11                            , 4,    //12:15
      _reserved2                        , 16,
      EXTI12                            , 4,    //0:3
      EXTI13                            , 4,    //4:7
      EXTI14                            , 4,    //8:11
      EXTI15                            , 4,    //12:15
      _reserved3                        , 16);
  } EXTICR;                                     //              0x0000'0000     External interrupt configuration register
  unsigned int _reserved;
  BUNION(MAPR2, unsigned int,                   //              0x0000'0000     AF remap and debug I/O configuration register2
    TIM15                               , 1,    //0             0
    TIM16                               , 1,    //1             0
    TIM17                               , 1,    //2             0
    CEC                                 , 1,    //3             0
    TIM1_DMA                            , 1,    //4             0
    TIM9                                , 1,    //5             0               TIM9 remapping:         CH1     CH2
                                                //                                                0     PA2     PA3
                                                //                                                1     PE5     PE6
    TIM10                               , 1,    //6             0               TIM10 remapping:        CH1
                                                //                                                0     PB8
                                                //                                                1     PF6
    TIM11                               , 1,    //7             0               TIM11 remapping:        CH1
                                                //                                                0     PB9
                                                //                                                1     PF7
    TIM13                               , 1,    //8             0               TIM13 remapping:        CH1
                                                //                                                0     PA6
                                                //                                                1     PF8
    TIM14                               , 1,    //9             0               TIM14 remapping:        CH1
                                                //                                                0     PA7
                                                //                                                1     PF9
    FSMC_NADV                           , 1,    //10            0               NADV connect/disconnect
    TIM67_DAC_DMA                       , 1,    //11            0
    TIM12                               , 1,    //12            0
    MISC                                , 1,    //13            0
    Reserved                            , 18);
} AFIO_TypeDef;

typedef struct
{
  RSTRUCT(EVCR, unsigned int,                   //              0x0000'0000     Event control register
    PIN                                 [4],    //0:3           0               Pin selectio
    PORT                                [3],    //4:6           0               Port selection
    EVOE                                   ,    //7             0               Event output enable
    _reserved                           [24]);
  RSTRUCT(MAPR, unsigned int,                   //              0x0000'0000     AF remap and debug I/O configuration register
    SPI1                                   ,    //0             0               SPI1 remapping:         NSS     SCK     MISO    MOSI
    I2C1                                   ,    //1             0               I2C1 remapping:         SCL     SDA
    USART1                                 ,    //2             0               USART1 remapping:       TX      RX
    USART2                                 ,    //3             0               USART2 remapping:       CTS     RTS     TX      RX      CK
    USART3                              [2],    //4-5           00              USART3 remapping:       TX      RX      CK      CTS     RTS
    TIM1                                [2],    //6-7           00              TIM1 remapping:         ETR     CH1     CH2     CH3     CH4     BKIN    CH1N    CH2N    CH3N
    TIM2                                [2],    //8-9           00              TIM2 remapping:         CH1/ETR CH2     CH3     CH4
    TIM3                                [2],    //10-11         0               TIM3 remapping          CH1     CH2     CH3     CH4
    TIM4                                   ,    //12            0               TIM4 remapping:         CH1     CH2     CH3     CH4
    CAN1                                [2],    //13-14         00              CAN remapping:          RX      TX
    PD01                                   ,    //15            0               Port D0/Port D1 mapping on OSC_IN/OSC_OUT
    TIM5CH4_IREMAP                         ,    //16            0               TIM5 channel4 internal remap
    /*** low-medium-high-XLdensity devices ***/
    ADC1_ETRGINJ                           ,    //17            0               ADC 1 External trigger injected conversion remapping
    ADC1_ETRGREG                           ,    //18            0               ADC 1 external trigger regular conversion remapping
    ADC2_ETRGINJ                           ,    //19            0               ADC 2 external trigger injected conversion remapping
    ADC2_ETRGREG                           ,    //20            0               ADC 2 external trigger regular conversion remapping
    /*** low-medium-high-XLdensity devices ***/
    /*** connectivity line devices ***/
    ETH                                    ,    //21            0               Ethernet MAC remapping: RX_DV-CRS_DV    RXD0    RXD1    RXD2    RXD3
    CAN2                                   ,    //22            0               CAN2 I/O remapping:     RX      TX
    MII_RMII_SEL                           ,    //23            0               MII or RMII selection
    /*** connectivity line devices ***/
    SWJ_CFG                             [3],    //24:26         0               Serial wire JTAG configuration
    /*** connectivity line devices ***/
    _reserved                              ,
    SPI3                                   ,    //28            0               SPI3/I2S3 remapping:    NSS     SCK     MISO    MOSI
    TIM2ITR1_IREMAP                        ,    //29            0               TIM2 internal trigger 1 remapping
    PTP_PPS                                ,    //30            0               Ethernet PTP PPS remapping
    /*** connectivity line devices ***/
    _reserved1                             );
  RSTRUCT(EXTICR, unsigned int,                 //              0x0000'0000     External interrupt configuration register
    EXTI0                               [4],    //0:3
    EXTI1                               [4],    //4:7
    EXTI2                               [4],    //8:11
    EXTI3                               [4],    //12:15
    _reserved                           [16],
    EXTI4                               [4],    //0:3
    EXTI5                               [4],    //4:7
    EXTI6                               [4],    //8:11
    EXTI7                               [4],    //12:15
    _reserved1                          [16],
    EXTI8                               [4],    //0:3
    EXTI9                               [4],    //4:7
    EXTI10                              [4],    //8:11
    EXTI11                              [4],    //12:15
    _reserved2                          [16],
    EXTI12                              [4],    //0:3
    EXTI13                              [4],    //4:7
    EXTI14                              [4],    //8:11
    EXTI15                              [4],    //12:15
    _reserved3                          [16]);
  unsigned int _reserved[32];
  RSTRUCT(MAPR2, unsigned int,                  //              0x0000'0000     AF remap and debug I/O configuration register2
    TIM15                                  ,    //0             0
    TIM16                                  ,    //1             0
    TIM17                                  ,    //2             0
    CEC                                    ,    //3             0
    TIM1_DMA                               ,    //4             0
    TIM9                                   ,    //5             0               TIM9 remapping
    TIM10                                  ,    //6             0               TIM10 remapping
    TIM11                                  ,    //7             0               TIM11 remapping
    TIM13                                  ,    //8             0               TIM13 remapping
    TIM14                                  ,    //9             0               TIM14 remapping
    FSMC_NADV                              ,    //10            0               NADV connect/disconnect
    TIM67_DAC_DMA                          ,    //11            0
    TIM12                                  ,    //12            0
    MISC                                   ,    //13            0
    Reserved                            [18]);
} AFIO_BITBAND_TypeDef;

#endif