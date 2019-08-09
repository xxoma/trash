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

    if (hours & 0x10) {
        hours = 10 + (hours & 0xF);
    } else if(hours & 0x20) {
        hours = 20 + (hours & 0xF);
    } else {
        hours = hours & 0xF;
    }

    return hours;
}

bool ds3231_set_time(char hours, char minutes, char seconds)
{

    if (hours > 23 || minutes > 59 || seconds > 59) {
        return false;
    }

    bool result = false;

    struct mgos_i2c *i2c = mgos_i2c_get_global();

    if (!i2c) {
        ds3231_err_msg();
        
        return false;
    }

    if (hours > 19) {
        hours = 0x20 | (hours % 10);
    } else if(hours > 9) {
        hours = 0x10 | (hours % 10);
    } else {
        hours = hours % 10;
    }

    result = mgos_i2c_write_reg_b(i2c, DS3231_I2C_ADDR, HOUR_REGISTER, hours);

    if (!result) {
        return false;
    }

    int l = 0;
    int h = 0;
    
        
    l = (minutes % 10);
    h = (minutes - l) / 10;

    minutes = h << 4 | l;

    result = mgos_i2c_write_reg_b(i2c, DS3231_I2C_ADDR, MINUTES_REGISTER, minutes);

    if (!result) {
        return false;
    }

    l = (seconds % 10);
    h = (seconds - l) / 10;

    seconds = h << 4 | l;

    result = mgos_i2c_write_reg_b(i2c, DS3231_I2C_ADDR, SECONDS_REGISTER, seconds);

    return result;
}

bool ds3231_get_is_12_hour_format()
{
    struct mgos_i2c *i2c = mgos_i2c_get_global();

    if (!i2c) {
        ds3231_err_msg();
        
        return 0;
    }

    char hours = 0;

    hours = mgos_i2c_read_reg_b(i2c, DS3231_I2C_ADDR, HOUR_REGISTER);

    return (64&hours) >> 6;
}