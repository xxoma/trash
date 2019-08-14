#ifndef _DS3231_H
#define _DS3231_H
#include <stdbool.h>

#define DS3231_I2C_ADDR 0x68

#define SECONDS_REGISTER 0
#define MINUTES_REGISTER 1
#define HOUR_REGISTER 2

int ds3231_get_seconds();
int ds3231_get_minutes();
int ds3231_get_hours();
bool ds3231_get_is_12_hour_format();
bool ds3231_set_seconds(char seconds);
bool ds3231_set_minutes(char minutes);
bool ds3231_set_hours(char hours);

#endif