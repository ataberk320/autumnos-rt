#include <drivers.h>
#include <rtthread.h>

const char* cpuv(void) {
	unsigned long vid = 0;

	__asm__ volatile ("csrr %0, mvendorid" : "=r"(vid));
	
	if (vid == 0x5b7) {
		return "Allwinner Technology D1";
	}
	else if (vid == 0) {
		return "Generic/Unknown";
	}
	return "NULL";
}

uint32_t total_ram(void) {
	rt_size_t total, used;
	rt_memory_info(&total, &used, RT_NULL);
	return (uint32_t)total;
}

uint32_t used_ram(void) {
	rt_size_t total, used;
	rt_memory_info(&total, &used, RT_NULL);
	return (uint32_t)used;
}
