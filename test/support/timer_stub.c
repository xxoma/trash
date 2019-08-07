#include <stddef.h>
#include "timer_stub.h"

static timer_callback  m_cb;
static void          * m_cb_arg;
static int             m_msecs;
static int             m_flags;
static int             m_calls_num;


mgos_timer_id timer_stub_set(int msecs, int flags, timer_callback cb,
                                    void* cb_arg, int cmock_num_calls)
{
  m_msecs      = msecs;
  m_flags      = flags;
  m_cb         = cb;
  m_cb_arg     = cb_arg;
  m_calls_num += 1;

  return 1;
}

void timer_stub_clear(void)
{
  m_msecs       = 0;
  m_flags       = 0;
  m_cb          = NULL;
  m_cb_arg      = NULL;
  m_calls_num   = 0;
}

bool timer_stub_fire(void)
{
  if(m_cb != NULL) {
    m_cb(m_cb_arg);
    return true;
  }
  return false;
}

timer_callback  timer_stub_callback(void)  { return m_cb; }
int             timer_stub_calls_num(void) { return m_calls_num; }
int             timer_stub_msecs(void)     { return m_msecs; }
int             timer_stub_flags(void)     { return m_flags; }