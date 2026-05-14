#include "drivers.h"
#include <rtthread.h>
#include <rtdevice.h>
#include "AutumnAPI.h"

uint32_t AutumnAPI_Get_TickMS(void) {
	tick_ms();
}

void AutumnAPI_DelayMS(uint32_t ms) {
	delay_ms(ms);
}

void AutumnAPI_PowerOff(void) {
	power_off();
}

void AutumnAPI_Reboot(void) {
	reboot();
}

void AutumnAPI_SIMStatus(void) {
	int status = sim_init();
	if (status != 1) {
		//Handle an function
	}
	return status;
}

void AutumnAPI_ModemSnd(const char *cmd) {
	send(cmd);
}

void AutumnAPI_Read_Battery_Level() {
	battery_percent();
}

void AutumnAPI_CPU_Vendor() {
	cpuv();
}

void AutumnAPI_Mount_FS() {
	storage_init();
}

void AutumnAPI_Play_Sound(uint8_t *buffer, uint32_t size) {
	play(buffer, size);
}

void AutumnAPI_Volume(int v) {
	sound_vol(v) {
	if (v > 50) {
		v = 50;
	}
}

void AutumnAPI_Init_SoundDev() {
	init();
}
