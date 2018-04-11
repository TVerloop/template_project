//
//
//
//
//
//
//
/// @file startup.c
/// @author T. Verloop <t93.verloop@gmail.com>
/// @version 0.1
/// @date 04-04-2018
/// @brief Reset handler definition.
///
/// @detail Startup code
///

//****************************************************************************//
// Includes.
//****************************************************************************//

// System.
#include <stdint.h>

// Third Party.

// Local.

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

    /// Position in ROM where data section is to be obtained.
    extern const uint32_t __data_init_start;
    /// Position in RAM where data section is to be placed.
    extern uint32_t __data_start;
    /// End of the data section in ROM.
    extern const uint32_t __data_end;

    /// Position in ROM where fastcode section is to be obtained.
    extern const uint32_t __fastcode_init_start;
    /// Position in RAM where fastcode section is to be placed.
    extern uint32_t __fastcode_start;
    /// End of the fastcode section in ROM.
    extern const uint32_t __fastcode_end;

    /// Begin of the BSS section.
    extern uint32_t __bss_start;
    /// End of the BSS section.
    extern const uint32_t __bss_end;

    extern int main(void);

    /// Handels low level initialization.
    ///
    /// @param  None.
    /// @return
    ///         @li void
    void _start(void) {
        const uint32_t * src;
        uint32_t * dst;

        //--------------------------------------------------------------------//
        // Initialize the Data section.
        //--------------------------------------------------------------------//

        src = &__data_init_start;
        dst = &__data_start;

        while(dst < &__data_end) {
            *dst = *src;
            dst++;
            src++;
        }

        //--------------------------------------------------------------------//
        // Initialize the fastcode section.
        //--------------------------------------------------------------------//

        src = &__fastcode_init_start;
        dst = &__fastcode_start;

        while(dst < &__fastcode_end) {
            *dst = *src;
            dst++;
            src++;
        }

        //--------------------------------------------------------------------//
        // Initialize the BSS section.
        //--------------------------------------------------------------------//

        dst = &__bss_start;

        while(dst < &__bss_end) {
            *dst = 0;
            dst++;
        }

        //--------------------------------------------------------------------//
        // Launch the main.
        //--------------------------------------------------------------------//

        main();

        //--------------------------------------------------------------------//
        // In the unlikely event that the main exits loop forever.
        //--------------------------------------------------------------------//

        while(1) {}
    }

#ifdef __cplusplus
}
#endif //__cplusplus
