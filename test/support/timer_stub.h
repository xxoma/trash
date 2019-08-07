#ifndef _TIMER_STUB_H
#define _TIMER_STUB_H

#include <stdbool.h>
#include "unity.h"
#include "mgos_timers.h"

mgos_timer_id   timer_stub_set(int msecs, int flags, timer_callback cb,
                                void* cb_arg, int cmock_num_calls);
void            timer_stub_clear(void);
bool            timer_stub_fire(void);
timer_callback  timer_stub_callback(void);
int             timer_stub_calls_num(void);
int             timer_stub_msecs(void);
int             timer_stub_flags(void);

#ifndef TEST_ASSERT_TIMER
#define TEST_ASSERT_TIMER(calls_num, flags, msecs)                            \
  do {                                                                        \
    TEST_ASSERT_MESSAGE(timer_stub_callback() != NULL, "Timer was not set");  \
    TEST_ASSERT_EQUAL_MESSAGE(calls_num, timer_stub_calls_num(),              \
                              "Unexpected calls number");                     \
    TEST_ASSERT_EQUAL_MESSAGE(flags, timer_stub_flags(),                      \
                              "Unexpected flags");                            \
    TEST_ASSERT_EQUAL_MESSAGE(msecs, timer_stub_msecs(),                      \
                              "Unexpected interval");                         \
  } while (0)
#endif // TEST_ASSERT_TIMER

#endif // _TIMER_STUB_H