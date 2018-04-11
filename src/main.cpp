//
//
//
//
//
//
//
/// @file main.cpp
/// @author T. Verloop <t93.verloop@gmail.com>
/// @version 0.1
/// @date 04-04-2018
/// @brief Entry point of the program.
///

//****************************************************************************//
// Includes.
//****************************************************************************//

// System.
#include <cstdint>

// Third Party.

// Local.

/// Reference to a memory address in io space.
typedef volatile uint32_t & registry_ref_t;
/// Pointer to a memory address in io space.
typedef volatile uint32_t * registry_ptr_t;

/// Creates a pointer to a IO space memory address from an unsigned integer.
///
/// @param[in]  address Integer representing an memory address.
/// @return
///         @li Reference to a memory address.
static constexpr registry_ref_t p_registry(const uint32_t & address) {
    return (*(registry_ptr_t) address);
}

/// The entry point of the application.
///
/// @return
///         @li 0   Program terminated as intended.
///         @li !0  Program terminated due to an error.
int main(void) {

    // AHB clock enable register.
    registry_ref_t rcc_ahbenr      = p_registry(0x40021014);
    // GPIOA mode register.
    registry_ref_t gpioa_moder     = p_registry(0x48000000);
    // GPIOA output data register
    registry_ref_t gpioa_odr       = p_registry(0x48000014);

    // Enable Clock for GPIOA
    rcc_ahbenr |= (0x01 << 17);
    // Set Pin PA5 output.
    gpioa_moder |= (0x01 << (5 * 2));

    // Loop forever.
    while (1) {
        // Set the pin high.
        gpioa_odr |= (0x01 << 5);
        // Wait a bit.
        for(volatile uint32_t i = 0; i < 1000000; i++) {}
        // Clear the pin.
        gpioa_odr &= ~(0x01 << 5);
        // Wait some more.
        for(volatile uint32_t i = 0; i < 1000000; i++) {}
    }
    return 0;
}
