#include <rtthread.h>
#include "main.h"
void a_kpanic(const char *reason) {
	rt_hw_interrupt_disable();
	rt_kprintf("KERNEL PANIC: %s\n", reason);
	reboot();
}
