#include "build/tests/temp/_test_ds3231.c"
#include "ds3231.h"
#include "mock_mgos_i2c.h"
#include "unity.h"






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

  void *a = &i2c;



  mgos_i2c_get_global_CMockExpectAndReturn(25, a);





  res = ds3231_get_seconds();

  UnityAssertEqualNumber((UNITY_INT)((res)), (UNITY_INT)((10)), (("Should return number of secconds")), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_INT);

}
