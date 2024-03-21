#ifndef _IDWG_H_
#define _IDWG_H_

#include <common.h>
#include <define.h>
//                                      |       //Address       Default         Description
typedef struct
{
  unsigned int KEY;                             //              0x0000'0000     Key register (16 bits low is used)
  unsigned int PR;                              //              0x0000'0000     Prescaler register (3 bits low is used)
  unsigned int PLR;                             //              0x0000'0FFF     Reload register (12 bits low is used)
  BUNION(SR, unsigned int,                      //              0x0000'0000     Status register
    PVU                                 , 1,    //0             0               Watchdog prescaler value update
    RVU                                 , 1,    //1             0               Watchdog counter reload value update
    _reserved                           , 30);
} IDWG_TypeDef;

typedef struct
{
  unsigned int KEY[32];                         //              0x0000'0000     Key register (16 bits low is used)
  unsigned int PR[32];                          //              0x0000'0000     Prescaler register (3 bits low is used)
  unsigned int PLR[32];                         //              0x0000'0FFF     Reload register (12 bits low is used)
  RSTRUCT(SR, unsigned int,                     //              0x0000'0000     Status register
    PVU                                    ,    //0             0               Watchdog prescaler value update
    RVU                                    ,    //1             0               Watchdog counter reload value update
    _reserved                           [30]);
} IDWG_BITBAND_TypeDef;

#endif