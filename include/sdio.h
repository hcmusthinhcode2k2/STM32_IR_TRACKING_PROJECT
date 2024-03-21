#ifndef _SDIO_H_
#define _SDIO_H_

#include <define.h>

//                                      //Address       Default         Description
typedef struct
{
  unsigned int POWER;                   //              0x0000'0000     SDIO power control register
  UNION(CLKCR, unsigned int,            //              0x0000'0000     SDI clock control register
        CLKDIV          , 8,            //              0               Clock divide factor
        CLKEN           , 1,            //              0               Clock enable bit
        PWRSAV          , 1,            //              0               Power saving configuration bit
        BYPASS          , 1,            //              0               Clock divider bypass enable bit
        WIDBUS          , 2,            //              0               Wide bus mode enable bit
        NEGEDGE         , 1,            //              0               SDIO_CK dephasing selection bit
        HWFC_EN         , 1,            //              0               HW Flow Control enable
        _Reserved       , 17);
  unsigned int ARG;                     //              0x0000'0000     SDIO argument register
  UNION(CMD, unsigned int,              //              0x0000'0000     SDIO command register
        CMDINDEX        , 6,            //              0               Command index
        WAITRESP        , 2,            //              0               Wait for response bits
        WAITINT         , 1,            //              0               CPSM waits for interrupt request
        WAITPEND        , 1,            //              0               CPSM Waits for ends of data transfer
        CPSMEN          , 1,            //              0               Command path state machine (CPSM) Enable bit
        SDIOSuspend     , 1,            //              0               SD I/O suspend command
        ENCMDcompl      , 1,            //              0               Enable CMD completion
        nIEN            , 1,            //              0               not Interrupt Enable
        ATACMD          , 1,            //              0               CE-ATA command
        _Reserved       , 17);
  const unsigned int RESPCMD;           //              0x0000'0000     SDIO command response register
  const unsigned int CARDSTATUS[4];     //              0x0000'0000     SDIO response
  unsigned int DATATIME;                //              0x0000'0000     SDIO data timer register
  unsigned int DATALENGTH;              //              0x0000'0000     SDIO data length register (25 bits low)
  UNION(DCTRL, unsigned int,            //              0x0000'0000     SDIO data control register
        DTEN            , 1,            //              0               Data transfer enabled bit
        DTDIR           , 1,            //              0               Data transfer direction selection
        DTMODE          , 1,            //              0               Data transfer mode selection 1: Stream or SDIO multibyte data transfer
        DMAEN           , 1,            //              0               DMA enable bit
        DBLOCKSIZE      , 4,            //              0               Data block size
        RWSTART         , 1,            //              0               Read wait start
        RWSTOP          , 1,            //              0               Read wait stop
        RWMOD           , 1,            //              0               Read wait mode
        SDIOEN          , 1,            //              0               SD I/O enable functions
        _Reserved       , 20);
  const unsigned int DATACOUNT;         //              0x0000'0000     SDIO data counter register
  UNION(STA, const unsigned int,        //              0x0000'0000     SDIO status register
        CCRCFAIL        , 1,            //              0               Command response received
        DCRCFAIL        , 1,            //              0               Data block sent/received
        CTIMEOUT        , 1,            //              0               Command response timeout
        DTIMEOUT        , 1,            //              0               Data timeout
        TXUNDERR        , 1,            //              0               Transmit FIFO underrun error
        RXOVERR         , 1,            //              0               Received FIFO overrun error
        CMDREND         , 1,            //              0               Command response received
        CMDSENT         , 1,            //              0               Command sent
        DATAEND         , 1,            //              0               Data end
        STBITERR        , 1,            //              0               Start bit not detected on all data signals in wide bus mode
        DBCKEND         , 1,            //              0               Data block sent/received
        CMDACT          , 1,            //              0               Command transfer in progress
        TXACT           , 1,            //              0               Data transmit in progress
        RXACT           , 1,            //              0               Data receive in progress
        TXFIFOHE        , 1,            //              0               Transmit FIFO half empty: at least 8 words can be written into the FIFO
        RXFIFOHF        , 1,            //              0               Receive FIFO half full: there are at least 8 words in the FIFO
        TXFIFOF         , 1,            //              0               Transmit FIFO full
        RXFIFOF         , 1,            //              0               Receive FIFO full
        TXFIFOE         , 1,            //              0               Transmit FIFO empty
        RXFIFOE         , 1,            //              0               Receive FIFO empty
        TXDAVL          , 1,            //              0               Data available in transmit FIFO
        RXDAVL          , 1,            //              0               Data available in receive FIFO
        SDIOIT          , 1,            //              0               SDIO interrupt received
        CEATAEND        , 1,            //              0               CE-ATA command completion signal received for CMD61
        _Reserved       , 8);
  UNION(ICR, unsigned int,              //              0x0000'0000     SDIO interrupt clear register
        CCRCFAILC       , 1,
        DCRCFAILC       , 1,
        CTIMEOUTC       , 1,
        DTIMEOUTC       , 1,
        TXUNDERRC       , 1,
        RXOVERRC        , 1,
        CMDRENDC        , 1,
        CMDSENTC        , 1,
        DATAENDC        , 1,
        STBITERRC       , 1,
        DBCKENDC        , 1,
        _Reserved       , 11,
        SDIOITC         , 1,
        CEATAENDC       , 1,
        _Reserved1      , 8);
  UNION(MASK, unsigned int,             //              0x0000'0000     SDIO mask register
        CCRCFAILIE      , 1,            //              0               ... interrupt enable
        DCRCFAILIE      , 1,
        CTIMEOUTIE      , 1,
        DTIMEOUTIE      , 1,
        TXUNDERRIE      , 1,
        RXOVERRIE       , 1,
        CMDRENDIE       , 1,
        CMDSENTIE       , 1,
        DATAENDIE       , 1,
        STBITERRIE      , 1,
        DBCKENDIE       , 1,
        CMDACTIE        , 1,
        TXACTIE         , 1,
        RXACTIE         , 1,
        TXFIFOHEIE      , 1,
        RXFIFOHFIE      , 1,
        TXFIFOFIE       , 1,
        RXFIFOFIE       , 1,
        TXFIFOEIE       , 1,
        RXFIFOEIE       , 1,
        TXDAVLIE        , 1,
        RXDAVLIE        , 1,
        SDIOITIE        , 1,
        CEATAENDIE      , 1,
        _Reserved       , 8); 
  unsigned int _Reserved[0x48 - 0x3C];
  const unsigned int FIFOCOUNT;
  unsigned int _Reserved1[0x80 - 0x48];
  unsigned int FIFODATA;
} SDIO_TypeDef;

