#include "build/tests/temp/_test_ds3231.c"
#include "ds3231.h"
#include "unity.h"




void setUp(void)

{





_Bool 

    res = 

          0

               ;



  if ((res)) {} else {UnityFail( ((" Expression Evaluated To FALSE")), (UNITY_UINT)((UNITY_UINT)(10)));};

}



void tearDown(void)

{

}



void test_ds3231_get_seconds()

{

  int res;



  struct mgos_i2c *i2c = {};



  mgos_i2c_read_reg_b_ExpectAndReturn(i2c, 0x68, 0, 10);

  res = ds3231_get_seconds();

  UnityAssertEqualNumber((UNITY_INT)((res)), (UNITY_INT)((10)), (("Should return number of secconds")), (UNITY_UINT)(25), UNITY_DISPLAY_STYLE_INT);

}
