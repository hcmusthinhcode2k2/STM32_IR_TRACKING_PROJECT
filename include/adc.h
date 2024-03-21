#ifndef _ADC_H_
#define _ADC_H_

#include <common.h>
#include <define.h>
//                                      |       //Address       Default         Description
typedef struct
{
  BUNION(SR, unsigned long,                      //              0x0000'0000     ADC status register
    AWD                                 , 1,    //0             0               Analog watchdog flag
    EOC                                 , 1,    //1             0               End of conversion
    JEOC                                , 1,    //2             0               Injected channel end of conversion
    JSTRT                               , 1,    //3             0               Injected channel Start flag
    STRT                                , 1,    //4             0               Regular channel Start flag
    _reserved                           , 27);
  BUNION(CR1, unsigned long,                     //              0x0000'0000     ADC control register 1
    AWDCH                               , 5,    //0:4           0               Analog watchdog channel select bits
    EOCIE                               , 1,    //5             0               Interrupt enable for EOC
    AWDIE                               , 1,    //6             0               Analog watchdog interrupt enable
    JEOCIE                              , 1,    //7             0               Interrupt enable for injected channels
    SCAN                                , 1,    //8             0               Scan mode
    AWDSGL                              , 1,    //9             0               Enable the watchdog on a single channel in scan mode
    JAUTO                               , 1,    //10            0               Automatic Injected Group conversion 
    DISCEN                              , 1,    //11            0               Discontinuous mode on regular channels
    JDISCEN                             , 1,    //12            0               Discontinuous mode on injected channels
    DISCNUM                             , 3,    //13:15         0               Discontinuous mode channel count
    DUALMOD                             , 4,    //16:19         0               Dual mode selection
    _reserved                           , 2,
    JAWDEN                              , 1,    //22            0               Analog watchdog enable on injected channels
    AWDEN                               , 1,    //23            0               Analog watchdog enable on regular channels
    _reserved1                          , 8);
  BUNION(CR2, unsigned long,                     //              0x0000'0000     ADC control register 2
    ADON                                , 1,    //0             0               A/D converter ON / OFF
    CONT                                , 1,    //1             0               Continuous conversion
    CAL                                 , 1,    //2             0               A/D Calibration
    RSTCAL                              , 1,    //3             0               Reset calibration
    _reserved                           , 4,
    DMA                                 , 1,    //8             0               Direct memory access mode
    _reserved1                          , 2,    //              0
    ALIGN                               , 1,    //11            0               Data alignment
    JEXTSEL                             , 3,    //12:14         0               External event select for injected group
    JEXTTRIG                            , 1,    //15            0               External trigger conversion mode for injected channels
    _reserved2                          , 1,
    EXTSEL                              , 3,    //17:19         0               External event select for regular group
    EXTTRIG                             , 1,    //20            0               External trigger conversion mode for regular channels
    JSWSTART                            , 1,    //21            0               Start conversion of injected channels
    SWSTART                             , 1,    //22            0               Start conversion of regular channels
    TSVREFE                             , 1,    //23            0               Temperature sensor and VREFINT enable
    _reserved3                          , 8);
  UNION(SMPR,
    RSTRUCT(REGS, unsigned long, r1, r2);
    BSTRUCT(BITS, unsigned long,
      CN10                              , 3,    //0:2           0               Channel x Sample time selection
      CN11                              , 3,    //3:5           0
      CN12                              , 3,    //6:8           0
      CN13                              , 3,    //9:11          0
      CN14                              , 3,    //12:14         0
      CN15                              , 3,    //15:17         0
      CN16                              , 3,    //18:20         0
      CN17                              , 3,    //21:23         0
      _reserved                         , 8,
      CN0                               , 3,    //0:2           0
      CN1                               , 3,    //3:5           0
      CN2                               , 3,    //6:8           0
      CN3                               , 3,    //9:11          0
      CN4                               , 3,    //12:14         0
      CN5                               , 3,    //15:17         0
      CN6                               , 3,    //18:20         0
      CN7                               , 3,    //21:23         0
      CN8                               , 3,    //24:26         0
      CN9                               , 3,    //27:29         0
      _reserved1                        , 2););
  unsigned long JOFFSET[4];                      //              0x0000'0000     ADC injected channel data offset register
  unsigned long thresh_hold[2];
//  RSTRUCT(THRESH_HOLD, unsigned long, 
//    HIGH,                                       //              0x0000'0FFF 
//    LOW);                                       //              0x0000'0000
   UNION(SQR,                                   //              0x0000'0000-3   ADC regular sequence register
    RSTRUCT(REGS, unsigned long, r1, r2, r3);
    BSTRUCT(BITS, unsigned long,
      th13                              , 5,    //0:4           0               13th conversion in regular sequence
      th14                              , 5,    //5:9
      th15                              , 5,    //10:14
      th16                              , 5,    //15:19
      Length                            , 4,    //20:23         0               Regular channel sequence length
      _reserved                         , 8,
      th7                               , 5,    //0:4  
      th8                               , 5,    //5:9
      th9                               , 5,    //10:14
      th10                              , 5,    //15:19
      th11                              , 5,    //20:24
      th12                              , 5,    //25:29
      _reserved1                        , 2,
      st1                               , 5,    //0:4  
      nd2                               , 5,    //5:9
      rd3                               , 5,    //10:14
      th4                               , 5,    //15:19
      th5                               , 5,    //20:24
      th6                               , 5,    //25:29
      _reserved2                        , 2););
  BUNION(JSQR, unsigned long,                    //              0x0000'0000     ADC injected sequence register
    CN1                                 , 5,    //0:4           0               first conversion in injected sequence
    CN2                                 , 5,    //5:9
    CN3                                 , 5,    //10:14
    CN4                                 , 5,    //15:19
    JL                                  , 2,    //20-21         0               Injected sequence length
    _reserved                           , 10);
  unsigned long JDATA[4];                        //              0x0000'0000     ADC injected data register
  BUNION(DR, unsigned long,                      //              0x0000'0000     ADC regular data register
    DATA                                , 16,   //0:15          0               Regular data
    ADC2DATA                            , 16);  //16:31         0               ADC2 data
} ADC_TypeDef;
typedef struct
{
  RSTRUCT(SR, unsigned long,                     //              0x0000'0000     ADC status register
    AWD                                    ,    //0             0               Analog watchdog flag
    EOC                                    ,    //1             0               End of conversion
    JEOC                                   ,    //2             0               Injected channel end of conversion
    JSTRT                                  ,    //3             0               Injected channel Start flag
    STRT                                   ,    //4             0               Regular channel Start flag
    _reserved                           [27]);
  RSTRUCT(CR1, unsigned long,                    //              0x0000'0000     ADC control register 1
    AWDCH                               [5],    //0:4           0               Analog watchdog channel select bits
    EOCIE                                  ,    //5             0               Interrupt enable for EOC
    AWDIE                                  ,    //6             0               Analog watchdog interrupt enable
    JEOCIE                                 ,    //7             0               Interrupt enable for injected channels
    SCAN                                   ,    //8             0               Scan mode
    AWDSGL                                 ,    //9             0               Enable the watchdog on a single channel in scan mode
    JAUTO                                  ,    //10            0               Automatic Injected Group conversion 
    DISCEN                                 ,    //11            0               Discontinuous mode on regular channels
    JDISCEN                                ,    //12            0               Discontinuous mode on injected channels
    DISCNUM                             [3],    //13:15         0               Discontinuous mode channel count
    DUALMOD                             [4],    //16:19         0               Dual mode selection
    _reserved                           [2],
    JAWDEN                                 ,    //22            0               Analog watchdog enable on injected channels
    AWDEN                                  ,    //23            0               Analog watchdog enable on regular channels
    _reserved1                          [8]);
  RSTRUCT(CR2, unsigned long,                    //              0x0000'0000     ADC control register 2
    ADON                                   ,    //0             0               A/D converter ON / OFF
    CONT                                   ,    //1             0               Continuous conversion
    CAL                                    ,    //2             0               A/D Calibration
    RSTCAL                                 ,    //3             0               Reset calibration
    _reserved                           [4],
    DMA                                    ,    //8             0               Direct memory access mode
    _reserved1                          [2],    //              0
    ALIGN                                  ,    //11            0               Data alignment
    JEXTSEL                             [3],    //12:14         0               External event select for injected group
    JEXTTRIG                               ,    //15            0               External trigger conversion mode for injected channels
    _reserved2                             ,
    EXTSEL                              [3],    //17:19         0               External event select for regular group
    EXTTRIG                                ,    //20            0               External trigger conversion mode for regular channels
    JSWSTART                               ,    //21            0               Start conversion of injected channels
    SWSTART                                ,    //22            0               Start conversion of regular channels
    TSVREFE                                ,    //23            0               Temperature sensor and VREFINT enable
    _reserved3                          [8]);
  RSTRUCT(SMPR, unsigned long,                  //              0x0000'0000     ADC sample time register 1
    CN10                                [3],    //0:2           0               Channel x Sample time selection
    CN11                                [3],    //3:5           0
    CN12                                [3],    //6:8           0
    CN13                                [3],    //9:11          0
    CN14                                [3],    //12:14         0
    CN15                                [3],    //15:17         0
    CN16                                [3],    //18:20         0
    CN17                                [3],    //21:23         0
    _reserved                           [8],
    CN0                                 [3],    //0:2           0
    CN1                                 [3],    //3:5           0
    CN2                                 [3],    //6:8           0
    CN3                                 [3],    //9:11          0
    CN4                                 [3],    //12:14         0
    CN5                                 [3],    //15:17         0
    CN6                                 [3],    //18:20         0
    CN7                                 [3],    //21:23         0
    CN8                                 [3],    //24:26         0
    CN9                                 [3],    //27:29         0
    _reserved1                          [2]);  
  unsigned long JOFFSET[4][32];                  //              0x0000'0000     ADC injected channel data offset register
  unsigned long thresh_hold[64];
//  RSTRUCT(THRESH_HOLD, unsigned long, 
//    HIGH[32],                                   //              0x0000'0FFF 
//    LOW[32]);                                   //              0x0000'0000
  RSTRUCT(SQR, unsigned long,
    CN13                              [5],    //0:4           0               16th conversion in regular sequence
    CN14                              [5],    //5:9
    CN15                              [5],    //10:14
    CN16                              [5],    //15:19
    L                                 [4],    //20:23         0               Regular channel sequence length
    _reserved                         [8],
    CN7                               [5],    //0:4  
    CN8                               [5],    //5:9
    CN9                               [5],    //10:14
    CN10                              [5],    //15:19
    CN11                              [5],    //20:24
    CN12                              [5],    //25:29
    _reserved1                        [2],
    CN1                               [5],    //0:4  
    CN2                               [5],    //5:9
    CN3                               [5],    //10:14
    CN4                               [5],    //15:19
    CN5                               [5],    //20:24
    CN6                               [5],    //25:29
    _reserved2                        [2]);
  RSTRUCT(JSQR, unsigned long,                   //              0x0000'0000     ADC injected sequence register
    CN1                                 [5],    //0:4           0               first conversion in injected sequence
    CN2                                 [5],    //5:9
    CN3                                 [5],    //10:14
    CN4                                 [5],    //15:19
    JL                                  [2],    //20-21         0               Injected sequence length
    _reserved                           [10]);
  unsigned long JDATA[4];                        //              0x0000'0000     ADC injected data register
  RSTRUCT(DR, unsigned long,                     //              0x0000'0000     ADC regular data register
    DATA                                [16],   //0:15          0               Regular data
    ADC2DATA                            [16]);  //16:31         0               ADC2 data
} ADC_BITBAND_TypeDef;
//==============================================================================================================================================================
//===========================================================       LEVEL 1      ===============================================================================
//==============================================================================================================================================================
#define ADC_ContinuedMode(ADC, IsSet)           (ADC)->CR2.BITS.CONT = IsSet
//==============================================================================================================================================================
#define ADC_TEMPER_ENABLE               BIT23
void ADC_Start(volatile ADC_TypeDef* ADC, unsigned long Channel);               //(channel & bit23) -> Temperature sensor and VREFINT enable, ex: ADC_Start(&ADC1, 16 | ADC_TEMPER_ENABLE);
void ADC_StartGroup(volatile ADC_TypeDef* ADC, const unsigned char* Channels);  //end config with <index> if Channels[<index>] > 17; only using with DMA: DMA.Buffer[n] = Channels[n].Data
unsigned long ADC_Read(volatile ADC_TypeDef* ADC, unsigned long* OutValue);     //if End-Of-Converter: OutValue += ADC.Data; return 1;   else return 0;
//==============================================================================================================================================================

#endif