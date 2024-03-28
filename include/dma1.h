#ifndef _DMA_H_
#define _DMA_H_

typedef struct
{
  union
  {
    unsigned long REG;
    struct
    {
      unsigned long EN          : 1;
      unsigned long TCIE        : 1;
      unsigned long HTIE        : 1;
      unsigned long TEIE        : 1;      
      unsigned long DIR         : 1;      
      unsigned long CIRC        : 1;      
      unsigned long PINC        : 1;      
      unsigned long MINC        : 1;      
      unsigned long PSIZE       : 2;      
      unsigned long MSIZE       : 2;
      unsigned long PL          : 2;
      unsigned long MEM2MEM     : 1;
      unsigned long _reserved   : 17;
    } BITS;
  } CCR;
  unsigned long CNTR;                   //16 bit low is used
  unsigned long CPAR;
  unsigned long CMAR;
} DMAChannel_TypeDef;

typedef struct
{
  union
  {
    unsigned long REG;
    struct
    {
      unsigned long  GIF1       : 1;
      unsigned long TCIF1       : 1;
      unsigned long HTIF1       : 1;
      unsigned long TEIF1       : 1;
      unsigned long  GIF2       : 1;
      unsigned long TCIF2       : 1;
      unsigned long HTIF2       : 1;
      unsigned long TEIF2       : 1;      
      unsigned long  GIF3       : 1;
      unsigned long TCIF3       : 1;
      unsigned long HTIF3       : 1;
      unsigned long TEIF3       : 1;      
      unsigned long  GIF4       : 1;
      unsigned long TCIF4       : 1;
      unsigned long HTIF4       : 1;
      unsigned long TEIF4       : 1;      
      unsigned long  GIF5       : 1;
      unsigned long TCIF5       : 1;
      unsigned long HTIF5       : 1;
      unsigned long TEIF5       : 1;      
      unsigned long  GIF6       : 1;
      unsigned long TCIF6       : 1;
      unsigned long HTIF6       : 1;
      unsigned long TEIF6       : 1;      
      unsigned long  GIF7       : 1;
      unsigned long TCIF7       : 1;
      unsigned long HTIF7       : 1;
      unsigned long TEIF7       : 1;
      unsigned long _reserved   : 4;
    } BITS;
  } ISR, IFCR;
  DMAChannel_TypeDef Channel_1, 
  Channel_2, Channel_3, Channel_4, Channel_5,
  Channel_6, Channel_7;
} DMA_TypeDef;

#define DMA1            (*((DMA_TypeDef*)0x40020000))

#define DMA_ADC1        DMA1.Channel_1
#define DMA_TIM2_CH3    DMA1.Channel_1
#define DMA_TIM4_CH1    DMA1.Channel_1

//.....

#endif