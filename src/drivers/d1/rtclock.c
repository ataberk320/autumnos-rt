#include <drivers.h>
#include <rtthread.h>

#define RTC_DEV_NAME "rtc"
static rt_device_t rtc_dev = RT_NULL;

int rtc_device(void) {
	rtc_dev = rt_device_find(RTC_DEV_NAME);
	if (rtc_dev == RT_NULL) {
		return -1;
	}
	
	if (rt_device_open(rtc_dev, RT_DEVICE_FLAG_RDWR) != RT_EOK) {
		return -1;
	}

	return 0;
}

void a_time(void) {
	time_t now;
	struct tm *p;
	now = time(RT_NULL);
	p = gmtime(&now);
	
}
