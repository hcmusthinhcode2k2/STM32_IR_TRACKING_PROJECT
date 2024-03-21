#ifndef _DAC_H_
#define _DAC_H_

#include <define.h>

//                                      //Address       Default         Description
typedef struct
{
  UNION(CR, unsigned int,               //              0x0000'0000     DAC control register
        EN1             , 1,            //              0               DAC channel1 enable
        BOFF1           , 1,            //              0               DAC channel1 output buffer disable
        TEN1            , 1,            //              0               DAC channel1 trigger enable
        TSEL1           , 3,            //              0               DAC channel1 trigger selection
        WAVE1           , 3,            //              0               DAC channel1 noise/triangle wave generation enable
        MAMP1           , 4,            //              0               DAC channel1 mask/amplitude selector
        DMAEN1          , 1,            //              0               DAC channel1 DMA enable
        _Reserved       , 3,
        EN2             , 1,            //              0               DAC channel2 enable
        BOFF2           , 1,            //              0               DAC channel2 output buffer disable
        TEN2            , 1,            //              0               DAC channel2 trigger enable
        TSEL2           , 3,            //              0               DAC channel2 trigger selection
        WAVE2           , 3,            //              0               DAC channel2 noise/triangle wave generation enable
        MAMP2           , 4,            //              0               DAC channel2 mask/amplitude selector
        DMAEN2          , 1,            //              0               DAC channel2 DMA enable
        _Reserved1      , 3);
  UNION(SWTRIGR, unsigned int,          //              0x0000'0000     DAC software trigger register
        SWTRIG1         , 1,            //              0               DAC channel1 software trigger
        SWTRIG2         , 1,            //              0               DAC channel2 software trigger
        _Reserved       , 30);
  struct
  {
    struct
    {
      unsigned int _12BITS_RIGHT;       //              0x0000'00000
      unsigned int _12BITS_LEFT;        //              0x0000'00000
      unsigned int _8BITS;              //              0x0000'00000
    } Channel_1;
    struct
    {
      unsigned int _12BITS_RIGHT;       //              0x0000'00000
      unsigned int _12BITS_LEFT;        //              0x0000'00000
      unsigned int _8BITS;              //              0x0000'00000
    } Channel_2;
    UNION(DUAL_12BITS_RIGHT,            //              0x0000'00000
          unsigned int,
          CN1           , 16,
          CN2           , 16);
    UNION(DUAL_12BITS_LEFT,             //              0x0000'00000
          unsigned int,
          CN1           , 16,
          CN2           , 16);
    UNION(DUAL_8BITS, unsigned int,     //              0x0000'00000
          CN1           , 8,
          CN2           , 8,
          _Reserved, 16);
    struct
    {
      const unsigned int CN1;           //              0x0000'00000
      const unsigned int CN2;           //              0x0000'00000
    } OUTPUT;
  } DATA;  
} DAC_TypeDef;

//                                      //Address       Default         Description
typedef struct
{
  REGS_STRUCT(CR, unsigned int,         //              0x0000'0000     DAC control register
        EN1                ,            //              0               DAC channel1 enable
        BOFF1              ,            //              0               DAC channel1 output buffer disable
        TEN1               ,            //              0               DAC channel1 trigger enable
        TSEL1           [3],            //              0               DAC channel1 trigger selection
        WAVE1           [3],            //              0               DAC channel1 noise/triangle wave generation enable
        MAMP1           [4],            //              0               DAC channel1 mask/amplitude selector
        DMAEN1             ,            //              0               DAC channel1 DMA enable
        _Reserved       [3],
        EN2                ,            //              0               DAC channel2 enable
        BOFF2              ,            //              0               DAC channel2 output buffer disable
        TEN2               ,            //              0               DAC channel2 trigger enable
        TSEL2           [3],            //              0               DAC channel2 trigger selection
        WAVE2           [3],            //              0               DAC channel2 noise/triangle wave generation enable
        MAMP2           [4],            //              0               DAC channel2 mask/amplitude selector
        DMAEN2             ,            //              0               DAC channel2 DMA enable
        _Reserved1      [3]);
  REGS_STRUCT(SWTRIGR, unsigned int,    //              0x0000'0000     DAC software trigger register
        SWTRIG1            ,            //              0               DAC channel1 software trigger
        SWTRIG2            ,            //              0               DAC channel2 software trigger
        _Reserved       [30]);
  struct
  {
    struct
    {
      unsigned int _12BITS_RIGHT[32];   //              0x0000'00000
      unsigned int _12BITS_LEFT[32];    //              0x0000'00000
      unsigned int _8BITS[32];          //              0x0000'00000
    } Channel_1;
    struct
    {
      unsigned int _12BITS_RIGHT[32];   //              0x0000'00000
      unsigned int _12BITS_LEFT[32];    //              0x0000'00000
      unsigned int _8BITS[32];          //              0x0000'00000
    } Channel_2;
    REGS_STRUCT(DUAL_12BITS_RIGHT,      //              0x0000'00000
          unsigned int,
          CN1           [16],
          CN2           [16]);
    REGS_STRUCT(DUAL_12BITS_LEFT,       //              0x0000'00000
          unsigned int,
          CN1           [16],
          CN2           [16]);
    REGS_STRUCT(DUAL_8BITS, unsigned int,//             0x0000'00000
          CN1           [8],
          CN2           [8],
          _Reserved     [16]);
    struct
    {
      const unsigned int CN1[32];       //              0x0000'00000
      const unsigned int CN2[32];       //              0x0000'00000
    } OUTPUT;
  } DATA;  
} DAC_BITBAND_TypeDef;

#endif