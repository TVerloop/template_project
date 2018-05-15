/* -*- mode: c -*- */
/**
   @file vectors.c
   @author T. Verloop <t93.verloop@gmail.com>
   @version 0.1
   @date 15-05-2018
   @brief Interrupt vector table.

   @detail Contains a default definition for every interrupt. Theses defaults
   Can be overwritten by any other definition as these are all weak linked.
*/
#ifdef    __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
   @addtogroup Vectors
   @brief interrupt vector module.
   @{
 */

/**
   @brief Default interrupt handler.
*/
static void __Default_Handler(void)  __attribute__((interrupt ("IRQ")));
static void __Default_Handler(void) {
    while(1) {
        __asm__("BKPT");
    }
}

#if defined(CORTEXM0) || defined(CORTEXM0PLUS)

/**
   @addtogroup Cortex-m0
   @ingroup    Vectors.
   @brief      Cortex-m0 and m0+ interrupt handlers.
   @{
*/

void NMI_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void HardFault_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void __Reserved_0x10_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void __Reserved_0x14_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void __Reserved_0x18_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void __Reserved_0x1C_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void __Reserved_0x20_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void __Reserved_0x24_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void __Reserved_0x28_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void SVCall_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void __Reserved_0x30_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void __Reserved_0x34_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void PendSV_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void SysTick_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

/**
   @} End of group Cortex-m0.
*/

#elif defined(CORTEXM3)

/**
   @addtogroup Cortex-m3
   @ingroup    Vectors.
   @brief      Cortex-m3 interrupt handlers.
   @{
*/

void NMI_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void HardFault_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void MemoryManagementFault_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void BusFault_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));
group
void UsageFault_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void __Reserved_0x1C_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void __Reserved_0x20_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void __Reserved_0x24_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void __Reserved_0x28_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void SVCall_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void __Reserved_0x30_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void __Reserved_0x34_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void PendSV_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void SysTick_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

/**
   @} End of group Cortex-m3.
*/

#else

#error No arm core defined.

#endif

#if defined(STM32F0x0)

/**
   @addtogroup STM32F0x0
   @ingroup    Vectors.
   @brief      STM32F0x0 interrupt handlers.
   @{
*/

void WWDG_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void __Reserved_0x44_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void RTC_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void FLASH_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void RCC_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void EXTI0_1_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void EXTI2_3_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void EXTI4_15_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void __Reserved_0x60_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void DMA_CH1_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void DMA_CH2_3_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void DMA_CH4_5_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void ADC_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void TIM1_BRK_UP_TRG_COM_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void TIM1_CC_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void __Reserved_0x7C_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void TIM3_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void TIM6_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void __Reserved_0x84_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void __Reserved_0x88_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void TIM14_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void TIM15_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void TIM16_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void TIM17_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void I2C1_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void I2C2_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void SPI1_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void SPI2_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void USART1_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void USART2_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void USART3_4_5_6_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void __Reserved_0xB8_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void USB_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

/**
   @} End of group STM32F0x0.
*/

#elif defined(STM32F10xxx)

/**
   @addtogroup STM32F10xxx
   @ingroup    Vectors.
   @brief      STM32F10xxx interrupt handlers.
   @{
*/

void WWDG_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void PVD_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void TAMPER_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void RTC_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void FLASH_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void RCC_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void EXTI0_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void EXTI1_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void EXTI2_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void EXTI3_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void EXTI4_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void DMA1_CH1_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void DMA1_CH2_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void DMA1_CH3_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void DMA1_CH4_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void DMA1_CH5_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void DMA1_CH6_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void DMA1_CH7_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void ADC1_2_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void USB_HP_CAN_TX_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void USB_LP_CAN_RX0_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void CAN_RX1_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void CAN_SCE_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void EXTI9_5_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void TIM1_BRK_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void TIM1_UP_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void TIM1_TRG_COM_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void TIM1_CC_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void TIM2_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void TIM3_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void TIM4_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void I2C1_EV_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void I2C1_ER_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void I2C2_EV_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void I2C2_ER_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void SPI1_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void SPI2_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void USART1_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void USART2_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void USART3_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void EXTI15_10_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void RTCAlarm_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void USBWakeup_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void TIM8_BRK_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void TIM8_UP_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void TIM8_TRG_COM_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void TIM8_CC_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void ADC3_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void FSMC_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void SDIO_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void TIM5_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void SPI3_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void UART4_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void UART5_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void TIM6_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void TIM7_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void DMA2_CH1_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void DMA2_CH2_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void DMA2_CH3_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

void DMA2_CH4_5_Handler(void)
    __attribute__((interrupt("IRQ"), weak, alias("__Default_Handler")));

/**
   @} End of group STM32F10xxx.
*/

#else

#error Chip model not defined.

#endif

