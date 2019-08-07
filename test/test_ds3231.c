#include <stdbool.h>
#include <stdint.h>
#include "unity.h"
#include "mock_mgos_i2c.h"
// #include "mock_simple.h"

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
  mgos_i2c_read_reg_b_ExpectAndReturn(p, DS3231_I2C_ADDR, SECONDS_REGISTER, 10);

  res = ds3231_get_seconds();
  TEST_ASSERT_EQUAL_INT_MESSAGE(res, 10, "Should return number of secconds");
  TEST_ASSERT_MESSAGE(res > , "Should return number of secconds");
}
 