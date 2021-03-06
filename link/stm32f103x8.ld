/**
 *  @file script.ld
 *  @author T. Verloop <t93.verloop@gmail.com>
 *  @version 0.1
 *  @date 09-04-2018
 *  @brief stm32f030x4 GCC Linkerscript
 *
 *  @detail A GCC linkerscript for the stm323f030x4 cortex-m0 microcontrollers
 *
 **/

SEARCH_DIR(.);

/*-----------------------------------------------------------------------------*/
/* Output format.                                                              */
/*-----------------------------------------------------------------------------*/

OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm", "elf32-littlearm");
OUTPUT_ARCH(arm);

/*-----------------------------------------------------------------------------*/
/* Stack Sizes.                                                                */
/*-----------------------------------------------------------------------------*/

/* Main stack is used by user code and interrupts. */
__main_stack_size = 1024;
PROVIDE(__main_stack_size = __main_stack_size);
/*
 *  Process stack is optionally used by user program. Interrupt vectors still
 *  use main stack.
 */
__process_stack_size = 0;
PROVIDE(__process_stack_size = __process_stack_size);

/*-----------------------------------------------------------------------------*/
/* Memory definitions.                                                         */
/*-----------------------------------------------------------------------------*/

MEMORY {
    /* Flash region. */
    rom (rx) : org = 0x08000000, len = 64k
    /* Ram region. */
    ram (rwx) : org = 0x20000000, len = 20k
    /* Special zero sized region */
    nul (rwx) : org = 0x20000000, len = 0k
}

__rom_start = ORIGIN(rom);
__rom_size = LENGTH(rom);
__rom_end = __rom_start + __rom_size;
__ram_start = ORIGIN(ram);
__ram_size = LENGTH(ram);
__ram_end = __ram_start + __ram_size;

PROVIDE(__rom_start = __rom_start);
PROVIDE(__rom_size = __rom_size);
PROVIDE(__rom_end = __rom_end);
PROVIDE(__ram_start = __ram_start);
PROVIDE(__ram_size = __ram_size);
PROVIDE(__ram_end = __ram_end);

/*-----------------------------------------------------------------------------*/
/* Entry point.                                                                */
/*-----------------------------------------------------------------------------*/

ENTRY( Reset_Handler );

/*-----------------------------------------------------------------------------*/
/* Sections.                                                                   */
/*-----------------------------------------------------------------------------*/

