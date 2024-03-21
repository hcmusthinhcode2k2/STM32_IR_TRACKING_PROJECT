#ifndef _WWDG_H_
#define _WWDG_H_

#include <common.h>
#include <define.h>
//                                      |       //Address       Default         Description
typedef struct
{
  BUNION(CR, unsigned int,                      //              0x0000'007F     Control register
    T                                   , 7,    //0:6           0x7F            7-bit counter (MSB to LSB)
    WDGA                                , 1,    //7             0               Activation bit
    _reserved                           , 24);
  BUNION(CFR, unsigned int,                     //              0x0000'007F     Configuration register
    W                                   , 7,    //0:6           0x7F            7-bit window value
    WDGTB                               , 2,    //7-8           0               Timer base
    EWI                                 , 1,    //9             0               Early wakeup interrupt
    _reserved                           , 22);
  BUNION(SR, unsigned int,                      //              0x0000'0000     Status register
    EWIF                                , 1,    //0             0               Early wakeup interrupt flag
    _reserved                           , 31);
} WWDG_TypeDef;

typedef struct
{
  RSTRUCT(CR, unsigned int,                     //              0x0000'007F     Control register
    T                                   [7],    //0:6           0x7F            7-bit counter (MSB to LSB)
    WDGA                                   ,    //7             0               Activation bit
    _reserved                           [24]);
  RSTRUCT(CFR, unsigned int,                    //              0x0000'007F     Configuration register
    W                                   [7],    //0:6           0x7F            7-bit window value
    WDGTB                               [2],    //7-8           0               Timer base
    EWI                                    ,    //9             0               Early wakeup interrupt
    _reserved                           [22]);
  RSTRUCT(SR, unsigned int,                     //              0x0000'0000     Status register
    EWIF                                   ,    //0             0               Early wakeup interrupt flag
    _reserved                           [31]);
} WWDG_BITBAND_TypeDef;

#endif