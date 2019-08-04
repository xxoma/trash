#include "unity.h"

#include "simple.h"

void setUp(void)
{

bool res = false;

  TEST_ASSERT(res);
}

void tearDown(void)
{
}

void test_simple_func()
{
  bool res;
  res = simple_func();
  TEST_ASSERT_MESSAGE(res, "Should return TRUE");
}