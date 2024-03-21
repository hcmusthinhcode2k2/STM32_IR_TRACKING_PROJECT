#ifndef _CORTEX_M3_H_
#define _CORTEX_M3_H_

#include <common.h>
#include <define.h>
//==============================================================================================================================================================
//==================================================                 Using Functions            ================================================================
//==============================================================================================================================================================
void STK_Init(unsigned int Load);               //IRQ trigger = Load * 1000 / FSYS (us), FSYS KHz
//==============================================================================================================================================================
//============================================================        System timer         =====================================================================
//==============================================================================================================================================================
//                                      |       //Address       Default         Description
typedef struct
{
  BUNION(CTRL, unsigned int,                    //              0x0000'0000     SysTick control and status register
    ENABLE                              , 1,    //0             0               Counter enable
    TICK_INT                            , 1,    //1             0               SysTick exception request enable
    CLK_SOURCE                          , 1,    //2             0               Clock source selection (0: AHB/8, 1: AHB)
    _reserved                           , 13,
    COUNT_FLAG                          , 1,    //16            0               Returns 1 if timer counted to 0 since last time this was read
    _reserved1                          , 15);
  unsigned int LOAD;                            //              0x0000'0000     SysTick reload value register
  unsigned int VALUE;                           //              0x0000'0000     SysTick current value register
  unsigned int const CALIB;                     //              0x0000'0000     SysTick calibration value register
} STK_TypeDef;
__root __no_init volatile STK_TypeDef STK       __at(0xE000E010);
//==============================================================================================================================================================
//==================================================                  System control block        ==============================================================
//==============================================================================================================================================================
//                                      |       //Address       Default         Description
typedef struct
{
  BUNION(CPUID, unsigned int const,             //              0x411F'C231     CPUID base register (STM32F2 and STM32L series: 0x412F'C230)
    REVISION                            , 4,    //0:3              
    PART_NO                             , 12,   //4:15          0xC23
    CONST                               , 4,    //16:19         0xF
    VARIANT                             , 4,    //20:23              
    IMPLEMENTER                         , 8);   //24:31         0x41
  BUNION(ICSR, unsigned int,                    //              0x0000'0000     Interrupt control and state register       
    VECT_ACTIVE                         , 9,    //0:8           0               Active vector
    _reserved                           , 2,
    const RET_BASE                      , 1,    //12            0               Return to base level
    const VECT_PENDING                  , 10,   //13:22         0               Pending vector
    const ISR_PENDING                   , 1,    //23            0               Interrupt pending flag, excluding NMI and Faults
    _reserved1                          , 2,
    PEND_ST_CLR                         , 1,    //26            0               SysTick exception clear-pending bit
    PEND_ST_SET                         , 1,    //27            0               SysTick exception set-pending bit
    PEND_SV_CLR                         , 1,    //28            0               PendSV clear-pending bit
    PEND_SV_SET                         , 1,    //29            0               PendSV set-pending bit
    _reserved2                          , 1,
    NMI_PEND_SET                        , 1);   //31            0               NMI set-pending bit
  BUNION(VTOR, unsigned int,                    //              0x0000'0000     Vector table offset register
    _reserved                           , 9,
    TABLEOFF                            , 21,   //9:29          0               Vector table base offset field
    _reserved1                          , 2);
  BUNION(AIRCR, unsigned int,                   //              0xFA05'0000     Application interrupt and reset control register               
    VECT_RESET                          , 1,    //0             0               Reserved for Debug use
    VECT_CLR_ACTIVE                     , 1,    //1             0               Reserved for Debug use
    SYS_RESET_REQ                       , 1,    //2             0               System reset request
    _reserved                           , 5,
    PRI_GROUP                           , 3,    //8:10          0               Interrupt priority grouping field
    _reserved1                          , 4,
    const ENDIANESS                     , 1,    //15            0               Data endianness bit
    VECT_KEY                            , 16);  //              0xFA05          Register key (write 0x5FA to VECTKEY to write this reg)
  BUNION(SCR, unsigned int,                     //              0x0000'0000     System control register
    _reserved                           , 1,
    SLEEP_ON_EXIT                       , 1,    //1             0               Configures sleep-on-exit when returning from Handler mode to Thread mode
    SLEEP_DEEP                          , 1,    //2             0               Controls whether the processor uses sleep or deep sleep as its low power mode
    _reserved1                          , 1,
    S_EV_ON_PEND                        , 1,    //4             0               Send Event on Pending bit
    _reserved2                          , 27);
  BUNION(CCR, unsigned int,                     //              0x0000'0000     Configuration and control register ((STM32F2 and STM32L series: 0x0000'0200)
    NON_BASE_THRD_EN                    , 1,    //0             0               Configures how the processor enters Thread mode
    USE_RSETM_PEND                      , 1,    //1             0               Enables unprivileged software access to the STIR
    _reserved                           , 1,
    UNALIGN_TRP                         , 1,    //3             0               Enables unaligned access traps
    DIV_0_TRP                           , 1,    //4             0               Enables faulting or halting when the processor executes an SDIV or UDIV instruction with a divisor of 0
    _reserved1                          , 3,
    BFHF_NMI_GN                         , 1,    //8             0               Enables handlers with priority -1 or -2 to ignore data bus faults caused by load and store instructions
    STK_ALIGN                           , 1,    //9             0               Configures stack alignment on exception entry
    _reserved2                          , 22);
  union
  {
    RSTRUCT(REGS, unsigned int, r1, r2, r3);
    BSTRUCT(BITS, unsigned int,
      MEM_FAULT                         , 8,    //0:7           0
      BUS_FAULT                         , 8,    //8:15          0
      USAGE_FAULT                       , 8,    //16:23         0
      _reserved                         , 8,
      _reserved1                        , 24,
      SV_CALL                           , 8,    //24:31         0
      _reserved2                        , 16,
      PEND_SV                           , 8,    //16:23         0
      SYS_TICK                          , 8);   //24:31         0
  } SHPR;                                       //              0x0000'0000-3   System handler priority registers
  BUNION(SHCRS, unsigned int,                   //              0x0000'0000     System handler control and state register
    MEM_FAULT_ACT                       , 1,    //0             0
    BUS_FAULT_ACT                       , 1,    //1             0
    _reserved                           , 1,
    USG_FAULT_ACT                       , 1,    //3             0
    _reserved1                          , 3,
    SV_CALL_ACT                         , 1,    //7             0
    MONITOR_ACT                         , 1,    //8             0
    _reserved2                          , 1,
    PENDSV_ACT                          , 1,    //10            0
    SYS_TICK_ACT                        , 1,    //11            0               SysTick exception active bit, reads as 1 if exception is active
    USG_FAULT_PENDED                    , 1,    //12            0
    MEM_FAULT_PENDED                    , 1,    //13            0
    BUS_FAULT_PENDED                    , 1,    //14            0
    SV_CALL_PENDED                      , 1,    //15            0               SVC call pending bit, reads as 1 if exception is pending
    MEM_FAULT_ENA                       , 1,    //16            0
    BUS_FAULT_ENA                       , 1,    //17            0
    USG_FAULT_ENA                       , 1,    //18            0               Usage fault enable bit, set to 1 to enable
    _reserved3                          , 13);
  union
  {
    unsigned int REG;
    struct
    {
      BUNION(MMFSR, unsigned char,              //              0x00            Memory Management Fault Status Register
        IACC_VIOL                       , 1,    //0             0               Instruction access violation flag
        DACC_VIOL                       , 1,    //1             0               Data access violation flag
        _reserved                       , 1,
        MUNSTK_ERR                      , 1,    //3             0               Memory manager fault on unstacking for a return from exception
        MSTK_ERR                        , 1,    //4             0               Memory manager fault on stacking for exception entry
        _reserved1                      , 2,
        MMAR_VALID                      , 1);   //7             0               Memory Management Fault Address Register (MMAR) valid flag
      BUNION(BFSR, unsigned char,               //              0x00            Bus Fault Status Register
        IBUS_ERR                        , 1,    //0             0               Instruction bus error
        PRECIS_ERR                      , 1,    //1             0               Precise data bus error
        IMPRECIS_ERR                    , 1,    //2             0               Imprecise data bus error
        UNSTK_ERR                       , 1,    //3             0               Bus fault on unstacking for a return from exception
        STK_ERR                         , 1,    //4             0               Bus fault on stacking for exception entry
        _reserved                       , 2,
        BFAR_VALID                      , 1);   //7             0               Bus Fault Address Register (BFAR) valid flag
      BUNION(UFSR, unsigned short,              //              0x0000          Usage Fault Status Register
        UNDEF_INSTR                     , 1,    //0             0               Undefined instruction usage fault
        INV_STATE                       , 1,    //1             0               Invalid state usage fault
        INV_PC                          , 1,    //2             0               Invalid PC load usage fault, caused by an invalid PC load by EXC_RETURN
        NOCP                            , 1,    //3             0               No coprocessor usage fault. The processor does not support coprocessor instructions
        _reserved                       , 4,
        UN_ALIGNED                      , 1,    //8             0               Unaligned access usage fault
        DIV_BY_ZERO                     , 1,    //9             0               Divide by zero usage fault
        _reserved1                      , 6);
    };
  } CFSR;                                       //              0x0000'0000     Configurable fault status register
  BUNION(HFSR, unsigned int,                    //              0x0000'0000     Hard fault status register
    _reserved                           , 1,
    VECT_TBL                            , 1,    //1             0               Vector table hard fault
    _reserved1                          , 28,
    FORCED                              , 1,    //30            0               Forced hard fault
    DEBUG_VT                            , 1);   //31            0               Reserved for Debug use
  unsigned int MMFAR;                           //              0x----'----     Memory management fault address register
  unsigned int BFAR;                            //              0x----'----     Bus fault address register
} SCB_TypeDef;
#define SCB                                     NVIC.SCB_MASK
__root __no_init volatile
BUNION(SCB_ACTLR, unsigned int,                 //              0x0000'0000     Auxiliary control register
  DIS_MCYC_INT                          , 1,    //0             0               Disables folding of IT instructions
  DIS_DEFWBUF                           , 1,    //1             0               Disables write buffer use during default memory map accesses
  DIS_FOLD                              , 1,    //2             0               Disables interrupt of multi-cycle instructions
  _reserved                             , 29)   __at(0xE000E008);
