MEMORY
{
	RAM (xrw) : ORIGIN = 0x40000000, LENGTH = 64M
}

ENTRY(_start)

SECTIONS
{
.text :
    {
        . = ALIGN(8);
        KEEP(*( .vectors ))
        *(.text)
        *(.text.*)
        *(.rodata)
        *(.rodata.*)
        . = ALIGN(8);
    } > RAM

    . = ALIGN(8);
    __global_pointer$ = . + 0x800;

    .data :
    {
        . = ALIGN(8);
        *(.data)
        *(.data.*)
        *(.sdata)
        *(.sdata.*)
        . = ALIGN(8);
    } > RAM

    .bss :
    {
        . = ALIGN(8);
        __bss_start = .;
        *(.bss)
        *(.bss.*)
        *(.sbss)
        *(.sbss.*)
        *(COMMON)
        . = ALIGN(8);
        __bss_end = .;
    } > RAM

    .stack :
    {
        . = ALIGN(16);
        _stack_bottom = .;
        . += 8192;
        _stack_top = .;
    } > RAM

    _end = .;
}
