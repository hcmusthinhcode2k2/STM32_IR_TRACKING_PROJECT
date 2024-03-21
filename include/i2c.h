#ifndef _I2C_H_
#define _I2C_H_

#include <common.h>
#include <define.h>
//                                      |       //Address       Default         Description
typedef struct
{
  BUNION(CR1, unsigned int,                     //              0x0000'0000     I2C Control register 1
    PE                                  , 1,    //0             0               Peripheral enable
    SMBUS                               , 1,    //1             0               SMBus mode
    _reserved                           , 1,
    SMBTYPE                             , 1,    //3             0               SMBus type
    ENARP                               , 1,    //4             0               ARP enable
    ENPEC                               , 1,    //5             0               PEC enable
    ENGC                                , 1,    //6             0               General call enable
    NOSTRETCH                           , 1,    //7             0               Clock stretching disable (Slave mode)
    START                               , 1,    //8             0               Start generation
    STOP                                , 1,    //9             0               Stop generation
    ACK                                 , 1,    //10            0               Acknowledge enable
    POS                                 , 1,    //11            0               Acknowledge/PEC Position (for data reception)
    PEC                                 , 1,    //12            0               Packet error checking
    ALERT                               , 1,    //13            0               SMBus alert
    _reserved1                          , 1,
    SWRST                               , 1,    //15            0               Software reset
    _reserved2                          , 16);
  BUNION(CR2, unsigned int,                     //              0x0000'00000    I2C Control register 2
    FREQ                                , 6,    //0:5           0               Peripheral clock frequency
    _reserved                           , 2,
    ITERREN                             , 1,    //8             0               Error interrupt enable
    ITEVTEN                             , 1,    //9             0               Event interrupt enable
    ITBUFEN                             , 1,    //10            0               Buffer interrupt enable
    DMAEN                               , 1,    //11            0               DMA requests enable
    LAST                                , 1,    //12            0               DMA last transfer
    _reserved1                          , 19);
  BUNION(OAR1, unsigned int,                    //              0x0000'0000     I2C Own address register 1
    ADD1                                , 10,   //0:9           0
    _reserved                           , 5,
    ADDMODE                             , 1,    //15            0               Addressing mode (slave mode)
    _reserved1                          , 16);
  BUNION(OAR2, unsigned int,                    //              0x0000'0000     I2C Own address register 2
    ENDUAL                              , 1,    //0             0               Dual addressing mode enable
    ADD2                                , 7,    //1:7           0               Interface address
    _reserved                           , 24);
  unsigned int DR;                              //              0x0000'0000     I2C Data register
  BUNION(SR1, unsigned int,                     //              0x0000'0000     I2C Status register 1
    const SB                            , 1,    //0             0               Start bit (Master mode)
    const ADDR                          , 1,    //1             0               Address sent (master mode)/matched (slave mode)
    const BTF                           , 1,    //2             0               Byte transfer finished
    const ADD10                         , 1,    //3             0               10-bit header sent (Master mode)
    const STOPF                         , 1,    //4             0               Stop detection (slave mode)
    _reserved                           , 1,
    const RxNE                          , 1,    //6             0               Data register not empty (receivers)
    const TxE                           , 1,    //7             0               Data register empty (transmitters)
    BERR                                , 1,    //8             0               Bus error
    ARLO                                , 1,    //9             0               Arbitration lost (master mode)
    AF                                  , 1,    //10            0               Acknowledge failure
    OVR                                 , 1,    //11            0               Overrun/Underrun
    PECERR                              , 1,    //12            0               PEC Error in reception
    _reserved1                          , 1,
    TIMEOUT                             , 1,    //14            0               Timeout or Tlow error
    SMBALERT                            , 1,    //15            0               SMBus alert
    _reserved2                          , 16);
  BUNION(SR2, const unsigned int,               //              0x0000'0000
    MSL                                 , 1,    //0             0               Master/slave
    BUSY                                , 1,    //1             0               Bus busy
    TRA                                 , 1,    //2             0               Transmitter/receiver
    _reserved                           , 1,
    GENCALL                             , 1,    //4             0               General call address (Slave mode)
    SMBDEFAULT                          , 1,    //5             0               SMBus device default address (Slave mode)
    SMBHOST                             , 1,    //6             0               SMBus host header (Slave mode)
    DUALF                               , 1,    //7             0               Dual flag (Slave mode)
    PEC                                 , 8,    //8:15          0               Packet error checking register
    _reserved1                          , 16);
  BUNION(CCR, unsigned int,                     //              0x0000'0000     I2C Clock control register
    CCR                                 , 12,   //0:11          0               Clock control register in Fm/Sm mode (Master mode)
    _reserved                           , 2,
    DUTY                                , 1,    //14            0               Fm mode duty cycle
    FS                                  , 1,    //15            0               I2C master mode selection
    _reserved1                          , 16);
  unsigned int TRISE;                           //              0x0000'0002     Maximum rise time in Fm/Sm mode
} I2C_TypeDef;

