#include <drivers.h>
#include <rtthread.h>
#include <rtdevice.h>
#include <string.h>

#define UART_DEV_NAME "uart1"
static rt_device_t net_dev = RT_NULL;

int sim_init(void) {
	net_dev = rt_device_find(UART_DEV_NAME);
	if (net_dev == RT_NULL) return -1;
	if (rt_device_open(net_dev, RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_INT_RX) != RT_EOK) return -1;
	struct serial_configure config = RT_SERIAL_CONFIG_DEFAULT;
	config.baud_rate = BAUD_RATE_115200;
	rt_device_control(net_dev, RT_DEVICE_CTRL_CONFIG, &config);
	return 0;
}

void send(const char *cmd) {
	if (net_dev != RT_NULL) {
		rt_device_write(net_dev, 0, cmd, strlen(cmd));
		rt_device_write(net_dev, 0, "\r\n", 2);
	}
}

int recv(uint8_t *buffer, uint32_t size) {
	if (net_dev != RT_NULL) {
		return rt_device_read(net_dev, 0, buffer, size);
	}
}
