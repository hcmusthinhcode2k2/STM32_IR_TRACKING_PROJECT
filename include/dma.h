#ifndef _DMA_H_
#define _DMA_H_

#include <common.h>
#include <define.h>
//                                      |       //Address       Default         Description
typedef struct
{
  BUNION(CCR, unsigned int,                     //              0x0000'0000     DMA channel x configuration register
    EN                                  , 1,    //0             0               Channel enable
    TCIE                                , 1,    //1             0               Transfer complete interrupt enable
    HTIE                                , 1,    //2             0               Half transfer interrupt enable
    TEIE                                , 1,    //3             0               Transfer error interrupt enable
    DIR                                 , 1,    //4             0               Data transfer direction
    CIRC                                , 1,    //5             0               Circular mode
    PINC                                , 1,    //6             0               Peripheral increment mode
    MINC                                , 1,    //7             0               Memory increment mode
    PSIZE                               , 2,    //8-9           0               Peripheral size
    MSIZE                               , 2,    //10-11         0               Memory size
    PL                                  , 2,    //12-13         0               Channel priority level
    MEM2MEM                             , 1,    //14            0               Memory to memory mode
    _reserved                           , 17);
  unsigned int CNDTR;                           //              0x0000'0000     DMA channel x number of data register
  unsigned int CPAR;                            //              0x0000'0000     DMA channel x peripheral address register
  unsigned int CMAR;                            //              0x0000'0000     DMA channel x memory address register
  unsigned int _reserved;
} DMAChannel_TypeDef;

typedef struct
{
  BUNION(ISR, unsigned int const,               //              0x0000'0000     DMA interrupt status register
    GIF1                                , 1,    //0             0               Channel x global interrupt flag
    TCIF1                               , 1,    //1             0               Channel x transfer complete flag
    HTIF1                               , 1,    //2             0               Channel x half transfer flag
    TEIF1                               , 1,    //3             0               Channel x transfer error flag
    GIF2                                , 1,    //4             0
    TCIF2                               , 1,    //5             0
    HTIF2                               , 1,    //6             0
    TEIF2                               , 1,    //7             0    
    GIF3                                , 1,    //8             0
    TCIF3                               , 1,    //9             0
    HTIF3                               , 1,    //10            0
    TEIF3                               , 1,    //11            0    
    GIF4                                , 1,    //12            0
    TCIF4                               , 1,    //13            0
    HTIF4                               , 1,    //14            0
    TEIF4                               , 1,    //15            0    
    GIF5                                , 1,    //16            0
    TCIF5                               , 1,    //17            0
    HTIF5                               , 1,    //18            0
    TEIF5                               , 1,    //19            0    
    GIF6                                , 1,    //20            0
    TCIF6                               , 1,    //21            0
    HTIF6                               , 1,    //22            0
    TEIF6                               , 1,    //23            0    
    GIF7                                , 1,    //24            0
    TCIF7                               , 1,    //25            0
    HTIF7                               , 1,    //26            0
    TEIF7                               , 1,    //27            0
    _reserved                           , 4);
  BUNION(IFCR, unsigned int,                    //              0x0000'0000     DMA interrupt flag clear register
    CGIF1                               , 1,    //0             0               Channel x global interrupt clear
    CTCIF1                              , 1,    //1             0               Channel x transfer complete clear
    CHTIF1                              , 1,    //2             0               Channel x half transfer clear
    CTEIF1                              , 1,    //3             0               Channel x transfer error clear
    CGIF2                               , 1,    //4             0
    CTCIF2                              , 1,    //5             0
    CHTIF2                              , 1,    //6             0
    CTEIF2                              , 1,    //7             0
    CGIF3                               , 1,    //8             0
    CTCIF3                              , 1,    //9             0
    CHTIF3                              , 1,    //10            0
    CTEIF3                              , 1,    //11            0
    CGIF4                               , 1,    //12            0
    CTCIF4                              , 1,    //13            0
    CHTIF4                              , 1,    //14            0
    CTEIF4                              , 1,    //15            0
    CGIF5                               , 1,    //16            0
    CTCIF5                              , 1,    //17            0
    CHTIF5                              , 1,    //18            0
    CTEIF5                              , 1,    //19            0
    CGIF6                               , 1,    //20            0
    CTCIF6                              , 1,    //21            0
    CHTIF6                              , 1,    //22            0
    CTEIF6                              , 1,    //23            0
    CGIF7                               , 1,    //24            0
    CTCIF7                              , 1,    //25            0
    CHTIF7                              , 1,    //26            0
    CTEIF7                              , 1,    //27            0
    _reserved                           , 4);
  DMAChannel_TypeDef Channel_1;
  DMAChannel_TypeDef Channel_2;
  DMAChannel_TypeDef Channel_3;
  DMAChannel_TypeDef Channel_4;
  DMAChannel_TypeDef Channel_5;
  DMAChannel_TypeDef Channel_6;
  DMAChannel_TypeDef Channel_7;  
} DMA_TypeDef;

