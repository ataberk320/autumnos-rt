#include "drivers.h"
#include <rtthread.h>
#include "main.h"

void entry(void *par) {
	while (1) {
		int battery_level = battery_percent();
		if (battery_level > 0 && battery_level <= 2) {
			power_off();
		}
	}

void corethr(void) {
	rt_thread_t tid;
	tid = acrtask("acore", entry, 2048, 10);
	if (core_tid == RT_NULL) {
		a_kpanic("Could not start critical process!");
	}
}
