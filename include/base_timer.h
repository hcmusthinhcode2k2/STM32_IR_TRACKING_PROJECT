#ifndef _BASE_TIMER_H_
#define _BASE_TIMER_H_

#include <common.h>
#include <define.h>
//                                      |       //Address       Default         Description
//==============================================================================================================================================================
//===========================================================       LEVEL 1      ===============================================================================
//==============================================================================================================================================================
/*
+) NOTE:
  -NVIC must enable
  -IRQ function must clear flag
*/
#define BASE_TIMER_EnableInterrupt(TIMER)       ((BASIC_TIMER_TypeDef*)(TIMER))->DIER.REG |= BIT0
#define BASE_TIMER_DisableInterrupt(TIMER)      ((BASIC_TIMER_TypeDef*)(TIMER))->DIER.REG &= ~BIT0
//==============================================================================================================================================================
#define BASE_TIMER_EnableDMA(TIMER)             ((BASIC_TIMER_TypeDef*)(TIMER))->DIER.REG |= BIT8
#define BASE_TIMER_DisableDMA(TIMER)            ((BASIC_TIMER_TypeDef*)(TIMER))->DIER.REG &= ~BIT8
//==============================================================================================================================================================
/*
+) Timer overflow:
    ((Prescale + 1) / F_TIMER) * (ReloadValue + 1) (ms) //F_TIMER: KHz
+) Using for all timer
*/
void BASE_TIMER_Init(volatile void* TIMER, unsigned int Prescale, unsigned int ReloadValue);                            //Prescale & ReloadValue: 16 bit
//==============================================================================================================================================================
/*
+) NOTE:
  -GPIO as OUTPUT_AF_PUSHPULL
  -AFIO to remap channel pin
  -Except basic timer
  -if (Channel & BIT6) -> Channel
  -if (Channel & BIT7) -> ChannelN
*/
void BASE_TIMER_GeneratePWM(volatile void* TIMER, unsigned int Channel, unsigned int Duty, unsigned int IDLE_IsHigh);   //Channel: 8 bit; Duty: 16 bit
//==============================================================================================================================================================

#endif