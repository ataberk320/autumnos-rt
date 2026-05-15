#include <rtthread.h>
#include <rtdevice.h>
#include <dfs_posix.h>
#include "drivers.h"
#include "dict.h"

int sdcard(void) {
	uint32_t reg_val = *(volatile uint32_t*)PF_CFG0_REG;
	reg_val &= ~(0xFFFFFF);
	reg_val |= 0x222222;
	*(volatile uint32_t *)PF_CFG0_REG = reg_val;
	
	*(volatile uint32_t *)SDMMC0_CLK_REG = (1 << 31) | (1 << 24) | 0x02;

	rt_thread_mdelay(100);
	return RT_EOK;
}

int sdcart_mnt(void) {
	if (dfs_mount("sd0", "/", "elm", 0, 0) == 0) {
		return 0;
	}
	return -1;
}