//----------------------------------------------------------------------------//
// Interrupt vector table.
//----------------------------------------------------------------------------//

/**
   @brief imported main stack end (from linker script)
*/
extern const char __main_stack_end;

/**
   @brief import the address of Reset_Handler()
*/
extern void Reset_Handler(void);

/**
   @brief  Vector table.
*/
void (*const vectors[])(void) __attribute__ ((used, section(".vectors"))) = {
    (void (*)(void))&__main_stack_end,
    Reset_Handler,

#if defined(CORTEXM0) || defined(CORTEXM0PLUS)

    NMI_Handler,
    HardFault_Handler,
    __Reserved_0x10_Handler,
    __Reserved_0x14_Handler,
    __Reserved_0x18_Handler,
    __Reserved_0x1C_Handler,
    __Reserved_0x20_Handler,
    __Reserved_0x24_Handler,
    __Reserved_0x28_Handler,
    SVCall_Handler,
    __Reserved_0x30_Handler,
    __Reserved_0x34_Handler,
    PendSV_Handler,
    SysTick_Handler,

#elif defined(CORTEXM3)

    NMI_Handler,
    HardFault_Handler,
    MemoryManagementFault_Handler,
    BusFault_Handler,
    UsageFault_Handler,
    __Reserved_0x1C_Handler,
    __Reserved_0x20_Handler,
    __Reserved_0x24_Handler,
    __Reserved_0x28_Handler,
    SVCall_Handler,
    __Reserved_0x30_Handler,
    __Reserved_0x34_Handler,
    PendSV_Handler,
    SysTick_Handler,

#endif

#if defined(STM32F0x0)

    WWDG_Handler,
    __Reserved_0x44_Handler,
        RTC_Handler,
    FLASH_Handler,
    RCC_Handler,
    EXTI0_1_Handler,
    EXTI2_3_Handler,
    EXTI4_15_Handler,
    __Reserved_0x60_Handler,
    DMA_CH1_Handler,
    DMA_CH2_3_Handler,
    DMA_CH4_5_Handler,
    ADC_Handler,
    TIM1_BRK_UP_TRG_COM_Handler,
    TIM1_CC_Handler,
    __Reserved_0x7C_Handler,
    TIM3_Handler,
    TIM6_Handler,
    __Reserved_0x84_Handler,
    __Reserved_0x88_Handler,
    TIM14_Handler,
    TIM15_Handler,
    TIM16_Handler,
    TIM17_Handler,
    I2C1_Handler,
    I2C2_Handler,
    SPI1_Handler,
    SPI2_Handler,
    USART1_Handler,
    USART2_Handler,
    USART3_4_5_6_Handler,
    __Reserved_0xB8_Handler,
    USB_Handler

#elif defined(STM32F10xxx)

    WWDG_Handler,
    PVD_Handler,
    TAMPER_Handler,
    RTC_Handler,
    FLASH_Handler,
    RCC_Handler,
    EXTI0_Handler,
    EXTI1_Handler,
    EXTI2_Handler,
    EXTI3_Handler,
    EXTI4_Handler,
    DMA1_CH1_Handler,
    DMA1_CH2_Handler,
    DMA1_CH3_Handler,
    DMA1_CH4_Handler,
    DMA1_CH5_Handler,
    DMA1_CH6_Handler,
    DMA1_CH7_Handler,
    ADC1_2_Handler,
    USB_HP_CAN_TX_Handler,
    USB_LP_CAN_RX0_Handler,
    CAN_RX1_Handler,
    CAN_SCE_Handler,
    EXTI9_5_Handler,
    TIM1_BRK_Handler,
    TIM1_UP_Handler,
    TIM1_TRG_COM_Handler,
    TIM1_CC_Handler,
    TIM2_Handler,
    TIM3_Handler,
    TIM4_Handler,
    I2C1_EV_Handler,
    I2C1_ER_Handler,
    I2C2_EV_Handler,
    I2C2_ER_Handler,
    SPI1_Handler,
    SPI2_Handler,
    USART1_Handler,
    USART2_Handler,
    USART3_Handler,
    EXTI15_10_Handler,
    RTCAlarm_Handler,
    USBWakeup_Handler,
    TIM8_BRK_Handler,
    TIM8_UP_Handler,
    TIM8_TRG_COM_Handler,
    TIM8_CC_Handler,
    ADC3_Handler,
    FSMC_Handler,
    SDIO_Handler,
    TIM5_Handler,
    SPI3_Handler,
    UART4_Handler,
    UART5_Handler,
    TIM6_Handler,
    TIM7_Handler,
    DMA2_CH1_Handler,
    DMA2_CH2_Handler,
    DMA2_CH3_Handler,
    DMA2_CH4_5_Handler

#endif

};

/**
   @} End of group Vectors.
 */

#ifdef    __cplusplus
}
#endif /* __cplusplus */
