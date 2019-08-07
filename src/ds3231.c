#include "mgos.h"
#include "mgos_i2c.h"

#include "ds3231.h"

static void ds3231_err_msg()
{
    LOG(LL_ERROR, ("i2c bus is disabled, set i2c.enable=true"));
}

int ds3231_get_seconds()
{
    struct mgos_i2c *i2c = mgos_i2c_get_global();

    if (!i2c) {
        ds3231_err_msg();

        return 0;
    }


    char seconds = 0;

    seconds = mgos_i2c_read_reg_b(i2c, DS3231_I2C_ADDR, SECONDS_REGISTER);

    return (seconds>>4) * 10 + (seconds & 0xF);
}

int ds3231_get_minutes()
{
    struct mgos_i2c *i2c = mgos_i2c_get_global();

    if (!i2c) {
        ds3231_err_msg();
        
        return 0;
    }

    char minutes = 0;

    minutes = mgos_i2c_read_reg_b(i2c, DS3231_I2C_ADDR, MINUTES_REGISTER);

    return (minutes>>4) * 10 + (minutes & 0xF);
}

int ds3231_get_hours()
{
    struct mgos_i2c *i2c = mgos_i2c_get_global();

    if (!i2c) {
        ds3231_err_msg();
        
        return 0;
    }

    char hours = 0;

    hours = mgos_i2c_read_reg_b(i2c, DS3231_I2C_ADDR, HOUR_REGISTER);

    return (hours & 0x1F);
}

bool ds3231_set_time(int hours, int minutes, int seconds)
{
    struct mgos_i2c *i2c = mgos_i2c_get_global();

    if (!i2c) {
        ds3231_err_msg();
        
        return 0;
    }

    return 0;
    ///
}