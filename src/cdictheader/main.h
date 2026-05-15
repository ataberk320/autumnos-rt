#ifndef MAINFUNC_H
#define MAINFUNC_H

#include <rtthread.h>

//panic.c
void a_kpanic(const char *reason);

//acore.c
void entry(void *par);
void corethr(void);

//AutumnIO.c
int aopen(const char *path, int flags);
int aread(int fd, void *buf, uint32_t len);
int awrt(int fd, const void *buf, uint32_t len);
void aclose(int fd);

#endif
