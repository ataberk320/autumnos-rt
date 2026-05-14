#ifndef MEM_H
#define MEM_H

void* atm_malloc(uint32_t size);
void afree(void *ptr, uint32_t size);
rt_thread_t acrtask(const char *name, void (*entry) (void* parameter), uint32_t stack_size, uint8_t priority);

#endif
