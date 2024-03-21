#ifndef _USB_H_
#define _USB_H_

#include <USBP.h>
#include <define.h>
//                                      |       //Address       Default         Description
typedef struct
{
  RSTRUCT(TX, unsigned short,
    ADDR[2],
    COUNT[2]);
  struct
  {
    unsigned short ADDR[2];
    BUNION(COUNT[2], unsigned short,
      VALUE                             , 10,
      NUM_BLOCK                         , 5,
      BLSIZE                            , 1);
  } RX;
} USBEndpoint_ADDR_TypeDef;
//                                      |       //Address       Default         Description
typedef struct
{
  BUNION(Endpoint[8], unsigned int,             //              0x0000'0000     USB endpoint n register
    EA                                  , 4,    //0:3           0               Endpoint address
    STAT_TX                             , 2,    //4:5           0               Status bits, for transmission transfers
    DTOG_TX                             , 1,    //6             0               Data Toggle, for transmission transfers
    CTR_TX                              , 1,    //7             0               Correct Transfer for transmission
    EP_KIND                             , 1,    //8             0               Endpoint kind
    EP_TYPE                             , 2,    //9:10          0               Endpoint type
    const SETUP                         , 1,    //11            0               Setup transaction completed
    STAT_RX                             , 2,    //12:13         0               Status bits, for reception transfers
    DTOG_RX                             , 1,    //14            0               Data Toggle, for reception transfers
    CTR_RX                              , 1,    //15            0               Correct Transfer for reception
    _reserved                           , 16);
  unsigned int _reserved[8];
  BUNION(CNTR, unsigned int,                    //              0x0000'0003     USB control register
    FRES                                , 1,    //0             1               Force USB Reset
    PDWN                                , 1,    //1             1               Power down
    LPMODE                              , 1,    //2             0               Low-power mode
    FSUSP                               , 1,    //3             0               Force suspend
    RESUME                              , 1,    //4             0               Resume request
    _reserved                           , 3,    
    ESOFM                               , 1,    //8             0               Expected start of frame interrupt mask
    SOFM                                , 1,    //9             0               Start of frame interrupt mask
    RESETM                              , 1,    //10            0               USB reset interrupt mask
    SUSPM                               , 1,    //11            0               Suspend mode interrupt mask
    WKUPM                               , 1,    //12            0               Wakeup interrupt mask
    ERRM                                , 1,    //13            0               Error interrupt mask
    PMAOVRM                             , 1,    //14            0               Packet memory area over / underrun interrupt mask
    CTRM                                , 1,    //15            0               Correct transfer interrupt mask
    _reserved1                          , 16);
  BUNION(ISTR, unsigned int,                    //              0x0000'0000     USB interrupt status register
    const EP_ID                         , 4,    //0:3           0               Endpoint Identifier
    const DIR                           , 1,    //4             0               Direction of transaction
    _reserved                           , 3,
    ESOF                                , 1,    //8             0               Expected start of frame
    SOF                                 , 1,    //9             0               Start of frame
    RESET                               , 1,    //10            0               USB reset request
    SUSP                                , 1,    //11            0               Suspend mode request
    WKUP                                , 1,    //12            0               Wakeup
    ERR                                 , 1,    //13            0               Error
    PMAOVR                              , 1,    //14            0               Packet memory area over / underrun
    const CTR                           , 1,    //15            0               Correct transfer
    _reserved1                          , 16);
  BUNION(FNR, const unsigned int,               //              0x0000'0---     USB frame number register
    FN                                  , 11,   //0:10                          Frame number
    LSOF                                , 2,    //11-12         0               Lost SOF
    LCK                                 , 1,    //13            0               Locked
    RXDM                                , 1,    //14            0               Receive data - line status
    RXDP                                , 1,    //15            0               Receive data + line status 
    _reserved                           , 16);
  BUNION(DADDR, unsigned int,                   //              0x0000'0000     USB device address
    ADD                                 , 7,    //0:6           0               Device address
    EF                                  , 1,    //7             0               Enable function
    _reserved                           , 24);
  unsigned int BTABLE;                          //              0x0000'0000     Buffer table address (bit 15->3 is used)
} USB_TypeDef;

