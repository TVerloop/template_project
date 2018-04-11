//
//
//
//
//
//
//
/// @file vectors.c
/// @author T. Verloop <t93.verloop@gmail.com>
/// @version 0.1
/// @date 04-04-2018
/// @brief Interrupt vector table.
///
/// @detail Contains a default definition for every interrupt. Theses defaults
/// Can be overwritten by any other definition as these are all weak linked.
///

#include <irq.h>

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

    /// Default interrupt handler, linked against all handlers which are not
    /// defined otherwise.
    ///
    /// @param  None.
    /// @return void.
    static void __attribute__((interrupt ("IRQ"))) __default_handler(void) {
        while(1) {
            __asm__("BKPT");
        }
    }

    /// Defines default handlers.
    /// @param NAME     handler name.
    /// @return
    ///         @li     Default handler definition
    #define default_handler(NAME)                                           \
        void NAME ## _handler(void)

    #define __def_handlr \
        __attribute__ ((interrupt ("IRQ"), weak, alias("__default_handler")))

    //-------------------------------------------------------------------------//
    // Define all default interrupt handlers.
    //-------------------------------------------------------------------------//

    void __def_handlr handler_0x08 (void) ;
    void __def_handlr handler_0x0C (void) ;
    void __def_handlr handler_0x10 (void) ;
    void __def_handlr handler_0x14 (void) ;
    void __def_handlr handler_0x18 (void) ;
    void __def_handlr handler_0x1C (void) ;
    void __def_handlr handler_0x20 (void) ;
    void __def_handlr handler_0x24 (void) ;
    void __def_handlr handler_0x28 (void) ;
    void __def_handlr handler_0x2C (void) ;
    void __def_handlr handler_0x30 (void) ;
    void __def_handlr handler_0x34 (void) ;
    void __def_handlr handler_0x38 (void) ;
    void __def_handlr handler_0x3C (void) ;
    void __def_handlr handler_0x40 (void) ;
    void __def_handlr handler_0x44 (void) ;
    void __def_handlr handler_0x48 (void) ;
    void __def_handlr handler_0x4C (void) ;
    void __def_handlr handler_0x50 (void) ;
    void __def_handlr handler_0x54 (void) ;
    void __def_handlr handler_0x58 (void) ;
    void __def_handlr handler_0x5C (void) ;
    void __def_handlr handler_0x60 (void) ;
    void __def_handlr handler_0x64 (void) ;
    void __def_handlr handler_0x68 (void) ;
    void __def_handlr handler_0x6C (void) ;
    void __def_handlr handler_0x70 (void) ;
    void __def_handlr handler_0x74 (void) ;
    void __def_handlr handler_0x78 (void) ;
    void __def_handlr handler_0x7C (void) ;
    void __def_handlr handler_0x80 (void) ;
    void __def_handlr handler_0x84 (void) ;
    void __def_handlr handler_0x88 (void) ;
    void __def_handlr handler_0x8C (void) ;
    void __def_handlr handler_0x90 (void) ;
    void __def_handlr handler_0x94 (void) ;
    void __def_handlr handler_0x98 (void) ;
    void __def_handlr handler_0x9C (void) ;
    void __def_handlr handler_0xA0 (void) ;
    void __def_handlr handler_0xA4 (void) ;
    void __def_handlr handler_0xA8 (void) ;
    void __def_handlr handler_0xAC (void) ;
    void __def_handlr handler_0xB0 (void) ;
    void __def_handlr handler_0xB4 (void) ;
    void __def_handlr handler_0xB8 (void) ;
    void __def_handlr handler_0xBC (void) ;

    //----------------------------------------------------------------------------//
    // Interrupt vector table.
    //----------------------------------------------------------------------------//

    // imported main stack end (from linker script)
    extern const char __main_stack_end;
    // import the address of Reset_Handler()
    extern void _start(void);
    // Vector table.
    const volatile void * volatile vectors[] __attribute__ ((section(".vectors"))) = {
    	(void *)&__main_stack_end,
    	(void *)_start,
        (void *)handler_0x08,
        (void *)handler_0x0C,
        (void *)handler_0x10,
        (void *)handler_0x14,
        (void *)handler_0x18,
        (void *)handler_0x1C,
        (void *)handler_0x20,
        (void *)handler_0x24,
        (void *)handler_0x28,
        (void *)handler_0x2C,
        (void *)handler_0x30,
        (void *)handler_0x34,
        (void *)handler_0x38,
        (void *)handler_0x3C,
        (void *)handler_0x40,
        (void *)handler_0x44,
        (void *)handler_0x48,
        (void *)handler_0x4C,
        (void *)handler_0x50,
        (void *)handler_0x54,
        (void *)handler_0x58,
        (void *)handler_0x5C,
        (void *)handler_0x60,
        (void *)handler_0x64,
        (void *)handler_0x68,
        (void *)handler_0x6C,
        (void *)handler_0x70,
        (void *)handler_0x74,
        (void *)handler_0x78,
        (void *)handler_0x7C,
        (void *)handler_0x80,
        (void *)handler_0x84,
        (void *)handler_0x88,
        (void *)handler_0x8C,
        (void *)handler_0x90,
        (void *)handler_0x94,
        (void *)handler_0x98,
        (void *)handler_0x9C,
        (void *)handler_0xA0,
        (void *)handler_0xA4,
        (void *)handler_0xA8,
        (void *)handler_0xAC,
        (void *)handler_0xB0,
        (void *)handler_0xB4,
        (void *)handler_0xB8
    };


#ifdef __cplusplus
}
#endif //__cplusplus