SECTIONS {
    .text : {
        . = ALIGN(4);
        __text_start = .;
        PROVIDE(__text_start = __text_start);
        . = ALIGN(4);
        KEEP(*(.vectors));
        . = ALIGN(4);
        *(.text .text.* .gnu.linkonce.t.*);
        . = ALIGN(4);
        *(.rodata .rodata.* .gnu.linkonce.r.*);
        . = ALIGN(4);
        *(.ARM.extab* .gnu.linkonce.armextab.*); /* exception unwinding information */
        . = ALIGN(4);
        *(.gcc_except_table); /* information used for stack unwinding during exception */
        . = ALIGN(4);
        *(.eh_frame_hdr); /* additional information about .ex_frame section */
        . = ALIGN(4);
        *(.eh_frame); /* information used for stack unwinding during exception */
/*

		. = ALIGN(4);

		KEEP(*(.init));

		. = ALIGN(4);

		__preinit_array_start = .;

		KEEP(*(.preinit_array));

		. = ALIGN(4);

		__preinit_array_end = .;

		__init_array_start = .;

		KEEP(*(SORT(.init_array.*)));

		. = ALIGN(4);

		KEEP(*(.init_array));

		. = ALIGN(4);

		__init_array_end = .;

*/
/*

		KEEP(*(.fini));

		. = ALIGN(4);

		__fini_array_start = .;

		KEEP(*(.fini_array));

		. = ALIGN(4);

		KEEP(*(SORT(.fini_array.*)));

		. = ALIGN(4);

		__fini_array_end = .;

*/
        . = ALIGN(4);
        __text_end = .;
        PROVIDE(__text_end = __text_end);
    } > rom AT > rom

    .IF_YOU_SEE_THIS_YOU_HAVE_ONE_OR_MORE_GLOBAL_OBJECT_CONSTRUCTORS : {
        KEEP(*(.init));
        KEEP(*(.preinit_array));
        KEEP(*(SORT(.init_array.*)));
        KEEP(*(.init_array));
    } > nul


    . = ALIGN(4);
    __exidx_start = .;
    PROVIDE(__exidx_start = __exidx_start);


    .ARM.exidx : {
        *(.ARM.exidx* .gnu.linkonce.armexidx.*);
    } > rom AT > rom /* index entries for section unwinding */

    . = ALIGN(4);
    __exidx_end = .;
    PROVIDE(__exidx_end = __exidx_end);


    .data : {
        . = ALIGN(4);
        __data_init_start = LOADADDR (.data);
        PROVIDE(__data_init_start = __data_init_start);
        __data_start = .;
        PROVIDE(__data_start = __data_start);
        . = ALIGN(4);
        *(.data .data.* .gnu.linkonce.d.*)
        . = ALIGN(4);
        __data_end = .;
        PROVIDE(__data_end = __data_end);
    } > ram AT > rom

    .fastcode : {
        . = ALIGN(4);
        __fastcode_init_start = LOADADDR (.fastcode);
        PROVIDE(__fastcode_init_start = __fastcode_init_start);
        __fastcode_start = .;
        PROVIDE(__fastcode_start = __fastcode_start);
        . = ALIGN(4);
        *(.glue_7t .glue_7);
        *(text.fastcode)
        . = ALIGN(4);
        __fastcode_end = .;
        PROVIDE(__fastcode_end = __fastcode_end);
    } > ram AT > rom


    .bss : {
        . = ALIGN(4);
        __bss_start = .;
        PROVIDE(__bss_start = __bss_start);
        . = ALIGN(4);
        *(.bss .bss.* .gnu.linkonce.b.*)
        . = ALIGN(4);
        *(COMMON);
        . = ALIGN(4);
        __bss_end = .;
        PROVIDE(__bss_end = __bss_end);
    } > ram AT > ram

    .stack : {
        . = ALIGN(8);
        __stack_start = .;
        PROVIDE(__stack_start = __stack_start);
        . = ALIGN(8);
        __main_stack_start = .;
        PROVIDE(__main_stack_start = __main_stack_start);
        . += __main_stack_size;
        . = ALIGN(8);
        __main_stack_end = .;
        PROVIDE(__main_stack_end = __main_stack_end);
        . = ALIGN(8);
        __process_stack_start = .;
        PROVIDE(__process_stack_start = __process_stack_start);
        . += __process_stack_size;
        . = ALIGN(8);
        __process_stack_end = .;
        PROVIDE(__process_stack_end = __process_stack_end);
        . = ALIGN(8);
        __stack_end = .;
        PROVIDE(__stack_end = __stack_end);
    } > ram AT > ram

    . = ALIGN(4);
    __heap_start = .;
    PROVIDE(__heap_start = __heap_start);
    . = ALIGN(4);
    __heap_end = __ram_end;
    PROVIDE(__heap_end = __heap_end);
    .stab 0 (NOLOAD) : { *(.stab) }
    .stabstr 0 (NOLOAD) : { *(.stabstr) }
    /* DWARF debug sections.

       * Symbols in the DWARF debugging sections are relative to the beginning

       * of the section so we begin them at 0. */
    /* DWARF 1 */
    .debug 0 : { *(.debug) }
    .line 0 : { *(.line) }
    /* GNU DWARF 1 extensions */
    .debug_srcinfo 0 : { *(.debug_srcinfo) }
    .debug_sfnames 0 : { *(.debug_sfnames) }
    /* DWARF 1.1 and DWARF 2 */
    .debug_aranges 0 : { *(.debug_aranges) }
    .debug_pubnames 0 : { *(.debug_pubnames) }
    /* DWARF 2 */
    .debug_info 0 : { *(.debug_info .gnu.linkonce.wi.*) }
    .debug_abbrev 0 : { *(.debug_abbrev) }
    .debug_line 0 : { *(.debug_line) }
    .debug_frame 0 : { *(.debug_frame) }
    .debug_str 0 : { *(.debug_str) }
    .debug_loc 0 : { *(.debug_loc) }
    .debug_macinfo 0 : { *(.debug_macinfo) }
    /* SGI/MIPS DWARF 2 extensions */
    .debug_weaknames 0 : { *(.debug_weaknames) }
    .debug_funcnames 0 : { *(.debug_funcnames) }
    .debug_typenames 0 : { *(.debug_typenames) }
    .debug_varnames 0 : { *(.debug_varnames) }
    .note.gnu.arm.ident 0 : { KEEP(*(.note.gnu.arm.ident)) }
    .ARM.attributes 0 : { KEEP(*(.ARM.attributes)) }
    /DISCARD/ : { *(.note.GNU-stack) }
}

PROVIDE(__text_size = __text_end - __text_start);
PROVIDE(__exidx_size = __exidx_end - __exidx_start);
PROVIDE(__data_size = __data_end - __data_start);
PROVIDE(__bss_size = __bss_end - __bss_start);
PROVIDE(__stack_size = __stack_end - __stack_start);
PROVIDE(__heap_size = __heap_end - __heap_start);

/******************************************************************************

* END OF FILE

******************************************************************************/
