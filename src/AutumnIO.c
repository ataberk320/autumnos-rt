#include "cdictheader/main.h"
#include <dfs_posix.h>

int aopen(const char *path, int flags) {
	int fd = open(path, flags);
	if (fd < 0) {
		return -1;
	}
	return fd;
}

int aread(int fd, void *buf, uint32_t len) {
	if (fd < 0 || buf == RT_NULL) return 1;
	return read(fd, buf, len);
}

int awrt(int fd, const void *buf, uint32_t len) {
	if (fd < 0 || buf == RT_NULL) return -1;
	return write(fd, buf, len);
}

void aclose(int fd) {
	if (fd >= 0) close(fd);
}
