/*
 * Copyright (c) 2014-2018 Cesanta Software Limited
 * All rights reserved
 *
 * Licensed under the Apache License, Version 2.0 (the ""License"");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an ""AS IS"" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "mgos.h"
#include "ds3231.h"

static void timer_cb(void *i2c) {

  // char seconds = 0;
  // char minutes = 0;

  // seconds = mgos_i2c_read_reg_b(i2c, 0x68, 00);
  // seconds = (seconds>>4) * 10 + (seconds & 0xF);

  // minutes = mgos_i2c_read_reg_b(i2c, 0x68, 01);
  // minutes = (minutes>>4) * 10 + (minutes & 0xF);

  LOG(LL_INFO,
      ("uptime: %.2lf, RAM: %lu, %lu free",
       mgos_uptime(), (unsigned long) mgos_get_heap_size(),
       (unsigned long) mgos_get_free_heap_size()));
  LOG(LL_INFO, ("00H: %d", ds3231_get_seconds()));
  LOG(LL_INFO, ("00H: %d", ds3231_get_minutes()));
  LOG(LL_INFO, ("00H: %d", ds3231_get_hours()));
  (void) i2c;
}

enum mgos_app_init_result mgos_app_init(void) {
  mgos_set_timer(1000 /* ms */, MGOS_TIMER_REPEAT, timer_cb, NULL);
  return MGOS_APP_INIT_SUCCESS;
}
