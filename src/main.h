#ifndef MAINFUNC_H
#define MAINFUNC_H

#include <rtthread.h>

//panic.c
void a_kpanic(const char *reason);

//acore.c
void entry(void *par);
void corethr(void);

//task.c
rt_thread_t acrtask(const char *name, void (*entry) (void* parameter), uint32_t stack_size, uint8_t priority);

//mem.c
void* atm_malloc(uint32_t size);
void afree(void *ptr, uint32_t size);
