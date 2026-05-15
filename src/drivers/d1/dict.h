#ifndef GPIO_DICT_H
#define GPIO_DICT_H

#define AXP_I2C_ADDR 0x34
#define AXP_BATT_VOLT_H 0x78
#define AXP_BATT_VOLT_L 0x79
#define AXP_BATT_PERCENT 0xB9	
#define AXP_ADDR 0x34
#define AXP_P_OFF 0x32
#define P_OFF_BIT 0x80
#define TOUCH_ADDR 0x5D
#define CCU_BASE            0x02001000
#define GPIO_BASE           0x02000000
#define SDMMC0_CLK_REG      (CCU_BASE + 0x830)
#define PF_CFG0_REG         (GPIO_BASE + 0x00B0)

#endif
