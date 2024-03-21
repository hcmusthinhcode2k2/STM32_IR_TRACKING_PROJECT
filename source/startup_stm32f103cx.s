        MODULE  ?cstartup

        ;; Forward declaration of sections.
        SECTION CSTACK:DATA:NOROOT(3)

        SECTION .intvec:CODE:NOROOT(2)
//        EXTERN  RCC
//        EXTERN  SystemInit
        EXTERN  __iar_program_start
        EXTERN  main        
        PUBLIC  __vector_table

        DATA
__vector_table
        DCD     sfe(CSTACK)
        DCD     Reset_Handler                   ; Reset Handler
        DCD     NMI_Handler                     ; NMI Handler
        DCD     HardFault_Handler               ; Hard Fault Handler
        DCD     MemManage_Handler               ; MPU Fault Handler
        DCD     BusFault_Handler                ; Bus Fault Handler
        DCD     UsageFault_Handler              ; Usage Fault Handler
        DCD     0                               ; Reserved
        DCD     0                               ; Reserved
        DCD     0                               ; Reserved
        DCD     0                               ; Reserved
        DCD     SVC_Handler                     ; SVCall Handler
        DCD     DebugMon_Handler                ; Debug Monitor Handler
        DCD     0                               ; Reserved
        DCD     PendSV_Handler                  ; PendSV Handler
        DCD     SysTick_Handler                 ; SysTick Handler

         ; External Interrupts
        DCD     WWDG_IRQHandler                 ; Window Watchdog
        DCD     PVD_IRQHandler                  ; PVD through EXTI Line detect
        DCD     TAMPER_IRQHandler               ; Tamper
        DCD     RTC_IRQHandler                  ; RTC
        DCD     FLASH_IRQHandler                ; Flash
        DCD     RCC_IRQHandler                  ; RCC
        DCD     EXTI0_IRQHandler                ; EXTI Line 0
        DCD     EXTI1_IRQHandler                ; EXTI Line 1
        DCD     EXTI2_IRQHandler                ; EXTI Line 2
        DCD     EXTI3_IRQHandler                ; EXTI Line 3
        DCD     EXTI4_IRQHandler                ; EXTI Line 4
        DCD     DMA1_CN1_IRQHandler             ; DMA1 Channel 1
        DCD     DMA1_CN2_IRQHandler             ; DMA1 Channel 2
        DCD     DMA1_CN3_IRQHandler             ; DMA1 Channel 3
        DCD     DMA1_CN4_IRQHandler             ; DMA1 Channel 4
        DCD     DMA1_CN5_IRQHandler             ; DMA1 Channel 5
        DCD     DMA1_CN6_IRQHandler             ; DMA1 Channel 6
        DCD     DMA1_CN7_IRQHandler             ; DMA1 Channel 7
        DCD     ADC1_2_IRQHandler               ; ADC1 & ADC2
        DCD     USB_HP_CAN1_TX_IRQHandler       ; USB High Priority or CAN1 TX
        DCD     USB_LP_CAN1_RX0_IRQHandler      ; USB Low  Priority or CAN1 RX0
        DCD     CAN1_RX1_IRQHandler             ; CAN1 RX1
        DCD     CAN1_SCE_IRQHandler             ; CAN1 SCE
        DCD     EXTI9_5_IRQHandler              ; EXTI Line 9..5
        DCD     TIM1_BRK_IRQHandler             ; TIM1 Break
        DCD     TIM1_UP_IRQHandler              ; TIM1 Update
        DCD     TIM1_TRG_COM_IRQHandler         ; TIM1 Trigger and Commutation
        DCD     TIM1_CC_IRQHandler              ; TIM1 Capture Compare
        DCD     TIM2_IRQHandler                 ; TIM2
        DCD     TIM3_IRQHandler                 ; TIM3
        DCD     TIM4_IRQHandler                 ; TIM4
        DCD     I2C1_EV_IRQHandler              ; I2C1 Event
        DCD     I2C1_ER_IRQHandler              ; I2C1 Error
        DCD     I2C2_EV_IRQHandler              ; I2C2 Event
        DCD     I2C2_ER_IRQHandler              ; I2C2 Error
        DCD     SPI1_IRQHandler                 ; SPI1
        DCD     SPI2_IRQHandler                 ; SPI2
        DCD     UART1_IRQHandler                ; USART1
        DCD     UART2_IRQHandler                ; USART2
        DCD     UART3_IRQHandler                ; USART3
        DCD     EXTI15_10_IRQHandler            ; EXTI Line 15..10
        DCD     RTC_Alarm_IRQHandler             ; RTC Alarm through EXTI Line
        DCD     USBWakeUp_IRQHandler            ; USB Wakeup from suspend

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Default interrupt handlers.
;;
        THUMB

        PUBWEAK Reset_Handler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reset_Handler
//        LDR     R0, =RCC
//        LDR     R1, =SystemInit
//        BLX     R1
        LDR     R0, =__iar_program_start
        BX      R0
        
        PUBWEAK NMI_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
NMI_Handler
        B NMI_Handler

        PUBWEAK HardFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
HardFault_Handler
        B HardFault_Handler

        PUBWEAK MemManage_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
MemManage_Handler
        B MemManage_Handler

        PUBWEAK BusFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
BusFault_Handler
        B BusFault_Handler

        PUBWEAK UsageFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
