#ifndef _SPI_H_
#define _SPI_H_

#include <common.h>
#include <define.h>
//                                      |       //Address       Default         Description
typedef struct
{
  BUNION(CR1, unsigned int,                     //              0x0000'0000     SPI control register 1 (not used in I2S mode)
    CPHA                                , 1,    //0             0               Clock phase
    CPOL                                , 1,    //1             0               Clock polarity
    MSTR                                , 1,    //2             0               Master selection
    BR                                  , 3,    //3:5           0               Baud rate control
    SPE                                 , 1,    //6             0               SPI enable
    LSBFIRST                            , 1,    //7             0               Frame format
    SSI                                 , 1,    //8             0               Internal slave select
    SSM                                 , 1,    //9             0               Software slave management
    RXONLY                              , 1,    //10            0               Receive only
    DFF                                 , 1,    //11            0               Data frame format
    CRCNEXT                             , 1,    //12            0               CRC transfer next
    CRCEN                               , 1,    //13            0               Hardware CRC calculation enable
    BIDIOE                              , 1,    //14            0               Output enable in bidirectional mode
    BIDIMODE                            , 1,    //15            0               Bidirectional data mode enable
    _reserved                           , 16);
  BUNION(CR2, unsigned int,                     //              0x0000'0000     SPI control register 2
    RXDMAEN                             , 1,    //0             0               Rx buffer DMA enable
    TXDMAEN                             , 1,    //1             0               Tx buffer DMA enable
    SSOE                                , 1,    //2             0               SS output enable
    _reserved                           , 2,
    ERRIE                               , 1,    //5             0               Error interrupt enable
    RXNEIE                              , 1,    //6             0               RX buffer not empty interrupt enable
    TXEIE                               , 1,    //7             0               Tx buffer empty interrupt enable
    _reserved1                          , 24);
  BUNION(SR, unsigned int,                      //              0x0000'0002     SPI status register
    const RXNE                          , 1,    //0             0               Receive buffer not empty
    const TXE                           , 1,    //1             1               Transmit buffer empty
    const CHSIDE                        , 1,    //2             0               Channel side
    const UDR                           , 1,    //3             0               Underrun flag
    CRCERR                              , 1,    //4             0               CRC error flag
    const MODF                          , 1,    //5             0               Mode fault
    const OVR                           , 1,    //6             0               Overrun flag
    const BSY                           , 1,    //7             0               Busy flag
    _reserved                           , 24);
  unsigned int DR;                              //              0x0000'0000     SPI data register
  unsigned int CRCPR;                           //              0x0000'0007     SPI CRC polynomial register (SPI_CRCPR) (not used in I2S mode)
  unsigned int const RXCRCR;                    //              0x0000'0000     SPI RX CRC register (SPI_RXCRCR) (not used in I2S mode)
  unsigned int const TXCRCR;                    //              0x0000'0000     SPI TX CRC register (SPI_TXCRCR) (not used in I2S mode)
  BUNION(I2SCFGR, unsigned int,                 //              0x0000'0000     SPI_I2S configuration register
    CHLEN                               , 1,    //0             0               Channel length (number of bits per audio channel)
    DATLEN                              , 2,    //1-2           0               Data length to be transferred
    CKPOL                               , 1,    //3             0               Steady state clock polarity
    I2SSTD                              , 2,    //4-5           0               I2S standard selection
    _reserved                           , 1,
    PCMSYNC                             , 1,    //7             0               PCM frame synchronization
    I2SCFG                              , 2,    //8-9           0               I2S configuration mode
    I2SE                                , 1,    //10            0               I2S Enable
    I2SMOD                              , 1,    //11            0               I2S mode selection
    _reserved1                          , 20);
  BUNION(I2SPR, unsigned int,                   //              0x0000'0010     SPI_I2S prescaler register
    I2SDIV                              , 8,    //0:7           0               I2S Linear prescaler
    ODD                                 , 1,    //8             0               Odd factor for the prescaler
    MCKOE                               , 1,    //9             0               Master clock output enable
    _reserved                           , 22);
} SPI_TypeDef;