typedef struct
{
  RSTRUCT(CCR, unsigned int,                    //              0x0000'0000     DMA channel x configuration register
    EN                                     ,    //0             0               Channel enable
    TCIE                                   ,    //1             0               Transfer complete interrupt enable
    HTIE                                   ,    //2             0               Half transfer interrupt enable
    TEIE                                   ,    //3             0               Transfer error interrupt enable
    DIR                                    ,    //4             0               Data transfer direction
    CIRC                                   ,    //5             0               Circular mode
    PINC                                   ,    //6             0               Peripheral increment mode
    MINC                                   ,    //7             0               Memory increment mode
    PSIZE                               [2],    //8-9           0               Peripheral size
    MSIZE                               [2],    //10-11         0               Memory size
    PL                                  [2],    //12-13         0               Channel priority level
    MEM2MEM                                ,    //14            0               Memory to memory mode
    _reserved                           [17]);
  unsigned int CNDTR[32];                       //              0               DMA channel x number of data register
  unsigned int CPAR[32];                        //              0               DMA channel x peripheral address register
  unsigned int CMAR[32];                        //              0               DMA channel x memory address register
  unsigned int _reserved[32];
} DMAChannel_BITBAND_TypeDef;

typedef struct
{
  RSTRUCT(ISR, unsigned int const,              //              0x0000'0000     DMA interrupt status register
    GIF1                                   ,    //0             0               Channel x global interrupt flag
    TCIF1                                  ,    //1             0               Channel x transfer complete flag
    HTIF1                                  ,    //2             0               Channel x half transfer flag
    TEIF1                                  ,    //3             0               Channel x transfer error flag
    GIF2                                   ,    //4             0
    TCIF2                                  ,    //5             0
    HTIF2                                  ,    //6             0
    TEIF2                                  ,    //7             0  
    GIF3                                   ,    //8             0
    TCIF3                                  ,    //9             0
    HTIF3                                  ,    //10            0
    TEIF3                                  ,    //11            0  
    GIF4                                   ,    //12            0
    TCIF4                                  ,    //13            0
    HTIF4                                  ,    //14            0
    TEIF4                                  ,    //15            0  
    GIF5                                   ,    //16            0
    TCIF5                                  ,    //17            0
    HTIF5                                  ,    //18            0
    TEIF5                                  ,    //19            0  
    GIF6                                   ,    //20            0
    TCIF6                                  ,    //21            0
    HTIF6                                  ,    //22            0
    TEIF6                                  ,    //23            0  
    GIF7                                   ,    //24            0
    TCIF7                                  ,    //25            0
    HTIF7                                  ,    //26            0
    TEIF7                                  ,    //27            0
    _reserved                           [4]);
  RSTRUCT(IFCR, unsigned int,                   //              0x0000'0000     DMA interrupt flag clear register
    CGIF1                                  ,    //0             0               Channel x global interrupt clear
    CTCIF1                                 ,    //1             0               Channel x transfer complete clear
    CHTIF1                                 ,    //2             0               Channel x half transfer clear
    CTEIF1                                 ,    //3             0               Channel x transfer error clear
    CGIF2                                  ,    //4             0
    CTCIF2                                 ,    //5             0
    CHTIF2                                 ,    //6             0
    CTEIF2                                 ,    //7             0  
    CGIF3                                  ,    //8             0
    CTCIF3                                 ,    //9             0
    CHTIF3                                 ,    //10            0
    CTEIF3                                 ,    //11            0  
    CGIF4                                  ,    //12            0
    CTCIF4                                 ,    //13            0
    CHTIF4                                 ,    //14            0
    CTEIF4                                 ,    //15            0  
    CGIF5                                  ,    //16            0
    CTCIF5                                 ,    //17            0
    CHTIF5                                 ,    //18            0
    CTEIF5                                 ,    //19            0  
    CGIF6                                  ,    //20            0
    CTCIF6                                 ,    //21            0
    CHTIF6                                 ,    //22            0
    CTEIF6                                 ,    //23            0  
    CGIF7                                  ,    //24            0
    CTCIF7                                 ,    //25            0
    CHTIF7                                 ,    //26            0
    CTEIF7                                 ,    //27            0
    _reserved                           [4]);
  DMAChannel_BITBAND_TypeDef Channel_1;
  DMAChannel_BITBAND_TypeDef Channel_2;
  DMAChannel_BITBAND_TypeDef Channel_3;
  DMAChannel_BITBAND_TypeDef Channel_4;
  DMAChannel_BITBAND_TypeDef Channel_5;
  DMAChannel_BITBAND_TypeDef Channel_6;
  DMAChannel_BITBAND_TypeDef Channel_7;  
} DMA_BITBAND_TypeDef;
//==============================================================================================================================================================
//========================================================       DMA1 request      =============================================================================
//==============================================================================================================================================================
#define DMA_ADC1                DMA1.Channel_1
#define DMA_TIM2_CH3            DMA1.Channel_1
#define DMA_TIM4_CH1            DMA1.Channel_1

