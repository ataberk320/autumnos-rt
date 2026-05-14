#include "drivers.h"
#include <rtthread.h>
#include <rtdevice.h>

void power_off(void) {
	struct rt_i2c_bus_device *i2c_bus;
	i2c_bus = (struct rt_i2c_bus_device *)rt_device_find("i2c0");

	if (i2c_bus != RT_NULL) {
		uint8_t buf[2];
		buf[0] = AXP_P_OFF;
		buf[1] = P_OFF_BIT;

		struct rt_i2c_msg msg;
		msg.addr = AXP_ADDR;
		msg.flags = RT_I2C_WR;
		msg.buf = buf;
		msg.len = 2;

		rt_i2c_transfer(i2c_bus, &msg, 1);
	}
}

void reboot(void) {
	rt_hw_cpu_reset();
}
