#include "drivers.h"
#include <rtthread.h>
#include <rtdevice.h>
#include "dict.h"

int battery_percent(void) {
    struct rt_i2c_bus_device *i2c_bus;
    i2c_bus = (struct rt_i2c_bus_device *)rt_device_find("i2c0");
    
    if (i2c_bus != RT_NULL) {
        uint8_t reg = AXP_BATT_PERCENT;
        uint8_t percent = 0;
        
        struct rt_i2c_msg msgs[2];
        msgs[0].addr  = AXP_I2C_ADDR;
        msgs[0].flags = RT_I2C_WR;
        msgs[0].buf   = &reg;
        msgs[0].len   = 1;

        msgs[1].addr  = AXP_I2C_ADDR;
        msgs[1].flags = RT_I2C_RD;
        msgs[1].buf   = &percent;
        msgs[1].len   = 1;

        if (rt_i2c_transfer(i2c_bus, msgs, 2) == 2) {
            return (int)percent;
        }
    }
    return -1;
}

uint32_t battery_voltage(void) {
    struct rt_i2c_bus_device *i2c_bus;
    i2c_bus = (struct rt_i2c_bus_device *)rt_device_find("i2c0");
    
    if (i2c_bus != RT_NULL) {
        uint8_t reg = AXP_BATT_VOLT_H;
        uint8_t data[2];
        
        struct rt_i2c_msg msgs[2];
        msgs[0].addr  = AXP_I2C_ADDR;
        msgs[0].flags = RT_I2C_WR;
        msgs[0].buf   = &reg;
        msgs[0].len   = 1;

        msgs[1].addr  = AXP_I2C_ADDR;
        msgs[1].flags = RT_I2C_RD;
        msgs[1].buf   = data;
        msgs[1].len   = 2;

        if (rt_i2c_transfer(i2c_bus, msgs, 2) == 2) {
            return (uint32_t)((data[0] << 4) | (data[1] & 0x0F));
        }
    }
    return 0;
}