#define DMA_SPI1_RX             DMA1.Channel_2
#define DMA_UART3_TX            DMA1.Channel_2
#define DMA_TIM1_CH1            DMA1.Channel_2
#define DMA_TIM2_UP             DMA1.Channel_2
#define DMA_TIM3_CH3            DMA1.Channel_2

#define DMA_SPI1_TX             DMA1.Channel_3
#define DMA_UART3_RX            DMA1.Channel_3
#define DMA_TIM3_CH4            DMA1.Channel_3
#define DMA_TIM3_UP             DMA1.Channel_3

#define DMA_SPI2_RX             DMA1.Channel_4
#define DMA_I2S2_RX             DMA1.Channel_4
#define DMA_UART1_TX            DMA1.Channel_4
#define DMA_I2C2_TX             DMA1.Channel_4
#define DMA_TIM1_CH4            DMA1.Channel_4
#define DMA_TIM1_TRIG           DMA1.Channel_4
#define DMA_TIM1_COM            DMA1.Channel_4
#define DMA_TIM4_CH2            DMA1.Channel_4

#define DMA_SPI2_TX             DMA1.Channel_5
#define DMA_I2S2_TX             DMA1.Channel_5
#define DMA_UART1_RX            DMA1.Channel_5
#define DMA_I2C2_RX             DMA1.Channel_5
#define DMA_TIM1_UP             DMA1.Channel_5
#define DMA_TIM2_CH1            DMA1.Channel_5
#define DMA_TIM4_CH3            DMA1.Channel_5

#define DMA_UART2_RX            DMA1.Channel_6
#define DMA_I2C1_TX             DMA1.Channel_6
#define DMA_TIM1_CH3            DMA1.Channel_6
#define DMA_TIM3_CH1            DMA1.Channel_6
#define DMA_TIM3_TRIG           DMA1.Channel_6

