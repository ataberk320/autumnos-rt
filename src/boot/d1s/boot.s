.section .vectors, "ax"
.globl _start

_start:
	csrw mie, zero
	csrw mip, zero

	.option push
	.option norelax
	la gp, __global_pointer$
	.option pop
	
	la sp, _stack_top

	li t0, 0x00006000
	csrs mstatus, t0

	la a0, __bss_start
	la a1, __bss_end
	bgeu a0, a1, .bss_done
.bss_loop:
	sd zero, 0(a0)
	addi a0, a0, 8
	bltu a0, a1, .bss_loop

.bss_done:
	tail entry

.section .stack
.align 4
_stack_bottom:
	.space 8192
_stack_top:
