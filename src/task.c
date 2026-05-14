#include "mem.h"
#include "drivers.h"
#include <rtthread.h>
#include "main.h"

rt_thread_t acrtask(const char *name, void (*entry) (void* parameter), uint32_t stack_size, uint8_t priority) {
	rt_thread_t tid = rt_thread_create(name, entry, RT_NULL, stack_size, priority, 20);
	if (tid != RT_NULL) {
		rt_thread_startup(tid);
	}
	return tid;
}
