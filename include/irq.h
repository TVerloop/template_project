//
//
//
//
//
//
//
/// @file irq.h
/// @author T. Verloop <t93.verloop@gmail.com>
/// @version 0.1
/// @date 09-04-2018
/// @brief Interrupt definitions.
///
/// @detail Macros to simplify creation of interrupt handlers.
///

//****************************************************************************//
// Includes.
//****************************************************************************//

#ifndef IRQ_H__
#define IRQ_H__

// Interrupt handlers need to be linked C style. So if C++ is used to compile
// Add an extern "C" to the function.
#ifdef __cplusplus
#define C_LINKAGE extern "C"
#else
#define C_LINKAGE
#endif

/// Non maskable interrupt IRQ.
#define IRQ_NMI                     0x08
/// Hardfault IRQ.
#define IRQ_HARDFAULT               0x0C

/// Reserverd IRQ.
#define IRQ_RESERVED_0x10           0x10
/// Reserverd IRQ.
#define IRQ_RESERVED_0x14           0x14
/// Reserverd IRQ.
#define IRQ_RESERVED_0x18           0x18
/// Reserverd IRQ.
#define IRQ_RESERVED_0x1C           0x1C
/// Reserverd IRQ.
#define IRQ_RESERVED_0x20           0x20
/// Reserverd IRQ.
#define IRQ_RESERVED_0x24           0x24
/// Reserverd IRQ.
#define IRQ_RESERVED_0x28           0x28

/// System Service call IRQ.
#define IRQ_SVC                     0x2C

/// Reserverd IRQ.
#define IRQ_RESERVED_0x30           0x30
/// Reserverd IRQ.
#define IRQ_RESERVED_0x34           0x34

/// Pending Service call IRQ.
#define IRQ_PENDSV                  0x38
/// Systick IRQ.
#define IRQ_SYSTICK                 0x3C
/// Windowed watch dog IRQ.
#define IRQ_WWDG                    0x40

/// Reserverd IRQ.
#define IRQ_RESERVED_0x44           0x44

/// Real Time Clock IRQ.
#define IRQ_RTC                     0x48
/// Flash global IRQ.
#define IRQ_FLASH                   0x4C
/// Reset and Clock control IRQ.
#define IRQ_RCC                     0x50

/// EXTI Line [1:0] interrupts.
#define IRQ_EXTI0_1                 0x54
/// EXTI Line [3:2] interrupts.
#define IRQ_EXTI2_3                 0x58
/// EXTI Line [5:4] interrupts.
#define IRQ_EXTI4_5                 0x5C

/// Reserverd IRQ.
#define IRQ_RESERVED_0x60           0x60

/// DMA Channel 1 IRQ.
#define IRQ_DMA_CH1                 0x64
/// DMA Channel 2 and 3 IRQ.
#define IRQ_DMA_CH2_3               0x68
/// DMA Channel 4 and 5 IRQ.
#define IRQ_DMA_CH4_5               0x6C
/// ADC IRQ.
#define IRQ_ADC                     0x70
/// TIM1 break, update, trigger, commutation IRQ.
#define IRQ_TIM1_BRK_UP_TRG_COM     0x74
/// TIM1 capture compare IRQ.
#define IRQ_TIM1_CC                 0x78

/// Reserverd IRQ.
#define IRQ_RESERVED_0x7C           0x7C

/// TIM3 global IRQ.
#define IRQ_TIM3                    0x80

/// TIM6 global IRQ.
#define IRQ_TIM6                    0x84

/// Reserved IRQ,
#define IRQ_RESERVED_0x88           0x88

/// TIM14 global IRQ.
#define IRQ_TIM14                   0x8C
/// TIM15 global IRQ.
#define IRQ_TIM15                   0x90
/// TIM16 global IRQ.
#define IRQ_TIM16                   0x94
/// TIM17 global IRQ.
#define IRQ_TIM17                   0x98

/// I2C1 global IRQ.
#define IRQ_I2C1                    0x9C
/// I2C2 global IRQ.
#define IRQ_I2C2                    0xA0

/// SPI1 global IRQ.
#define IRQ_SPI1                    0xA4
/// SPI2 global IRQ.
#define IRQ_SPI2                    0xA8

/// USART1 global IRQ.
#define IRQ_USART1                  0xAC
/// USART2 global IRQ.
#define IRQ_USART2                  0xB0
/// USART3/4/5/6 global IRQ.
#define IRQ_USART3_4_5_6            0xB4

/// Reserved IRQ.
#define IRQ_RESERVED_0xB8           0xB8

/// USB global IRQ.
#define IRQ_USB                     0xBC

/// Defines a interrupt handler function.
/// @param[in] IRQ      A IRQ identifier Macro.
/// @return
///         @li IRQ function definition.
#define interrupt_handler(IRQ) \
    __make_irq(IRQ)

/// Macro function used by interrupt_handler(IRQ)
/// @warning Do not call this macro function. Use interrupt_handler(IRQ)
/// instead.
#define __make_irq(IRQ) \
    C_LINKAGE void __attribute__ ((interrupt ("IRQ"))) handler_ ## IRQ (void)

#endif //IRQ_H__