typedef struct
{
  RSTRUCT(CR1, unsigned int,                    //              0x0000'0000     SPI control register 1 (not used in I2S mode)
    CPHA                                   ,    //0             0               Clock phase
    CPOL                                   ,    //1             0               Clock polarity
    MSTR                                   ,    //2             0               Master selection
    BR                                  [3],    //3:5           0               Baud rate control
    SPE                                    ,    //6             0               SPI enable
    LSBFIRST                               ,    //7             0               Frame format
    SSI                                    ,    //8             0               Internal slave select
    SSM                                    ,    //9             0               Software slave management
    RXONLY                                 ,    //10            0               Receive only
    DFF                                    ,    //11            0               Data frame format
    CRCNEXT                                ,    //12            0               CRC transfer next
    CRCEN                                  ,    //13            0               Hardware CRC calculation enable
    BIDIOE                                 ,    //14            0               Output enable in bidirectional mode
    BIDIMODE                               ,    //15            0               Bidirectional data mode enable
    _reserved                           [16]);
  RSTRUCT(CR2, unsigned int,                    //              0x0000'0000     SPI control register 2
    RXDMAEN                                ,    //0             0               Rx buffer DMA enable
    TXDMAEN                                ,    //1             0               Tx buffer DMA enable
    SSOE                                   ,    //2             0               SS output enable
    _reserved                           [2],
    ERRIE                                  ,    //5             0               Error interrupt enable
    RXNEIE                                 ,    //6             0               RX buffer not empty interrupt enable
    TXEIE                                  ,    //7             0               Tx buffer empty interrupt enable
    _reserved1                          [24]);
  RSTRUCT(SR, unsigned int,                     //              0x0000'0002     SPI status register
    const RXNE                             ,    //0             0               Receive buffer not empty
    const TXE                              ,    //1             1               Transmit buffer empty
    const CHSIDE                           ,    //2             0               Channel side
    const UDR                              ,    //3             0               Underrun flag
    CRCERR                                 ,    //4             0               CRC error flag
    const MODF                             ,    //5             0               Mode fault
    const OVR                              ,    //6             0               Overrun flag
    const BSY                              ,    //7             0               Busy flag
    _reserved                           [24]);
  unsigned int DR;                              //              0x0000'0000     SPI data register
  unsigned int CRCPR;                           //              0x0000'0007     SPI CRC polynomial register (SPI_CRCPR) (not used in I2S mode)
  unsigned int const RXCRCR;                    //              0x0000'0000     SPI RX CRC register (SPI_RXCRCR) (not used in I2S mode)
  unsigned int const TXCRCR;                    //              0x0000'0000     SPI TX CRC register (SPI_TXCRCR) (not used in I2S mode)
  RSTRUCT(I2SCFGR, unsigned int,                //              0x0000'0000     SPI_I2S configuration register
    CHLEN                                  ,    //0             0               Channel length (number of bits per audio channel)
    DATLEN                              [2],    //1-2           0               Data length to be transferred
    CKPOL                                  ,    //3             0               Steady state clock polarity
    I2SSTD                              [2],    //4-5           0               I2S standard selection
    _reserved                              ,
    PCMSYNC                                ,    //7             0               PCM frame synchronization
    I2SCFG                              [2],    //8-9           0               I2S configuration mode
    I2SE                                   ,    //10            0               I2S Enable
    I2SMOD                                 ,    //11            0               I2S mode selection
    _reserved1                          [20]);
  RSTRUCT(I2SPR, unsigned int,                  //              0x0000'0010     SPI_I2S prescaler register
    I2SDIV                              [8],    //0:7           0               I2S Linear prescaler
    ODD                                    ,    //8             0               Odd factor for the prescaler
    MCKOE                                  ,    //9             0               Master clock output enable
    _reserved                           [22]);
} SPI_BITBAND_TypeDef;
//==============================================================================================================================================================
//===========================================================       LEVEL 1      ===============================================================================
//==============================================================================================================================================================
typedef union
{
  unsigned int REG;
  struct
  {
    BUNION(Mode, unsigned short,
      Phase                             , 1,    //0             0
      Polarity                          , 1,    //1             0
      IsMaster                          , 1,    //2             1
      Baudrate_Div                      , 3,    //3:5           2               Baud rate = (F-SPI / (2^(Baudrate_Div + 1))) (MAX 18MHz)
      _reserved                         , 1,
      IsLowBitFirst                     , 1,    //7             0
      _reserved1                        , 3,
      IsFrame16Bit                      , 1,    //11            0
      _reserved2                        , 3,
      IsHalfDuplex                      , 1);   //15            0
    BUNION(DMA, unsigned char,
      Rx                                , 1,    //0             0
      Tx                                , 1,    //1             0
      _reserved                         , 6);
    BUNION(Interrupt, unsigned char,
      _reserved                         , 5,
      Error                             , 1,    //5             0
      Rx_NotEmpty                       , 1,    //6             0
      Tx_Empty                          , 1);   //7             0
  };
} SPIInit_TypeDef;
/*
+) EXAMPLE:
RCC_BITBAND.APB2_ENR.SPI1 = 1;
SPIInit_TypeDef SPIInit = (SPIInit_TypeDef){
  .Mode = {.BITS = {.Phase = 0, .Polarity = 0, .IsMaster = 1, .Baudrate_Div = 2, .IsLowBitFirst = 0, .IsFrame16Bit = 0, .IsHalfDuplex = 0, }, },  //F_SPI = F_BUS / 2 ^ (Baudrate_Div + 1) (MAX 18MHz)
  .DMA = {.BITS = {  .Rx = 0, .Tx = 0, }, }, 
  .Interrupt = {.BITS = {  .Error = 0, .Rx_NotEmpty = 0, .Tx_Empty = 0, }, }, 
};
SPI_Init(&SPI1, &SPIInit);
*/
void SPI_Init(volatile SPI_TypeDef* SPI, SPIInit_TypeDef* SPIInit);
//-----------------------------------------------------------       LEVEL 1      -------------------------------------------------------------------------------
#define SPI_Wait(SPI)   while((SPI)->SR.BITS.BSY)
//-----------------------------------------------------------       LEVEL 1      -------------------------------------------------------------------------------
void SPI_Write(volatile SPI_TypeDef* SPI, unsigned int Data);                   //Data: 16 or 8 bit
//-----------------------------------------------------------       LEVEL 1      -------------------------------------------------------------------------------
unsigned int SPI_Read(volatile SPI_TypeDef* SPI);                               //return: 16 or 8 bit
//-----------------------------------------------------------       LEVEL 1      -------------------------------------------------------------------------------
unsigned int SPI_WriteRead(volatile SPI_TypeDef* SPI, unsigned int Data);       //Data: 16 or 8 bit, return: 16 or 8 bit
//-----------------------------------------------------------       LEVEL 1      -------------------------------------------------------------------------------
void SPI_Writes(volatile SPI_TypeDef* SPI, void* Data, unsigned int Length);    //Length: 16 bit
//-----------------------------------------------------------       LEVEL 1      -------------------------------------------------------------------------------
/* Read fast
+) NOTE: pause spi bus (by interrupt, usb,...) maybe get wrong rx data
*/
void SPI_Reads(volatile SPI_TypeDef* SPI, void* Contain, unsigned int Length);  //Length: 16 bit
//-----------------------------------------------------------       LEVEL 1      -------------------------------------------------------------------------------
void SPI_WriteReads(volatile SPI_TypeDef* SPI, void* Contain, unsigned int Length);     //Length: 16 bit

#endif