//==============================================================================================================================================================
//=======================================================           Nested vectored interrupt controller          ==============================================
//==============================================================================================================================================================
//                                      |       //Address       Default         Description
#define NVIC_BSTRUCT(size)\
struct\
{\
  BSTRUCT( , unsigned int,\
          WWDG                          ,size,  /*0             0               Window WatchDog Interrupt                                       */\
          PVD                           ,size,  /*1             0               PVD through EXTI Line detection Interrupt                       */\
          TAMPER                        ,size,  /*2             0               Tamper Interrupt                                                */\
          RTC                           ,size,  /*3             0               RTC global Interrupt                                            */\
          FLASH                         ,size,  /*4             0               FLASH global Interrupt                                          */\
          RCC                           ,size,  /*5             0               RCC global Interrupt                                            */\
          EXTI0                         ,size,  /*6             0               EXTI Line0 Interrupt                                            */\
          EXTI1                         ,size,  /*7             0               EXTI Line1 Interrupt                                            */\
          EXTI2                         ,size,  /*8             0               EXTI Line2 Interrupt                                            */\
          EXTI3                         ,size,  /*9             0               EXTI Line3 Interrupt                                            */\
          EXTI4                         ,size,  /*10            0               EXTI Line4 Interrupt                                            */\
          DMA1_CN1                      ,size,  /*11            0               DMA1 Channel 1 global Interrupt                                 */\
          DMA1_CN2                      ,size,  /*12            0               DMA1 Channel 2 global Interrupt                                 */\
          DMA1_CN3                      ,size,  /*13            0               DMA1 Channel 3 global Interrupt                                 */\
          DMA1_CN4                      ,size,  /*14            0               DMA1 Channel 4 global Interrupt                                 */\
          DMA1_CN5                      ,size,  /*15            0               DMA1 Channel 5 global Interrupt                                 */\
          DMA1_CN6                      ,size,  /*16            0               DMA1 Channel 6 global Interrupt                                 */\
          DMA1_CN7                      ,size,  /*17            0               DMA1 Channel 7 global Interrupt                                 */\
          ADC_1_2                       ,size,  /*18            0               ADC1 and ADC2 global Interrupt                                  */\
          USB_HP_CAN1_TX                ,size,  /*19            0               USB Device High Priority or CAN1 TX Interrupts                  */\
          USB_LP_CAN1_RX0               ,size,  /*20            0               USB Device Low Priority or CAN1 RX0 Interrupts                  */\
          CAN1_RX1                      ,size,  /*21            0               CAN1 RX1 Interrupt                                              */\
          CAN1_SCE                      ,size,  /*22            0               CAN1 SCE Interrupt                                              */\
          EXTI_9_5                      ,size,  /*23            0               External Line[9:5] Interrupts                                   */\
          TIM1_BRK                      ,size,  /*24            0               TIM1 Break Interrupt                                            */\
          TIM1_UP                       ,size,  /*25            0               TIM1 Update Interrupt                                           */\
          TIM1_TRG_COM                  ,size,  /*26            0               TIM1 Trigger and Commutation Interrupt                          */\
          TIM1_CC                       ,size,  /*27            0               TIM1 Capture Compare Interrupt                                  */\
          TIM2                          ,size,  /*28            0               TIM2 global Interrupt                                           */\
          TIM3                          ,size,  /*29            0               TIM3 global Interrupt                                           */\
          TIM4                          ,size,  /*30            0               TIM4 global Interrupt                                           */\
          I2C1_EV                       ,size); /*31            0               I2C1 Event Interrupt                                            */\
  BSTRUCT( , unsigned int,\
          I2C1_ER                       ,size,  /*32            0               I2C1 Error Interrupt                                            */\
          I2C2_EV                       ,size,  /*33            0               I2C2 Event Interrupt                                            */\
          I2C2_ER                       ,size,  /*34            0               I2C2 Error Interrupt                                            */\
          SPI1                          ,size,  /*35            0               SPI1 global Interrupt                                           */\
          SPI2                          ,size,  /*36            0               SPI2 global Interrupt                                           */\
          UART1                         ,size,  /*37            0               USART1 global Interrupt                                         */\
          UART2                         ,size,  /*38            0               USART2 global Interrupt                                         */\
          UART3                         ,size,  /*39            0               USART3 global Interrupt                                         */\
          EXTI_15_10                    ,size,  /*40            0               External Line[15:10] Interrupts                                 */\
          RTC_ALARM                     ,size,  /*41            0               RTC Alarm through EXTI Line Interrupt                           */\
          USB_WAKEUP                    ,size,  /*42            0               USB Device WakeUp from suspend through EXTI Line Interrupt      */\
          TIM8_BRK_TIM12                ,size,  /*43            0               TIM8 Break interrupt and TIM12 global interrupt                 */\
          TIM8_UP_TIM13                 ,size,  /*44            0               TIM8 Update interrupt and TIM13 global interrupt                */\
          TIM8_TRG_COM_TIM14            ,size,  /*45            0               TIM8 Trigger and Commutation interrupts and TIM14 global interrupt*/\
          TIM8_CC                       ,size,  /*46            0               TIM8 Capture Compare interrupt                                  */\
          ADC3                          ,size,  /*47            0               ADC3 global interrupt                                           */\
          FSMC                          ,size,  /*48            0               FSMC global interrupt                                           */\
          SDIO                          ,size,  /*49            0               SDIO global interrupt                                           */\
          TIM5                          ,size,  /*50            0               TIM5 global interrupt                                           */\
          SPI3                          ,size,  /*51            0               SPI3 global interrupt                                           */\
          UART4                         ,size,  /*52            0               UART4 global interrupt                                          */\
          UART5                         ,size,  /*53            0               UART5 global interrupt                                          */\
          TIM6                          ,size,  /*54            0               TIM6 global interrupt                                           */\
          TIM7                          ,size,  /*55            0               TIM7 global interrupt                                           */\
          DMA2_CN_1                     ,size,  /*56            0               DMA2 Channel1 global interrupt                                  */\
          DMA2_CN_2                     ,size,  /*57            0               DMA2 Channel2 global interrupt                                  */\
          DMA2_CN_3                     ,size,  /*58            0               DMA2 Channel3 global interrupt                                  */\
          DMA2_CN4_5                    ,size,  /*59            0               DMA2 Channel4 and DMA2 Channel5 global interrupts (NOTE)        */\
          DMA2_CN5                      ,size,  /*60            0               DMA2 Channel5 global interrupt                                  */\
          ETH                           ,size,  /*61            0               Ethernet global interrupt                                       */\
          ETH_WKUP                      ,size,  /*62            0               Ethernet Wakeup through EXTI line interrupt                     */\
          CAN2_TX                       ,size); /*63            0               CAN2 TX interrupts                                              */\
  BSTRUCT( , unsigned int,\
          CAN2_RX0                      ,size,  /*64            0               CAN2 RX0 interrupts                                             */\
          CAN2_RX1                      ,size,  /*65            0               CAN2 RX1 interrupt                                              */\
          CAN2_SCE                      ,size,  /*66            0               CAN2 SCE interrupt                                              */\
          OTG_FS                        ,size); /*67            0               USB On The Go FS global interrupt                               */\
} BITS
typedef struct
{
  union
  {
    RSTRUCT(REGS, unsigned int, r0, r1, r2);
    NVIC_BSTRUCT(1);
  } ISER;                                       //                              Interrupt set-enable registers
  unsigned int _reserved[29];
  union
  {
    RSTRUCT(REGS, unsigned int, r0, r1, r2);
    NVIC_BSTRUCT(1);
  } ICER;                                       //                              Interrupt clear-enable registers
  unsigned int _reserved1[29];
  union
  {
    RSTRUCT(REGS, unsigned int, r0, r1, r2);
    NVIC_BSTRUCT(1);
  } ISPR;                                       //                              Interrupt set-pending registers
  unsigned int _reserved2[29];
  union
  {
    RSTRUCT(REGS, unsigned int, r0, r1, r2);
    NVIC_BSTRUCT(1);
  } ICPR;                                       //                              Interrupt clear-pending registers
  unsigned int _reserved3[29];
  union
  {
    RSTRUCT(REGS, unsigned int const, r0, r1, r2);
    NVIC_BSTRUCT(1);
  } IABR;                                       //                              Interrupt active bit registers
  unsigned int _reserved4[61];
  union
  {
    xRSTRUCT(REGS, unsigned int, r, 0, 20,);
    NVIC_BSTRUCT(8);
  } IPR;  
  unsigned int _reserved5[555];
  SCB_TypeDef SCB_MASK;                         //0xE000ED00
  unsigned int _reserved6[114];
  unsigned int STIR;                            //              0x0000'0000     Software trigger interrupt register
} NVIC_TypeDef;
__root __no_init volatile NVIC_TypeDef NVIC     __at(0xE000E100);
//==============================================================================================================================================================
//==================================================           Memory protection unit           ================================================================
//==============================================================================================================================================================
//                                      |       //Address       Default         Description
typedef struct
{
  BUNION(TYPER, unsigned int const,             //              0x0000'0800     MPU type register
    SEPARATE                            , 1,    //0             0               Separate flag
    _reserved                           , 8,
    DREGION                             , 7,    //9:15          4               Number of MPU data regions
    IREGION                             , 8,    //16:23         0               Number of MPU instruction regions
    _reserved1                          , 8);
  BUNION(CR, unsigned int,                      //              0x0000'0000     MPU control register
    ENABLE                              , 1,    //0             0               Enables the MPU
    HFNMIENA                            , 1,    //1             0               Enables the operation of MPU during hard fault, NMI, and FAULTMASK handlers
    PRIVDEFEN                           , 1,    //2             0               Enable privileged software access to default memory map
    _reserved                           , 29);
  unsigned int REGION;                          //              0x0000'0000     MPU region number register
  STRUCT(A[4],
    BUNION(RBAR, unsigned int,                  //              0x0000'0000     MPU region base address register
      REGION                            , 4,    //0:3           0               MPU region field
      VALID                             , 1,    //4             0               MPU region number valid
      ADDR                              , 27);  //5:31          0               Region base address field
    BUNION(RASR, unsigned int,                  //              0x0000'0000     MPU region attribute and size register
      ENABLE                            , 1,    //0             0               Region enable bit
      SIZE                              , 5,    //1:5           0               Size of the MPU protection region
      _reserved                         , 2,
      SRD                               , 8,    //8:15          0               Subregion disable bits
      B                                 , 1,    //16            0               
      C                                 , 1,    //17            0               
      S                                 , 1,    //18            0               Shareable memory attribute
      TEX                               , 3,    //19:21         0               memory attribute
      _reserved1                        , 2,
      AP                                , 3,    //24:26         0               Access permission
      _reserved2                        , 1,
      XN                                , 1,    //28            0               Instruction access disable bit
      _reserved3                        , 3););
} MPU_TypeDef;
__no_init volatile MPU_TypeDef MPU                      __at(0xE000ED90);
//==============================================================================================================================================================
//==================================================                   CPU Registers            ================================================================
//==============================================================================================================================================================
typedef struct
{ //0xFFFF'FFFF9
  unsigned int R0;
  unsigned int R1;
  unsigned int R2;
  unsigned int R3;
  unsigned int R12;
  unsigned int LR;
  unsigned int PC;
  unsigned int EAPSR;
  
  unsigned int R4;
  unsigned int R5;
  unsigned int R6;
  unsigned int R7;
  unsigned int R8;
  unsigned int R9;
  unsigned int R10;
  unsigned int R11;
  unsigned int SP;
} CPU_TypeDef;

#endif