#define DMA_UART2_TX            DMA1.Channel_7
#define DMA_I2C1_RX             DMA1.Channel_7
#define DMA_TIM2_CH2            DMA1.Channel_7
#define DMA_TIM2_CH4            DMA1.Channel_7
#define DMA_TIM4_UP             DMA1.Channel_7
//==============================================================================================================================================================
//========================================================       DMA2 request      =============================================================================
//==============================================================================================================================================================
#define DMA_SPI3_RX             DMA2.Channel_1
#define DMA_I2S3_RX             DMA2.Channel_1
#define DMA_TIM5_CH4            DMA2.Channel_1
#define DMA_TIM5_TRIG           DMA2.Channel_1
#define DMA_TIM8_CH3            DMA2.Channel_1
#define DMA_TIM8_UP             DMA2.Channel_1

#define DMA_SPI3_TX             DMA2.Channel_2
#define DMA_I2S3_TX             DMA2.Channel_2
#define DMA_TIM5_CH3            DMA2.Channel_2
#define DMA_TIM5_UP             DMA2.Channel_2
#define DMA_TIM8_CH4            DMA2.Channel_2
#define DMA_TIM8_TRIG           DMA2.Channel_2
#define DMA_TIM8_COM            DMA2.Channel_2

#define DMA_UART4_RX            DMA2.Channel_3
#define DMA_TIM6_UP             DMA2.Channel_3
#define DMA_DAC_CN1             DMA2.Channel_3
#define DMA_TIM8_CH1            DMA2.Channel_3

#define DMA_SDIO                DMA2.Channel_4
#define DMA_TIM5_CH2            DMA2.Channel_4
#define DMA_TIM7_UP             DMA2.Channel_4
#define DMA_DAC_CN2             DMA2.Channel_4

#define DMA_ADC3                DMA2.Channel_5
#define DMA_UART4_TX            DMA2.Channel_5
#define DMA_TIM5_CH1            DMA2.Channel_5
#define DMA_TIM8_CH2            DMA2.Channel_5
//==============================================================================================================================================================
//===========================================================       LEVEL 1      ===============================================================================
//==============================================================================================================================================================
//                                      |       //Address       Default         Description
typedef struct
{
  BUNION(Mode, unsigned int,
    _reserved                           , 4,
    IsReadFromMem                       , 1,    //4             0
    IsCircleMode                        , 1,    //5             0
    Peri_IsIncrement                    , 1,    //6             0
    Mem_IsIncrement                     , 1,    //7             0
    Peri_Size                           , 2,    //8-9           0               (2 ^ Peri_Size) bytes
    Mem_Size                            , 2,    //10-11         0               (2 ^ Mem_Size) bytes
    PriorityLevel                       , 2,    //12-13         0
    IsMemToMem                          , 1,    //14            0
    _reserved1                          , 17);
  BUNION(Interrupt, unsigned int,
    _reserved                           , 1,
    Trans_Compelete                     , 1,    //0
    HalfTrans                           , 1,    //0
    Error                               , 1,    //0
    _reserved1                          , 28);
} DMAInit_TypeDef;
/*
+) EXAMPLE:
RCC_BITBAND.AHB_ENR.DMA1 = 1;
DMAInit_TypeDef DMAInit = (DMAInit_TypeDef){
  .Mode = {.BITS = { .IsReadFromMem = 0, .IsCircleMode = 0, .Peri_IsIncrement = 0, .Mem_IsIncrement = 0, .Peri_Size = 0, .Mem_Size = 0, .PriorityLevel = 0, .IsMemToMem = 0, },},  //size: 0: 1 byte / 1: 2 byte / 2: 4 byte
  .Interrupt = {.BITS = {.Trans_Compelete = 0, .HalfTrans = 0, .Error = 0, }, },
};
DMA_Init(&DMA_UART1_RX, &DMAInit);
*/
void DMA_Init(volatile DMAChannel_TypeDef* DMAChannel, const DMAInit_TypeDef* DMAInit);
//==============================================================================================================================================================
#define DMA_Wait(DMAChannel)    while((DMAChannel)->CNDTR)
//==============================================================================================================================================================
void DMA_Transfer(volatile DMAChannel_TypeDef* DMAChannel, volatile void* MemPointer, volatile void* PeriPointer, unsigned int Size);
//==============================================================================================================================================================

#endif