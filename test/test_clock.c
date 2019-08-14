#include <stdbool.h>
#include "unity.h"
#include "clock.h"
#include "mock_ds3231.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_clock_get_now_time()
{

    struct time now;

    ds3231_get_seconds_ExpectAndReturn(15);
    ds3231_get_minutes_ExpectAndReturn(30);
    ds3231_get_hours_ExpectAndReturn(16);

    clock_get_current_time(&now);

    TEST_ASSERT_EQUAL_INT_MESSAGE(now.seconds, 15, "Should return actual seconds");
    TEST_ASSERT_EQUAL_INT_MESSAGE(now.minutes, 30, "Should return actual minutes");
    TEST_ASSERT_EQUAL_INT_MESSAGE(now.hours, 16, "Should return actual hours");
}

void test_clock_set_wrong_now_time()
{

    struct time now = {100, 100, 24};

    bool result = false;

    ds3231_set_seconds_ExpectAndReturn(100, false);
    ds3231_set_minutes_ExpectAndReturn(100, false);
    ds3231_set_hours_ExpectAndReturn(24, false);

    result = clock_set_time(&now);

    TEST_ASSERT_FALSE_MESSAGE(result, "Should return false if set time has wrong format");
}

void test_clock_set_time()
{

    struct time now = {15, 30, 16};

    bool result = false;

    ds3231_set_seconds_ExpectAndReturn(15, true);
    ds3231_set_minutes_ExpectAndReturn(30, true);
    ds3231_set_hours_ExpectAndReturn(16, true);

    result = clock_set_time(&now);

    TEST_ASSERT_TRUE_MESSAGE(result, "Should return true if set time succes");
}

void test_clock_get_time_str()
{
    struct time now = {5, 8, 4};

    char buffer[8] = {};
    char h_m_separator = ':';
    char m_s_separator = ':';

    clock_get_time_str(&now, buffer, h_m_separator, m_s_separator, true);

    TEST_ASSERT_EQUAL_STRING_MESSAGE("04:08:05", buffer, "Buffer should be equal to expected string"); 
}