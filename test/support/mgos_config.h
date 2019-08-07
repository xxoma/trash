#ifndef _MGOS_CONFIG_H
#define _MGOS_CONFIG_H

#include <stdbool.h>
#include <stdint.h>
#include "periph_defs.h"
#include "i2c_struct.h"

struct mgos_config {
  int mock;
};
struct mgos_config mgos_sys_config;

struct mgos_config_i2c {
  int unit_no;
  int enable;
  int freq;
  int debug;
  int sda_gpio;
  int scl_gpio;
};

struct mgos_i2c {
  struct mgos_config_i2c cfg;
  uint32_t scl_in_sig, scl_out_sig;
  uint32_t sda_in_sig, sda_out_sig;
  periph_module_t pm;
  i2c_dev_t *dev;
  int freq;
  bool debug;
  bool stopped;
};

const char *mgos_sys_config_get_api_url();
int         mgos_sys_config_get_sensors_sampling_rate();
int         mgos_sys_config_get_sensors_samples_per_report();
int         mgos_sys_config_get_system_sta_switch_n();
const char *mgos_sys_config_get_system_reports_path();
int         mgos_sys_config_get_wifi_sta1_enable();
int         mgos_sys_config_get_wifi_sta2_enable();
int         mgos_sys_config_get_wifi_sta_cfg_idx();
void        mgos_sys_config_set_wifi_sta_cfg_idx(int);
bool        save_cfg(const struct mgos_config *cfg, char **msg);

#endif // _MGOS_CONFIG_H
