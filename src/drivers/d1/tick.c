#include <rtthread.h>
#include <drivers.h>

uint32_t tick_ms(void) {
	return (uint32_t)rt_tick_get_millisecond();
}

void delay_ms(uint32_t ms) {
	rt_thread_mdelay(ms);
}