typedef struct
{
  RSTRUCT(Endpoint[8], unsigned int,            //              0x0000'0000     USB endpoint n register
    EA                                  [4],    //0:3           0               Endpoint address
    STAT_TX                             [2],    //4:5           0               Status bits, for transmission transfers
    DTOG_TX                                ,    //6             0               Data Toggle, for transmission transfers
    CTR_TX                                 ,    //7             0               Correct Transfer for transmission
    EP_KIND                                ,    //8             0               Endpoint kind
    EP_TYPE                             [2],    //9:10          0               Endpoint type
    const SETUP                            ,    //11            0               Setup transaction completed
    STAT_RX                             [2],    //12:13         0               Status bits, for reception transfers
    DTOG_RX                                ,    //14            0               Data Toggle, for reception transfers
    CTR_RX                                 ,    //15            0               Correct Transfer for reception
    _reserved                           [16]);
  unsigned int _reserved[8][32];
  RSTRUCT(CNTR, unsigned int,                   //              0x0000'0003     USB control register
    FRES                                   ,    //0             1               Force USB Reset
    PDWN                                   ,    //1             1               Power down
    LPMODE                                 ,    //2             0               Low-power mode
    FSUSP                                  ,    //3             0               Force suspend
    RESUME                                 ,    //4             0               Resume request
    _reserved                           [3],    
    ESOFM                                  ,    //8             0               Expected start of frame interrupt mask
    SOFM                                   ,    //9             0               Start of frame interrupt mask
    RESETM                                 ,    //10            0               USB reset interrupt mask
    SUSPM                                  ,    //11            0               Suspend mode interrupt mask
    WKUPM                                  ,    //12            0               Wakeup interrupt mask
    ERRM                                   ,    //13            0               Error interrupt mask
    PMAOVRM                                ,    //14            0               Packet memory area over / underrun interrupt mask
    CTRM                                   ,    //15            0               Correct transfer interrupt mask
    _reserved1                          [16]);
  RSTRUCT(ISTR, unsigned int,                   //              0x0000'0000     USB interrupt status register
    const EP_ID                         [4],    //0:3           0               Endpoint Identifier
    const DIR                              ,    //4             0               Direction of transaction
    _reserved                           [3],
    ESOF                                   ,    //8             0               Expected start of frame
    SOF                                    ,    //9             0               Start of frame
    RESET                                  ,    //10            0               USB reset request
    SUSP                                   ,    //11            0               Suspend mode request
    WKUP                                   ,    //12            0               Wakeup
    ERR                                    ,    //13            0               Error
    PMAOVR                                 ,    //14            0               Packet memory area over / underrun
    const CTR                              ,    //15            0               Correct transfer
    _reserved1                          [16]);
  RSTRUCT(FNR, const unsigned int,              //              0x0000'0---     USB frame number register
    FN                                  [11],   //0:10                          Frame number
    LSOF                                [2],    //11-12         0               Lost SOF
    LCK                                    ,    //13            0               Locked
    RXDM                                   ,    //14            0               Receive data - line status
    RXDP                                   ,    //15            0               Receive data + line status 
    _reserved                           [16]);
  RSTRUCT(DADDR, unsigned int,                  //              0x0000'0000     USB device address
    ADD                                 [7],    //0:6           0               Device address
    EF                                     ,    //7             0               Enable function
    _reserved                           [24]);
  unsigned int BTABLE[32];                      //              0x0000'0000     Buffer table address (bit 15->3 is used)
} USB_BITBAND_TypeDef;


/*
+) NOTE:
  -Address >= number_of_used_endpoint * 8
+) Example:
  -Endpoint 0 has -TX_Address = 12 => Buffer TX used by USB hardware register at (0x40006000 + 12 * 2)
                  -RX_Address = 97 => Buffer RX used by USB hardware register at (0x40006000 + 97 * 2)
*/
typedef struct
{
  unsigned short TX;
  unsigned short RX;  
} USBEndpointAddress_TypeDef;

/*
+) NOTE:
  -Turn on USB Clock and config as 48MHz before init
  -Turn on USB USB_LP_CAN1_RX0_IRQ after init and turn on system irq by "asm(CPSIE I)"
+) Example:
RCC_BITBAND.APB1ENR.USBEN = 1;
const USBEndpointAddress_TypeDef USBEndpointAddress[2] = {
  (USBEndpointAddress_TypeDef){.TX = 16, .RX = 16 + 64},
  (USBEndpointAddress_TypeDef){.TX = 16 + 128, .RX = 16 + 192},
};
USB_Init(&USB, USBEndpointAddress);
NVIC.ISER.BITS.USB_LP_CAN1_RX0 = 1;
asm("CPSIE I");
*/
extern volatile USB_TypeDef USB;
extern volatile USB_BITBAND_TypeDef USB_BITBAND;

void USB_Init(const USBEndpointAddress_TypeDef* USBEndPointAddress);
//void USB_OpenEndpointByIndex(reg8 EndpointIndex, USBEndpoint_TypeDef Value);
//void USB_ConfigEndpointByIndex(reg8 EndpointIndex, USBEndpoint_TypeDef NewValue);
//void USB_Send(reg8 EnpointIndex, const unsigned char __gptr* Data, reg16 Length);


#endif