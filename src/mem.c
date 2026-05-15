#include "cdictheader/mem.h"
#include "include/drivers.h"
#include <rtthread.h>

typedef struct {
	uint32_t total_alloc;
	uint32_t current_heap_u;
	uint32_t alloc_c;
} MemoryStats_t;

static MemoryStats_t stat = {0};

void* atm_malloc(uint32_t size) {
	void *ptr = rt_malloc(size);
	if (ptr != RT_NULL) {
		stat.current_heap_u += size;
		stat.total_alloc += size;
		stat.alloc_count++;
	}
	else {
		AutumnAPI_Reboot();
	}
	return ptr;
}

void afree(void *ptr, uint32_t size) {
	if (ptr != RT_NULL) {
		rt_free(ptr);
		stat.current_heap_u -= size;
		stat.alloc_c--;
	}
}
