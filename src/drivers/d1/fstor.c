#include <drivers.h>
#include <rtthread.h>
#include <dfs_posix.h>

int storage_init(void) {
	if (dfs_mount("sd0", "/", "elm", 0, 0) == 0) {
		return 0;
	}
	return -1;
}

int write(const char *path, const void *data, uint32_t len) {
	int fd = open(path,  O_WRONLY | O_CREAT | O_TRUNC);
	if (fd >= 0) {
		write(fd, data, len);
		close(fd);
		return 0;
	}
	return -1;
}

int read(const char *path, void* buffer, uint32_t len) {
	int fd = open(path, O_RDONLY);
	if (fd >= 0) {
		int bytes = read(fd, buffer, len);
		close(fd);
		return bytes;
	}
	return -1;
} 