UsageFault_Handler
        B UsageFault_Handler

        PUBWEAK SVC_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SVC_Handler
        B SVC_Handler

        PUBWEAK DebugMon_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
DebugMon_Handler
        B DebugMon_Handler

        PUBWEAK PendSV_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
PendSV_Handler
        B PendSV_Handler

        PUBWEAK SysTick_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SysTick_Handler
        B SysTick_Handler

        PUBWEAK WWDG_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
WWDG_IRQHandler
        B WWDG_IRQHandler

        PUBWEAK PVD_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
PVD_IRQHandler
        B PVD_IRQHandler

        PUBWEAK TAMPER_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TAMPER_IRQHandler
        B TAMPER_IRQHandler

        PUBWEAK RTC_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
RTC_IRQHandler
        B RTC_IRQHandler

        PUBWEAK FLASH_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
FLASH_IRQHandler
        B FLASH_IRQHandler

        PUBWEAK RCC_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
RCC_IRQHandler
        B RCC_IRQHandler

        PUBWEAK EXTI0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI0_IRQHandler
        B EXTI0_IRQHandler

        PUBWEAK EXTI1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI1_IRQHandler
        B EXTI1_IRQHandler

        PUBWEAK EXTI2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI2_IRQHandler
        B EXTI2_IRQHandler

        PUBWEAK EXTI3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI3_IRQHandler
        B EXTI3_IRQHandler

        PUBWEAK EXTI4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI4_IRQHandler
        B EXTI4_IRQHandler

        PUBWEAK DMA1_CN1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA1_CN1_IRQHandler
        B DMA1_CN1_IRQHandler

        PUBWEAK DMA1_CN2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA1_CN2_IRQHandler
        B DMA1_CN2_IRQHandler

        PUBWEAK DMA1_CN3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA1_CN3_IRQHandler
        B DMA1_CN3_IRQHandler

        PUBWEAK DMA1_CN4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA1_CN4_IRQHandler
        B DMA1_CN4_IRQHandler

        PUBWEAK DMA1_CN5_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA1_CN5_IRQHandler
        B DMA1_CN5_IRQHandler

        PUBWEAK DMA1_CN6_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA1_CN6_IRQHandler
        B DMA1_CN6_IRQHandler

        PUBWEAK DMA1_CN7_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
DMA1_CN7_IRQHandler
        B DMA1_CN7_IRQHandler

        PUBWEAK ADC1_2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
ADC1_2_IRQHandler
        B ADC1_2_IRQHandler

        PUBWEAK USB_HP_CAN1_TX_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
USB_HP_CAN1_TX_IRQHandler
        B USB_HP_CAN1_TX_IRQHandler

        PUBWEAK USB_LP_CAN1_RX0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
USB_LP_CAN1_RX0_IRQHandler
        B USB_LP_CAN1_RX0_IRQHandler

        PUBWEAK CAN1_RX1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
CAN1_RX1_IRQHandler
        B CAN1_RX1_IRQHandler

        PUBWEAK CAN1_SCE_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
CAN1_SCE_IRQHandler
        B CAN1_SCE_IRQHandler

        PUBWEAK EXTI9_5_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI9_5_IRQHandler
        B EXTI9_5_IRQHandler

        PUBWEAK TIM1_BRK_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIM1_BRK_IRQHandler
        B TIM1_BRK_IRQHandler

        PUBWEAK TIM1_UP_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIM1_UP_IRQHandler
        B TIM1_UP_IRQHandler

        PUBWEAK TIM1_TRG_COM_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIM1_TRG_COM_IRQHandler
        B TIM1_TRG_COM_IRQHandler

        PUBWEAK TIM1_CC_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIM1_CC_IRQHandler
        B TIM1_CC_IRQHandler

        PUBWEAK TIM2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIM2_IRQHandler
        B TIM2_IRQHandler

        PUBWEAK TIM3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIM3_IRQHandler
        B TIM3_IRQHandler

        PUBWEAK TIM4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
TIM4_IRQHandler
        B TIM4_IRQHandler

        PUBWEAK I2C1_EV_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C1_EV_IRQHandler
        B I2C1_EV_IRQHandler

        PUBWEAK I2C1_ER_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C1_ER_IRQHandler
        B I2C1_ER_IRQHandler

        PUBWEAK I2C2_EV_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C2_EV_IRQHandler
        B I2C2_EV_IRQHandler

        PUBWEAK I2C2_ER_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
I2C2_ER_IRQHandler
        B I2C2_ER_IRQHandler

        PUBWEAK SPI1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SPI1_IRQHandler
        B SPI1_IRQHandler

        PUBWEAK SPI2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
SPI2_IRQHandler
        B SPI2_IRQHandler

        PUBWEAK UART1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART1_IRQHandler
        B UART1_IRQHandler

        PUBWEAK UART2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART2_IRQHandler
        B UART2_IRQHandler

        PUBWEAK UART3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART3_IRQHandler
        B UART3_IRQHandler

        PUBWEAK EXTI15_10_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
EXTI15_10_IRQHandler
        B EXTI15_10_IRQHandler

        PUBWEAK RTC_Alarm_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
RTC_Alarm_IRQHandler
        B RTC_Alarm_IRQHandler

        PUBWEAK USBWakeUp_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
USBWakeUp_IRQHandler
        B USBWakeUp_IRQHandler

        END
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
