#ifndef API_H
#define API_H

uint32_t AutumnAPI_Get_TickMS(void);
void AutumnAPI_DelayMS(uint32_t ms);
void AutumnAPI_PowerOff(void);
void AutumnAPI_Reboot(void);
void AutumnAPI_SIMStatus(void);
void AutumnAPI_ModemSnd(const char *cmd);
void AutumnAPI_Read_Battery_Level();
void AutumnAPI_CPU_Vendor();
void AutumnAPI_Mount_FS();

#endif
