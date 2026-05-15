#include <rtthread.h>
#include <rtdevice.h>
#include <drivers.h>
#define AUDIO_DEV_NAME "sound0"
static rt_device_t audio_dev = RT_NULL;

int init(void) {
    audio_dev = rt_device_find(AUDIO_DEV_NAME);
    if (audio_dev == RT_NULL) {
        return -1;
    }

    if (rt_device_open(audio_dev, RT_DEVICE_FLAG_WRONLY) != RT_EOK) {
        return -1;
    }

    struct rt_audio_caps caps;
    caps.main_type = AUDIO_TYPE_OUTPUT;
    caps.sub_type = AUDIO_DSP_PARAM;
    caps.udata.config.samplerate = 44100;
    caps.udata.config.channels = 2;
    caps.udata.config.samplebits = 16;
    rt_device_control(audio_dev, AUDIO_CTL_CONFIGURE, &caps);

    return 0;
}

void play(uint8_t *buffer, uint32_t size) {
	if (audio_dev != RT_NULL) {
		rt_device_write(audio_dev, 0, buffer, size);
	}
}

void sound_vol(int vol) {
	rt_device_t audio_dev;
	audio_dev = rt_device_find(AUDIO_DEV_NAME);
	
	if(audio_dev != RT_NULL) {
		rt_device_open(audio_dev, RT_DEVICE_FLAG_WRONLY);
		rt_device_control(audio_dev, AUDIO_CTL_SETVOLUME, &vol);
		rt_device_close(audio_dev);
	}
}
