#include <stdbool.h>
#include <stdint.h>
#include "unity.h"
#include "mock_mgos_i2c.h"

#include "ds3231.h"

void setUp(void)
{

}

void tearDown(void)
{
}

void test_ds3231_get_seconds()
{
  int res;

  struct mgos_i2c i2c = {0};
  void *p = &i2c;

  mgos_i2c_get_global_ExpectAndReturn(p);
  mgos_i2c_read_reg_b_ExpectAndReturn(p, DS3231_I2C_ADDR, SECONDS_REGISTER, 37); //00100101 = 25 seconds register value

  res = ds3231_get_seconds();
  TEST_ASSERT_EQUAL_INT_MESSAGE(res, 25, "Should return number of secconds");
}

void test_ds3231_get_minutes()
{
  int res;

  struct mgos_i2c i2c = {0};
  void *p = &i2c;

  mgos_i2c_get_global_ExpectAndReturn(p);
  mgos_i2c_read_reg_b_ExpectAndReturn(p, DS3231_I2C_ADDR, MINUTES_REGISTER, 89); //1011001 59 minutes register value

  res = ds3231_get_minutes();
  TEST_ASSERT_EQUAL_INT_MESSAGE(res, 59, "Should return number of secconds");
}

void test_ds3231_get_hours()
{
  int res;

  struct mgos_i2c i2c = {0};
  void *p = &i2c;

  mgos_i2c_get_global_ExpectAndReturn(p);
  mgos_i2c_read_reg_b_ExpectAndReturn(p, DS3231_I2C_ADDR, HOUR_REGISTER, 35); //00100011 23 hours register value

  res = ds3231_get_hours();
  TEST_ASSERT_EQUAL_INT_MESSAGE(res, 23, "Should return number of secconds");
}

void test_ds3231_set_seconds()
{
  bool res;

  struct mgos_i2c i2c = {0};
  void *p = &i2c;

  mgos_i2c_get_global_ExpectAndReturn(p);
  mgos_i2c_write_reg_b_ExpectAndReturn(p, DS3231_I2C_ADDR, SECONDS_REGISTER, 37, true);

  res = ds3231_set_seconds(25);

  TEST_ASSERT_TRUE_MESSAGE(res, "Should return true if set seconds success");
}

void test_ds3231_set_minutes()
{
  bool res;

  struct mgos_i2c i2c = {0};
  void *p = &i2c;

  mgos_i2c_get_global_ExpectAndReturn(p);
  mgos_i2c_write_reg_b_ExpectAndReturn(p, DS3231_I2C_ADDR, MINUTES_REGISTER, 89, true);

  res = ds3231_set_minutes(59);
  
  TEST_ASSERT_TRUE_MESSAGE(res, "Should return true if set minutes success");
}

void test_ds3231_set_hours()
{
  bool res;

  struct mgos_i2c i2c = {0};
  void *p = &i2c;

  mgos_i2c_get_global_ExpectAndReturn(p);
  mgos_i2c_write_reg_b_ExpectAndReturn(p, DS3231_I2C_ADDR, HOUR_REGISTER, 35, true);

  res = ds3231_set_hours(23);
  
  TEST_ASSERT_TRUE_MESSAGE(res, "Should return true if set hours success");
}

void test_ds3231_get_is_12_hour_format()
{
  bool res;

  struct mgos_i2c i2c = {0};
  void *p = &i2c;

  mgos_i2c_get_global_ExpectAndReturn(p);
  mgos_i2c_read_reg_b_ExpectAndReturn(p, DS3231_I2C_ADDR, HOUR_REGISTER, 64);

  res = ds3231_get_is_12_hour_format();

  TEST_ASSERT_TRUE_MESSAGE(res, "Should return true if set time success");
}

void test_ds3231_get_is_24_hour_format()
{
  bool res;

  struct mgos_i2c i2c = {0};
  void *p = &i2c;

  mgos_i2c_get_global_ExpectAndReturn(p);
  mgos_i2c_read_reg_b_ExpectAndReturn(p, DS3231_I2C_ADDR, HOUR_REGISTER, 31);

  res = ds3231_get_is_12_hour_format();

  TEST_ASSERT_FALSE_MESSAGE(res, "Should return true if set time success");
}