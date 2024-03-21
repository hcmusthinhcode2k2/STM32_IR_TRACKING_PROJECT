#ifndef _UART_H_
#define _UART_H_

#include <common.h>
#include <define.h>
//                                      |       //Address       Default         Description
typedef struct
{
  BUNION(SR, unsigned long,                      //              0x0000'00C0     Status register
    const PE                            , 1,    //0             0               Parity error
    const FE                            , 1,    //1             0               Framing error
    const NE                            , 1,    //2             0               Noise error flag
    const ORE                           , 1,    //3             0               Overrun error
    const IDLE                          , 1,    //4             0               IDLE line detected
    RXNE                                , 1,    //5             0               Read data register not empty
    TC                                  , 1,    //6             1               Transmission complete
    const TXE                           , 1,    //7             1               Transmit data register empty
    LBD                                 , 1,    //8             0               LIN break detection flag
    CTS                                 , 1,    //9             0               CTS flag
    _Reserved                           , 22);
  unsigned long DR;                              //              0x----'----     Data register (9 bits low is used)
  BUNION(BRR, unsigned long,                     //              0x0000'0000     Baud rate register
    FRACTION                            , 4,    //0:3           0
    MANTISSA                            , 12,   //4:15          0               Baudrate = F/(MANTISSA + FRACTION / 16)
    _Reserved                           , 16);
  BUNION(CR1, unsigned long,                     //              0x0000'0000     Control register 1
    SBK                                 , 1,    //0             0               Send break
    RWU                                 , 1,    //1             0               Receiver wakeup
    RE                                  , 1,    //2             0               Receiver enable
    TE                                  , 1,    //3             0               Transmitter enable
    IDLEIE                              , 1,    //4             0               IDLE longerrupt enable
    RXNEIE                              , 1,    //5             0               RXNE longerrupt enable
    TCIE                                , 1,    //6             0               Transmission complete longerrupt enable
    TXEIE                               , 1,    //7             0               TXE longerrupt enable
    PEIE                                , 1,    //8             0               PE longerrupt enable
    PS                                  , 1,    //9             0               Parity selection
    PCE                                 , 1,    //10            0               Parity control enable
    WAKE                                , 1,    //11            0               Wakeup method
    M                                   , 1,    //12            0               Word length
    UE                                  , 1,    //13            0               USART enable
    _Reserved                           , 18);
  BUNION(CR2, unsigned long,                     //              0x0000'0000     Control register 2
    ADD                                 , 4,    //0:3          	0               Address of the USART node
    _Reserved                           , 1,
    LBDL                                , 1,    //5           	0               lin break detection length
    LBDIE                               , 1,    //6           	0               LIN break detection longerrupt enable
    _Reserved1                          , 1,     
    LBCL                                , 1,    //8           	0               Last bit clock pulse
    CPHA                                , 1,    //9           	0               Clock phase
    CPOL                                , 1,    //10           	0               Clock polarity
    CLKEN                               , 1,    //11           	0               Clock enable
    STOP                                , 2,    //12-13			0               STOP bits
    LINEN                               , 1,    //14         	0               LIN mode enable
    _Reserved2                          , 17);
  BUNION(CR3, unsigned long,                     //              0x0000'0000     Control register 3
    EIE                                 , 1,    //0          	0               Error longerrupt enable
    IREN                                , 1,    //1          	0               IrDA mode enable
    IRLP                                , 1,    //2          	0               IrDA low-power
    HDSEL                               , 1,    //3          	0               Half-duplex selection
    NACK                                , 1,    //4          	0               Smartcard NACK enable
    SCEN                                , 1,    //5          	0               Smartcard mode enable
    DMAR                                , 1,    //6          	0               DMA enable receive
    DMAT                                , 1,    //7          	0               DMA enable transmitter
    RTSE                                , 1,    //8          	0               RTS enable
    CTSE                                , 1,    //9          	0               CTS enable
    CTSIE                               , 1,    //10            0               CTS longerrupt enable
    _reserved, 21);
  BUNION(GTPR, unsigned long,                    //              0x0000'0000     Guard time and prescaler register
    PSC                                 , 8,    //0:7        	0               Prescaler value
    GT                                  , 8,    //8:15         	0               Guard time value
    _reserved                           , 16);
} UART_TypeDef;

