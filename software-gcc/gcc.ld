MEMORY
{
  RAM (rwx) : ORIGIN = 0x00000000, LENGTH = 0x100000 
}

ENTRY(vector_table)
SECTIONS
{
 . = 0x0;
 .text : {
 * (vectors)
 *(.text)
 }
 .data : { *(.data) }
 .bss :
 {
        . = ALIGN(4);
        __bss_start__ = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        __bss_end__ = .;
 } > RAM
 .heap (COPY):
 {
        __end__ = .;
        PROVIDE(end = .);
        *(.heap*)
        __HeapLimit = .;
 } > RAM
 . = ALIGN(8);
 . = . + 0x1000; /* 4kB of stack memory */
 stack_top = .;
}