//                                      //Address       Default         Description
typedef struct
{
  unsigned int POWER[32];               //              0x0000'0000     SDIO power control register
  REGS_STRUCT(CLKCR, unsigned int,      //              0x0000'0000     SDI clock control register
        CLKDIV          [8],            //              0               Clock divide factor
        CLKEN              ,            //              0               Clock enable bit
        PWRSAV             ,            //              0               Power saving configuration bit
        BYPASS             ,            //              0               Clock divider bypass enable bit
        WIDBUS          [2],            //              0               Wide bus mode enable bit
        NEGEDGE            ,            //              0               SDIO_CK dephasing selection bit
        HWFC_EN            ,            //              0               HW Flow Control enable
        _Reserved       [17]);
  unsigned int ARG[32];                 //              0x0000'0000     SDIO argument register
  REGS_STRUCT(CMD, unsigned int,        //              0x0000'0000     SDIO command register
        CMDINDEX        [6],            //              0               Command index
        WAITRESP        [2],            //              0               Wait for response bits
        WAITINT            ,            //              0               CPSM waits for interrupt request
        WAITPEND           ,            //              0               CPSM Waits for ends of data transfer
        CPSMEN             ,            //              0               Command path state machine (CPSM) Enable bit
        SDIOSuspend        ,            //              0               SD I/O suspend command
        ENCMDcompl         ,            //              0               Enable CMD completion
        nIEN               ,            //              0               not Interrupt Enable
        ATACMD             ,            //              0               CE-ATA command
        _Reserved       [17]);
  const unsigned int RESPCMD[32];       //              0x0000'0000     SDIO command response register
  const unsigned int CARDSTATUS[4][32]; //              0x0000'0000     SDIO response
  unsigned int DATATIME[32];            //              0x0000'0000     SDIO data timer register
  unsigned int DATALENGTH[32];          //              0x0000'0000     SDIO data length register (25 bits low)
  REGS_STRUCT(DCTRL, unsigned int,      //              0x0000'0000     SDIO data control register
        DTEN               ,            //              0               Data transfer enabled bit
        DTDIR              ,            //              0               Data transfer direction selection
        DTMODE             ,            //              0               Data transfer mode selection 1: Stream or SDIO multibyte data transfer
        DMAEN              ,            //              0               DMA enable bit
        DBLOCKSIZE      [4],            //              0               Data block size
        RWSTART            ,            //              0               Read wait start
        RWSTOP             ,            //              0               Read wait stop
        RWMOD              ,            //              0               Read wait mode
        SDIOEN             ,            //              0               SD I/O enable functions
        _Reserved       [20]);
  const unsigned int DATACOUNT[32];     //              0x0000'0000     SDIO data counter register
  REGS_STRUCT(STA, const unsigned int,  //              0x0000'0000     SDIO status register
        CCRCFAIL           ,            //              0               Command response received
        DCRCFAIL           ,            //              0               Data block sent/received
        CTIMEOUT           ,            //              0               Command response timeout
        DTIMEOUT           ,            //              0               Data timeout
        TXUNDERR           ,            //              0               Transmit FIFO underrun error
        RXOVERR            ,            //              0               Received FIFO overrun error
        CMDREND            ,            //              0               Command response received
        CMDSENT            ,            //              0               Command sent
        DATAEND            ,            //              0               Data end
        STBITERR           ,            //              0               Start bit not detected on all data signals in wide bus mode
        DBCKEND            ,            //              0               Data block sent/received
        CMDACT             ,            //              0               Command transfer in progress
        TXACT              ,            //              0               Data transmit in progress
        RXACT              ,            //              0               Data receive in progress
        TXFIFOHE           ,            //              0               Transmit FIFO half empty: at least 8 words can be written into the FIFO
        RXFIFOHF           ,            //              0               Receive FIFO half full: there are at least 8 words in the FIFO
        TXFIFOF            ,            //              0               Transmit FIFO full
        RXFIFOF            ,            //              0               Receive FIFO full
        TXFIFOE            ,            //              0               Transmit FIFO empty
        RXFIFOE            ,            //              0               Receive FIFO empty
        TXDAVL             ,            //              0               Data available in transmit FIFO
        RXDAVL             ,            //              0               Data available in receive FIFO
        SDIOIT             ,            //              0               SDIO interrupt received
        CEATAEND           ,            //              0               CE-ATA command completion signal received for CMD61
        _Reserved       [8]);
  REGS_STRUCT(ICR, unsigned int,        //              0x0000'0000     SDIO interrupt clear register
        CCRCFAILC          ,
        DCRCFAILC          ,
        CTIMEOUTC          ,
        DTIMEOUTC          ,
        TXUNDERRC          ,
        RXOVERRC           ,
        CMDRENDC           ,
        CMDSENTC           ,
        DATAENDC           ,
        STBITERRC          ,
        DBCKENDC           ,
        _Reserved       [11],
        SDIOITC            ,
        CEATAENDC          ,
        _Reserved1      [8]);
  REGS_STRUCT(MASK, unsigned int,       //              0x0000'0000     SDIO mask register
        CCRCFAILIE         ,            //              0               ... interrupt enable
        DCRCFAILIE         ,
        CTIMEOUTIE         ,
        DTIMEOUTIE         ,
        TXUNDERRIE         ,
        RXOVERRIE          ,
        CMDRENDIE          ,
        CMDSENTIE          ,
        DATAENDIE          ,
        STBITERRIE         ,
        DBCKENDIE          ,
        CMDACTIE           ,
        TXACTIE            ,
        RXACTIE            ,
        TXFIFOHEIE         ,
        RXFIFOHFIE         ,
        TXFIFOFIE          ,
        RXFIFOFIE          ,
        TXFIFOEIE          ,
        RXFIFOEIE          ,
        TXDAVLIE           ,
        RXDAVLIE           ,
        SDIOITIE           ,
        CEATAENDIE         ,
        _Reserved       [8]); 
  unsigned int _Reserved[0x48 - 0x3C][32];
  const unsigned int FIFOCOUNT[32];
  unsigned int _Reserved1[0x80 - 0x48][32];
  unsigned int FIFODATA[32];
} SDIO_BITBAND_TypeDef;

#endif