typedef struct
{
  RSTRUCT(SR, unsigned long,                     //              0x0000'00C0     Status register
    const PE                               ,    //0             0               Parity error
    const FE                               ,    //1             0               Framing error
    const NE                               ,    //2             0               Noise error flag
    const ORE                              ,    //3             0               Overrun error
    const IDLE                             ,    //4             0               IDLE line detected
    RXNE                                   ,    //5             0               Read data register not empty
    TC                                     ,    //6             1               Transmission complete
    const TXE                              ,    //7             1               Transmit data register empty
    LBD                                    ,    //8             0               LIN break detection flag
    CTS                                    ,    //9             0               CTS flag
    _Reserved                           [22]);
  unsigned long DR;                              //              0x----'----     Data register (9 bits low is used)
  RSTRUCT(BRR, unsigned long,                    //              0x0000'0000     Baud rate register
    FRACTION                            [4],    //0:3           0
    MANTISSA                            [12],   //4:15          0               Baudrate = F/(MANTISSA + FRACTION / 16)
    _Reserved                           [16]);
  RSTRUCT(CR1, unsigned long,                    //              0x0000'0000     Control register 1
    SBK                                    ,    //0             0               Send break
    RWU                                    ,    //1             0               Receiver wakeup
    RE                                     ,    //2             0               Receiver enable
    TE                                     ,    //3             0               Transmitter enable
    IDLEIE                                 ,    //4             0               IDLE longerrupt enable
    RXNEIE                                 ,    //5             0               RXNE longerrupt enable
    TCIE                                   ,    //6             0               Transmission complete longerrupt enable
    TXEIE                                  ,    //7             0               TXE longerrupt enable
    PEIE                                   ,    //8             0               PE longerrupt enable
    PS                                     ,    //9             0               Parity selection
    PCE                                    ,    //10            0               Parity control enable
    WAKE                                   ,    //11            0               Wakeup method
    M                                      ,    //12            0               Word length
    UE                                     ,    //13            0               USART enable
    _Reserved                           [18]);
  RSTRUCT(CR2, unsigned long,                    //              0x0000'0000     Control register 2
    ADD                                 [4],    //0:3          	0               Address of the USART node
    _Reserved                              ,
    LBDL                                   ,    //5           	0               lin break detection length
    LBDIE                                  ,    //6           	0               LIN break detection longerrupt enable
    _Reserved1                             ,     
    LBCL                                   ,    //8           	0               Last bit clock pulse
    CPHA                                   ,    //9           	0               Clock phase
    CPOL                                   ,    //10           	0               Clock polarity
    CLKEN                                  ,    //11           	0               Clock enable
    STOP                                [2],    //12-13			0               STOP bits
    LINEN                                  ,    //14         	0               LIN mode enable
    _Reserved2                          [17]);
  RSTRUCT(CR3, unsigned long,                    //              0x0000'0000     Control register 3
    EIE                                    ,    //0          	0               Error longerrupt enable
    IREN                                   ,    //1          	0               IrDA mode enable
    IRLP                                   ,    //2          	0               IrDA low-power
    HDSEL                                  ,    //3          	0               Half-duplex selection
    NACK                                   ,    //4          	0               Smartcard NACK enable
    SCEN                                   ,    //5          	0               Smartcard mode enable
    DMAR                                   ,    //6          	0               DMA enable receive
    DMAT                                   ,    //7          	0               DMA enable transmitter
    RTSE                                   ,    //8          	0               RTS enable
    CTSE                                   ,    //9          	0               CTS enable
    CTSIE                                  ,    //10            0               CTS longerrupt enable
    _reserved                           [21]);
  RSTRUCT(GTPR, unsigned long,                   //              0x0000'0000     Guard time and prescaler register
    PSC                                 [8],    //0:7        	0               Prescaler value
    GT                                  [8],    //8:15         	0               Guard time value
    _reserved                           [16]);
} UART_BITBAND_TypeDef;
//==============================================================================================================================================================
//===========================================================       LEVEL 1      ===============================================================================
//==============================================================================================================================================================
#define UART_EnableDMA_TX(UART)                 ((UART_TypeDef*)(UART))->CR3.BITS.DMAT = 1
#define UART_DisableDMA_TX(UART)                ((UART_TypeDef*)(UART))->CR3.BITS.DMAT = 0
#define UART_EnableDMA_RX(UART)                 ((UART_TypeDef*)(UART))->CR3.BITS.DMAR = 1
#define UART_DisableDMA_RX(UART)                ((UART_TypeDef*)(UART))->CR3.BITS.DMAR = 0
//-----------------------------------------------------------       LEVEL 1      -------------------------------------------------------------------------------
/*
+) NOTE:
  -NVIC must enable
  -IRQ function must clear flag
*/
#define UART_EnableIT_RX(UART)                  ((UART_TypeDef*)(UART))->CR1.REG |= BIT5
#define UART_DisableIT_RX(UART)                 ((UART_TypeDef*)(UART))->CR1.REG &= ~BIT5
//-----------------------------------------------------------       LEVEL 1      -------------------------------------------------------------------------------
void UART_Init(volatile UART_TypeDef* UART, unsigned long F_UART, unsigned long Baudrate);        //F_UART: KHz, Baudrate: bit / second
//-----------------------------------------------------------       LEVEL 1      -------------------------------------------------------------------------------
#define UART_WriteByte(UART, Data)              (UART)->DR = Data; while (!((UART)->SR.BITS.TXE))
//-----------------------------------------------------------       LEVEL 1      -------------------------------------------------------------------------------
void UART_WriteBytes(volatile UART_TypeDef* UART, const unsigned char* Data, unsigned long Length);
//-----------------------------------------------------------       LEVEL 1      -------------------------------------------------------------------------------
#define UART_IsReceived(UART_RX, TimeOut)       Serial_IsReceived((UART_RX), TimeOut)

#endif