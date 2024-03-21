#ifndef _EXTI_H_
#define _EXTI_H_

#include <common.h>
#include <define.h>
//                                      |       //Address       Default         Description
typedef
BUNION(EXTIName_TypeDef, unsigned int,
  PIN0                                  , 1,    //0
  PIN1                                  , 1,    //1
  PIN2                                  , 1,    //2
  PIN3                                  , 1,    //3
  PIN4                                  , 1,    //4
  PIN5                                  , 1,    //5
  PIN6                                  , 1,    //6
  PIN7                                  , 1,    //7
  PIN8                                  , 1,    //8
  PIN9                                  , 1,    //9
  PIN10                                 , 1,    //10
  PIN11                                 , 1,    //11
  PIN12                                 , 1,    //12
  PIN13                                 , 1,    //13
  PIN14                                 , 1,    //14
  PIN15                                 , 1,    //15
  PVD                                   , 1,    //16
  RTC_ALARM                             , 1,    //17
  USB_WEAKUP                            , 1,    //18
  ETHERNET_WEAKUP                       , 1,    //19
  _Reserved                             , 12);
typedef struct
{
  EXTIName_TypeDef IMR;                         //              0x0000'0000     Interrupt mask register
  EXTIName_TypeDef EMR;                         //              0x0000'0000     Event mask register
  EXTIName_TypeDef RTSR;                        //              0x0000'0000     Rising trigger selection register
  EXTIName_TypeDef FTSR;                        //              0x0000'0000     Falling trigger selection register
  EXTIName_TypeDef SWIER;                       //              0x0000'0000     Software interrupt event register
  EXTIName_TypeDef PR;                          //              0x----'----     Pending register
} EXTI_TypeDef;

typedef
RSTRUCT(EXTIName_BITBAND_TypeDef, unsigned int,
  PIN0                                     ,    //0
  PIN1                                     ,    //1
  PIN2                                     ,    //2
  PIN3                                     ,    //3
  PIN4                                     ,    //4
  PIN5                                     ,    //5
  PIN6                                     ,    //6
  PIN7                                     ,    //7
  PIN8                                     ,    //8
  PIN9                                     ,    //9
  PIN10                                    ,    //10
  PIN11                                    ,    //11
  PIN12                                    ,    //12
  PIN13                                    ,    //13
  PIN14                                    ,    //14
  PIN15                                    ,    //15
  PVD                                      ,    //16
  RTC_ALARM                                ,    //17
  USB_WEAKUP                               ,    //18
  ETHERNET_WEAKUP                          ,    //19
  _Reserved                             [12]);
typedef struct
{
  EXTIName_BITBAND_TypeDef IMR;                 //              0x0000'0000     Interrupt mask register
  EXTIName_BITBAND_TypeDef EMR;                 //              0x0000'0000     Event mask register
  EXTIName_BITBAND_TypeDef RTSR;                //              0x0000'0000     Rising trigger selection register
  EXTIName_BITBAND_TypeDef FTSR;                //              0x0000'0000     Falling trigger selection register
  EXTIName_BITBAND_TypeDef SWIER;               //              0x0000'0000     Software interrupt event register
  EXTIName_BITBAND_TypeDef PR;                  //              0x----'----     Pending register
} EXTI_BITBAND_TypeDef;
//==============================================================================================================================================================
//===========================================================       LEVEL 1      ===============================================================================
//==============================================================================================================================================================
typedef enum
{
  EXTI_MODE_RISING      = 0x01UL,
  EXTI_MODE_FALLING     = 0x02UL,
} EXTI_MODE;
void EXTI_Interrupt(volatile EXTI_TypeDef* EXTI, EXTIName_TypeDef InterruptMask, EXTI_MODE Mode);
//==============================================================================================================================================================
void EXTI_WeakupEvent(volatile EXTI_TypeDef* EXTI, EXTIName_TypeDef WeakupEventMask, EXTI_MODE Mode);

#endif