typedef struct
{
  RSTRUCT(CR1, unsigned int,                    //              0x0000'0000     I2C Control register 1
    PE                                     ,    //0             0               Peripheral enable
    SMBUS                                  ,    //1             0               SMBus mode
    _reserved                              ,
    SMBTYPE                                ,    //3             0               SMBus type
    ENARP                                  ,    //4             0               ARP enable
    ENPEC                                  ,    //5             0               PEC enable
    ENGC                                   ,    //6             0               General call enable
    NOSTRETCH                              ,    //7             0               Clock stretching disable (Slave mode)
    START                                  ,    //8             0               Start generation
    STOP                                   ,    //9             0               Stop generation
    ACK                                    ,    //10            0               Acknowledge enable
    POS                                    ,    //11            0               Acknowledge/PEC Position (for data reception)
    PEC                                    ,    //12            0               Packet error checking
    ALERT                                  ,    //13            0               SMBus alert
    _reserved1                             ,
    SWRST                                  ,    //15            0               Software reset
    _reserved2                          [16]);
  RSTRUCT(CR2, unsigned int,                    //              0x0000'00000    I2C Control register 2
    FREQ                                [6],    //0:5           0               Peripheral clock frequency
    _reserved                           [2],
    ITERREN                                ,    //8             0               Error interrupt enable
    ITEVTEN                                ,    //9             0               Event interrupt enable
    ITBUFEN                                ,    //10            0               Buffer interrupt enable
    DMAEN                                  ,    //11            0               DMA requests enable
    LAST                                   ,    //12            0               DMA last transfer
    _reserved1                          [19]);
  RSTRUCT(OAR1, unsigned int,                   //              0x0000'0000     I2C Own address register 1
    ADD1                                [10],   //0:9           0
    _reserved                           [5],
    ADDMODE                                ,    //15            0               Addressing mode (slave mode)
    _reserved1                          [16]);
  RSTRUCT(OAR2, unsigned int,                   //              0x0000'0000     I2C Own address register 2
    ENDUAL                                 ,    //0             0               Dual addressing mode enable
    ADD2                                [7],    //1:7           0               Interface address
    _reserved                           [24]);
  unsigned int DR[32];                          //              0x0000'0000     I2C Data register
  RSTRUCT(SR1, unsigned int,                    //              0x0000'0000     I2C Status register 1
    const SB                               ,    //0             0               Start bit (Master mode)
    const ADDR                             ,    //1             0               Address sent (master mode)/matched (slave mode)
    const BTF                              ,    //2             0               Byte transfer finished
    const ADD10                            ,    //3             0               10-bit header sent (Master mode)
    const STOPF                            ,    //4             0               Stop detection (slave mode)
    _reserved                              ,
    const RxNE                             ,    //6             0               Data register not empty (receivers)
    const TxE                              ,    //7             0               Data register empty (transmitters)
    BERR                                   ,    //8             0               Bus error
    ARLO                                   ,    //9             0               Arbitration lost (master mode)
    AF                                     ,    //10            0               Acknowledge failure
    OVR                                    ,    //11            0               Overrun/Underrun
    PECERR                                 ,    //12            0               PEC Error in reception
    _reserved1                             ,
    TIMEOUT                                ,    //14            0               Timeout or Tlow error
    SMBALERT                               ,    //15            0               SMBus alert
    _reserved2                          [16]);
  RSTRUCT(SR2, const unsigned int,              //              0x0000'0000
    MSL                                    ,    //0             0               Master/slave
    BUSY                                   ,    //1             0               Bus busy
    TRA                                    ,    //2             0               Transmitter/receiver
    _reserved                              ,
    GENCALL                                ,    //4             0               General call address (Slave mode)
    SMBDEFAULT                             ,    //5             0               SMBus device default address (Slave mode)
    SMBHOST                                ,    //6             0               SMBus host header (Slave mode)
    DUALF                                  ,    //7             0               Dual flag (Slave mode)
    PEC                                 [8],    //8:15          0               Packet error checking register
    _reserved1                          [16]);
  RSTRUCT(CCR, unsigned int,                    //              0x0000'0000     I2C Clock control register
    CCR                                 [12],   //0:11          0               Clock control register in Fm/Sm mode (Master mode)
    _reserved                           [2],
    DUTY                                   ,    //14            0               Fm mode duty cycle
    FS                                     ,    //15            0               I2C master mode selection
    _reserved1                          [16]);
  unsigned int TRISE[32];                       //              0x0000'0002     Maximum rise time in Fm/Sm mode
} I2C_BITBAND_TypeDef;
//====================================================================================================================================================
//====================================================================================================================================================
//====================================================================================================================================================
typedef struct
{
  BUNION(Mode, unsigned int,
    _reserved                           , 5,
    PacketErrorCheckEnable              , 1,
    GenCallEnable                       , 1,
    _reserved1                          , 4,
    DMAEnable                           , 1,
    
    _reserved2                          , 20);
  
} I2CInit_TypeDef;
void I2C_Init(volatile I2C_TypeDef* I2C, unsigned int EdgeTime);
//====================================================================================================================================================
typedef union
{
  unsigned char SlaveAddress;
  unsigned char DataAddress;
  unsigned short Size;
  const unsigned char* Data;
} I2CTask_TypeDef;
void I2C_Perform(I2CTask_TypeDef* I2CTask);     //if (I2CTask->SlaveAddress & 1) => read task


#endif