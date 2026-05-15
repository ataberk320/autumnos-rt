#include <rtthread.h>
#include <rtdevice.h>
#include <drivers.h>
#include "dict.h"

#define TOUCH_I2C_BUS "i2c2"

static struct rt_i2c_bus_device *touch_bus = RT_NULL;

int screen_init(void) {
	touch_bus = (struct rt_i2c_bus_device *)rt_device_find(TOUCH_I2C_BUS);
	if (touch_bus == RT_NULL) {
		return -RT_ERROR;
	}
	return RT_EOK;
}

int touch_read(int16_t *x, int16_t *y) {
	uint8_t read_buf[6];
	uint8_t reg_addr[2] = {0x81, 0x4E};
	
	struct rt_i2c_msg msgs[2];
	msgs[0].addr = TOUCH_ADDR;
	msgs[0].flags = RT_I2C_WR;
	msgs[0].buf = reg_addr;
	msgs[0].len = 2;
	msgs[1].addr  = TOUCH_ADDR;
    	msgs[1].flags = RT_I2C_RD;
    	msgs[1].buf   = read_buf;
    	msgs[1].len   = 6;
	if (rt_i2c_transfer(touch_bus, msgs, 2) == 2) {
		if (read_buf[0] & 0x80) {
			*x = ((read_buf[3] & 0x0F) << 8) | read_buf[2];
			*y = ((read_buf[5] & 0x0F) << 8) | read_buf[4];

			uint8_t clean_reg[3] = {0x81, 0x4E, 0x00};
			rt_i2c_master_send(touch_bus, TOUCH_ADDR, 0, clean_reg, 3);
			return 1;
		}
	}
	return 0;
}
