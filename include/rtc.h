#ifndef _RTC_H_
#define _RTC_H_

#include <common.h>
#include <define.h>
//                                      |       //Address       Default         Description
typedef struct
{
  BUNION(CRH, unsigned int,                     //              0x0000'0000     RTC control register high
    SECIE                               , 1,    //              0               Second interrupt enable
    ALRIE                               , 1,    //              0               Alarm interrupt enable
    OWIE                                , 1,    //              0               Overflow interrupt enable
    _reserved                           , 29);
  BUNION(CRL, unsigned int,                     //              0x0000'0020     RTC control register low
    SECF                                , 1,    //0             0               Second flag
    ALRF                                , 1,    //1             0               Alarm flag
    OWF                                 , 1,    //2             0               Overflow flag
    RSF                                 , 1,    //3             0               Registers synchronized flag
    CNF                                 , 1,    //4             0               Configuration flag
    const RTOFF                         , 1,    //5             1               RTC operation OFF
    _reserved                           , 26);
  RSTRUCT(PRL, unsigned int,                    //                              RTC prescaler load register
    HIGH,                                       //              0x0000'0000     (16 bits low is used)
    LOW);                                       //              0x0000'000C     (16 bits low is used)
  RSTRUCT(DIV, unsigned int,                    //                              RTC prescaler divider register
    const HIGH,                                 //              0x0000'0000     (4 bits low is used)
    const LOW);                                 //              0x0000'8000     (16 bits low is used)
  RSTRUCT(CNT, unsigned int,                    //                              RTC counter register
    HIGH,                                       //              0x0000'0000     (16 bits low is used)
    LOW);                                       //              0x0000'0000     (16 bits low is used)
  RSTRUCT(ALR, unsigned int,                    //                              RTC alarm register
    HIGH,                                       //              0x0000'FFFF     (16 bits low is used)
    LOW);                                       //              0x0000'FFFF     (16 bits low is used)
} RTC_TypeDef;

//                                      //Address       Default         Description
typedef struct
{
  RSTRUCT(CRH, unsigned int,                    //              0x0000'0000     RTC control register high
    SECIE                                  ,    //              0               Second interrupt enable
    ALRIE                                  ,    //              0               Alarm interrupt enable
    OWIE                                   ,    //              0               Overflow interrupt enable
    _reserved                           [29]);
  RSTRUCT(CRL, unsigned int,                    //              0x0000'0020     RTC control register low
    SECF                                   ,    //0             0               Second flag
    ALRF                                   ,    //1             0               Alarm flag
    OWF                                    ,    //2             0               Overflow flag
    RSF                                    ,    //3             0               Registers synchronized flag
    CNF                                    ,    //4             0               Configuration flag
    const RTOFF                            ,    //5             1               RTC operation OFF
    _reserved                           [26]);
  RSTRUCT(PRL, unsigned int,                    //                              RTC prescaler load register
    HIGH[32],                                   //              0x0000'0000     (16 bits low is used)
    LOW[32]);                                   //              0x0000'000C     (16 bits low is used)
  RSTRUCT(DIV, unsigned int,                    //                              RTC prescaler divider register
    const HIGH[32],                             //              0x0000'0000     (4 bits low is used)
    const LOW[32]);                             //              0x0000'8000     (16 bits low is used)
  RSTRUCT(CNT, unsigned int,                    //                              RTC counter register
    HIGH[32],                                   //              0x0000'0000     (16 bits low is used)
    LOW[32]);                                   //              0x0000'0000     (16 bits low is used)
  RSTRUCT(ALR, unsigned int,                    //                              RTC alarm register
    HIGH[32],                                   //              0x0000'FFFF     (16 bits low is used)
    LOW[32]);                                   //              0x0000'FFFF     (16 bits low is used)
} RTC_BITBAND_TypeDef;

#endif