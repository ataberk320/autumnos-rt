#ifndef MAINFUNC_H
#define MAINFUNC_H

#include <rtthread.h>

//panic.c
void a_kpanic(const char *reason);

//acore.c
void entry(void *par);
void corethr(void);


#endif
