/*

    */
.text
.balign 2
.syntax unified
.thumb
.thumb_func
.global Reset_Handler

Reset_Handler:

    /* Initialize Data section.  */
    ldr     r1, =__data_init_start
    ldr     r2, =__data_start
    ldr     r3, =__data_end

    b       2f
1:  ldmia   r1!,    {r0}
    stmia   r2!,    {r0}
2:  cmp     r2, r3
    bne     1b

    /* Initialize fastcode section. */
    ldr     r1, =__fastcode_init_start
    ldr     r2, =__fastcode_start
    ldr     r3, =__fastcode_end

    b       2f
1:  ldmia   r1!,    {r0}
    stmia   r2!,    {r0}
2:  cmp     r2, r3
    bne     1b

    /* Initialize bss section. */
    movs    r0, #0
    ldr     r1, =__bss_start
    ldr     r2, =__bss_end

    b       2f
1:  stmia   r1!,    {r0}
2:  cmp     r1,     r2
    bne     1b

    /* branch to main */

    ldr     r0, =main
    blx     r0

    b       .
