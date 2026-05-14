#ifndef DRV_H
#define DRV_H

//power.c
void power_off(void)
void reboot(void);

//sound.c
int init(void);
void play(uint8_t *buffer, uint32_t size);
void sound_vol(int vol);

//tick.c
uint32_t tick_ms(void);
void delay_ms(uint32_t ms);

//sim.c
int sim_init(void);
void send(const char *cmd);
int recv(uint8_t *buffer, uint32_t size);

//bat.c
int battery_percent(void);
uint32_t battery_voltage(void);

//cpu.c
const char* cpuv(void);
uint32_t total_ram(void);
uint32_t used_ram(void);

//fstor.c
int storage_init(void);
int write(const char *path, const void *data, uint32_t len);
int read(const char *path, void* buffer, uint32_t len);


#endif
