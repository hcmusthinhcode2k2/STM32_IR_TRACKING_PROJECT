#ifndef _PWR_H_
#define _PWR_H_

#include <common.h>
#include <define.h>
//                                      |       //Address       Default         Description
typedef struct
{
  BUNION(CR, unsigned int,                      //              0x0000'0000     Power control register
    LPDS                                , 1,    //0             0               Low-power deepsleep
    PDDS                                , 1,    //1             0               Power down deepsleep
    CWUF                                , 1,    //2             0               Clear wakeup flag
    CSBF                                , 1,    //3             0               Clear standby flag
    PVDE                                , 1,    //4             0               Power voltage detector enable
    PLS                                 , 3,    //5:7           0               PVD level selection
    DBP                                 , 1,    //8             0               Disable backup domain write protection
    _Reserved                           , 23);
  BUNION(CSR, unsigned int,                     //              0x0000'0000     Power control/status register
    const WUF                           , 1,    //0             0               Wakeup flag
    const SBF                           , 1,    //1             0               Standby flag
    const PVDO                          , 1,    //2             0               PVD output
    _Reserved                           , 5,    //3:7           0               Enable WKUP pin
    EWUP                                , 1,    //8             0
    _Reserved1                          , 23);
} PWR_TypeDef;

typedef struct
{
  RSTRUCT(CR, unsigned int,                     //              0x0000'0000     Power control register
    LPDS                                   ,    //0             0               Low-power deepsleep
    PDDS                                   ,    //1             0               Power down deepsleep
    CWUF                                   ,    //2             0               Clear wakeup flag
    CSBF                                   ,    //3             0               Clear standby flag
    PVDE                                   ,    //4             0               Power voltage detector enable
    PLS                                 [3],    //5:7           0               PVD level selection
    DBP                                    ,    //8             0               Disable backup domain write protection
    _Reserved                           [23]);
  RSTRUCT(CSR, unsigned int,                    //              0x0000'0000     Power control/status register
    const WUF                              ,    //0             0               Wakeup flag
    const SBF                              ,    //1             0               Standby flag
    const PVDO                             ,    //2             0               PVD output
    _Reserved                           [5],    //3:7           0               Enable WKUP pin
    EWUP                                   ,    //8             0
    _Reserved1                          [23]);
} PWR_BITBAND_TypeDef;

#endif