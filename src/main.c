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
#include "ssd1306.h"

static void timer_cb(void *arg) {

  char hours[3];
  char minutes[3];
  char seconds[3];

  snprintf(hours, 3, "%d", ds3231_get_hours());
  snprintf(minutes, 3, "%d", ds3231_get_minutes());
  snprintf(seconds, 3, "%d", ds3231_get_seconds());

  mgos_ssd1306_clear(arg);
  mgos_ssd1306_draw_hline(arg, 0, 0, 128, SSD1306_COLOR_WHITE);
  if (ds3231_get_hours() < 9) {
    mgos_ssd1306_draw_string(arg, 30, 11, "0");
  }
  mgos_ssd1306_draw_string(arg, 40, 11, hours);
  mgos_ssd1306_draw_string(arg, 50, 11, ":");
  if (ds3231_get_minutes() < 9) {
    mgos_ssd1306_draw_string(arg, 60, 11, "0");
  }
  mgos_ssd1306_draw_string(arg, 70, 11, minutes);
  mgos_ssd1306_draw_string(arg, 80, 11, ":");
  if (ds3231_get_seconds() < 9) {
    mgos_ssd1306_draw_string(arg, 90, 11, "0");
  }
  mgos_ssd1306_draw_string(arg, 100, 11, seconds);
  mgos_ssd1306_draw_hline(arg, 0, 31, 128, SSD1306_COLOR_WHITE);
  mgos_ssd1306_refresh(arg, true);

  LOG(LL_INFO,
      ("uptime: %.2lf, RAM: %lu, %lu free",
       mgos_uptime(), (unsigned long) mgos_get_heap_size(),
       (unsigned long) mgos_get_free_heap_size()));
  LOG(LL_INFO, ("00H: %d", ds3231_get_seconds()));
  LOG(LL_INFO, ("00H: %d", ds3231_get_minutes()));
  LOG(LL_INFO, ("00H: %d", ds3231_get_hours()));
  LOG(LL_INFO, ("is 12: %d", ds3231_get_is_12_hour_format()));
  (void) arg;
}

enum mgos_app_init_result mgos_app_init(void) {
  //ds3231_set_time(4, 57, 0);

  mgos_ssd1306_init();

  struct mgos_ssd1306* dsp = mgos_ssd1306_get_global();

  mgos_ssd1306_select_font (dsp, 2);

  mgos_set_timer(1000 /* ms */, MGOS_TIMER_REPEAT, timer_cb, dsp);
  return MGOS_APP_INIT_SUCCESS;
}
