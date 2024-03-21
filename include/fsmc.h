#ifndef _FSMC_H_
#define _FSMC_H_

#include <reg_define.h>

//                                      //Address       Default         Description
typedef UNION
(FSMC_BCR_TypeDef, unsigned int,        //              0x0000'30DB     SRAM/NOR-Flash chip-select control registers
  MBKEN                 , 1,            //              1               Memory bank enable bit
  MUXEN                 , 1,            //              1               Address/data multiplexing enable bit
  MTYP                  , 2,            //              0b10            Memory type  
  MWID                  , 2,            //              0b01            Memory databus width
  FACCEN                , 1,            //              1               Flash access enable
  _Reserved             , 1,  
  BURSTEN               , 1,            //              0               Burst enable bit
  WAITPOL               , 1,            //              0               Wait signal polarity bit
  WRAPMOD               , 1,            //              0               Wrapped burst mode support
  WAITCFG               , 1,            //              0               Wait timing configuration
  WREN                  , 1,            //              1               Write enable bit
  WAITEN                , 1,            //              1               Wait enable bit
  EXTMOD                , 1,            //              0               Extended mode enable
  ASYNCWAIT             , 1,            //              0               Wait signal during asynchronous transfers
  CPSIZE                , 3,            //              0               CRAM page size
  CBURSTRW              , 1,            //              0               Write burst enable
  _Reserved1            , 12);
typedef UNION
(FSMC_BTR_TypeDef, unsigned int,        //              0x0FFF'FFFF     SRAM/NOR-Flash chip-select timing registers
  ADDSET                , 4,            //              0xF             Address setup phase duration
  ADDHLD                , 4,            //              0xF             Address-hold phase duration
  DATAST                , 8,            //              0xFF            Data-phase duration
  BUSTURN               , 4,            //              0xF             Bus turnaround phase duration
  CLKDIV                , 4,            //              0xF             Clock divide ratio
  DATLAT                , 4,            //              0xF             Data latency for synchronous NOR Flash memory
  ACCMOD                , 2,            //              3               Access mode
  _Reserved             , 2);
typedef UNION
(FSMC_BWTR_TypeDef, unsigned int,       //              0x0FFF'FFFF     SRAM/NOR-Flash write timing registers
  ADDSET                , 4,            //              0xF             Address setup phase duration
  ADDHLD                , 4,            //              0xF             Address-hold phase duration
  DATAST                , 8,            //              0xFF            Data-phase duration
  BUSTURN               , 4,            //              0xF             Bus turnaround phase duration
  _Reserved             , 8,
  ACCMOD                , 2,            //              3               Access mode
  _Reserved1            , 2);
typedef UNION
(FSMC_PCR_TypeDef, unsigned int,        //              0x0000'0018     NAND Flash/PC Card control registers
  _Reserved             , 1,
  PWAITEN               , 1,            //              0               Wait feature enable bit
  PBKEN                 , 1,            //              0               PC Card/NAND Flash memory bank enable bit
  PTYP                  , 1,            //              1               Memory type
  PWID                  , 2,            //              1               Databus width
  ECCEN                 , 1,            //              0               ECC computation logic enable bit
  _Reserved1            , 2,
  TCLR                  , 4,            //              0               CLE to RE delay
  TAR                   , 4,            //              0               ALE to RE delay
  ECCPS                 , 3,            //              0               ECC page size
  _Reserved2            , 12);
typedef UNION
(FSMC_SR_TypeDef, unsigned int,         //              0x0000'0040     FIFO status and interrupt register
  IRS                   , 1,            //              0               Interrupt rising edge status
  ILS                   , 1,            //              0               Interrupt high-level status
  IFS                   , 1,            //              0               Interrupt falling edge status
  IREN                  , 1,            //              0               Interrupt rising edge detection enable bit
  ILEN                  , 1,            //              0               Interrupt high-level detection enable bit
  IFEN                  , 1,            //              0               Interrupt falling edge detection enable bit
  const FEMPT           , 1,            //              1               FIFO empty
  _Reserved2            , 25);
typedef UNION
(FSMC_PMEM_TypeDef, unsigned int,       //              0xFCFC'FCFC     Common memory space timing register
  MEMSET                , 8,            //              0xFC            Common memory x setup time
  MEMWAIT               , 8,            //              0xFC            Common memory x wait time
  MEMHOLD               , 8,            //              0xFC            Common memory x hold time
  MEMHIZ                , 8);           //              0xFC            Common memory x databus HiZ time
typedef UNION
(FSMC_PATT_TypeDef, unsigned int,       //              0xFCFC'FCFC     Attribute memory space timing registers
  ATTSET                , 8,            //              0xFC            Attribute memory x setup time
  ATTWAIT               , 8,            //              0xFC            Attribute memory x wait time
  ATTHOLD               , 8,            //              0xFC            Attribute memory x hold time
  ATTHIZ                , 8);           //              0xFC            Attribute memory x databus HiZ time

typedef struct
{
  FSMC_BCR_TypeDef BCR1;
  FSMC_BTR_TypeDef BTR1;
  FSMC_BCR_TypeDef BCR2;
  FSMC_BTR_TypeDef BTR2;  
  FSMC_BCR_TypeDef BCR3;
  FSMC_BTR_TypeDef BTR3;
  FSMC_BCR_TypeDef BCR4;
  FSMC_BTR_TypeDef BTR4;
} FSMC_TypeDef;

#endif