#ifndef _DBG_H_
#define _DBG_H_

#include <reg_define.h>

//                                      //Address       Default         Description
typedef struct
{
  UNION(IDCODE, const unsigned int,
        DEV_ID                  , 12,   //                              Device identifier
        _Reserved               , 4,
        REV_ID                  , 16);  //                              Revision identifier
  UNION(CR, unsigned int,               //              0x0000'0000     (POR Reset)
        DBG_SLEEP               , 1,    //              0               Debug Sleep mode
        DBG_STOP                , 1,    //              0               Debug Stop mode
        DBG_STANDBY             , 1,    //              0               Debug Standby mode
        _Reserved               , 2,
        TRACE_IOEN              , 1,    //              0               Trace pin assignment control
        TRACE_MODE              , 2,    //              0               ----------------------------
        DBG_IWDGSTOP            , 1,    //              0               Debug independent watchdog stopped when core is halted
        DBG_WWDG_STOP           , 1,    //              0               Debug window watchdog stopped when core is halted
        DBG_TIM1_STOP           , 1,    //              0               TIMx counter stopped when core is halted (x=4..1)
        DBG_TIM2_STOP           , 1,    //              0
        DBG_TIM3_STOP           , 1,    //              0
        DBG_TIM4_STOP           , 1,    //              0
        DBG_CAN1_STOP           , 1,    //              0               Debug CAN1 stopped when Core is halted
        DBG_I2C1_SMBUS_TIMEOUT  , 1,    //              0               SMBUS timeout mode stopped when Core is halted
        DBG_I2C2_SMBUS_TIMEOUT  , 1,    //              0               SMBUS timeout mode stopped when Core is halted
        DBG_TIM8_STOP           , 1,    //              0               TIMx counter stopped when core is halted (x=8..5)
        DBG_TIM5_STOP           , 1,    //              0
        DBG_TIM6_STOP           , 1,    //              0
        DBG_TIM7_STOP           , 1,    //              0
        DGB_CAN2_STOP           , 1,    //              0               Debug CAN2 stopped when core is halted
        _Reserved               , 3,
        DBG_TIM12_STOP          , 1,    //              0               TIMx counter stopped when core is halted (x=9..14)
        DBG_TIM13_STOP          , 1,    //              0
        DBG_TIM14_STOP          , 1,    //              0
        DBG_TIM9_STOP           , 1,    //              0
        DBG_TIM10_STOP          , 1,    //              0
        DBG_TIM11_STOP          , 1,    //              0
        _Reserved               , 1);
} DBG_TypeDef;

#endif