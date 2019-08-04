#include "unity.h"

#include "ds3231.h"

void setUp(void)
{

bool res = false;

  TEST_ASSERT(res);
}

void tearDown(void)
{
}

void test_ds3231_get_seconds()
{
  int res;

  struct mgos_i2c *i2c = {};

  mgos_i2c_read_reg_b_ExpectAndReturn(i2c, DS3231_I2C_ADDR, SECONDS_REGISTER, 10);
  res = ds3231_get_seconds();
  TEST_ASSERT_EQUAL_INT_MESSAGE(res, 10, "Should return number of secconds");
}
 