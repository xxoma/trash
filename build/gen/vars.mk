APP=trash
APP_BIN_LIBS=/home/sk/mos/trash/build/objs/libmbedtls-esp32-2.15.0.a /home/sk/mos/trash/build/objs/libmongoose-esp32-2.15.0.a
APP_CFLAGS=-DLFS_NO_DEBUG=1 -DMBEDTLS_ECP_ATCA=1 -DMBEDTLS_FREE_CERT_CHAIN=1 -DMBEDTLS_USER_CONFIG_FILE=\"mbedtls_platform_config.h\" -DMBEDTLS_X509_CA_CHAIN_ON_DISK=1 -DMGOS=1 -DMGOS_ENABLE_RPC_CHANNEL_HTTP=1 -DMGOS_ENABLE_SYS_SERVICE=1 -DMGOS_HAVE_ATCA=1 -DMGOS_HAVE_CA_BUNDLE=1 -DMGOS_HAVE_CORE=1 -DMGOS_HAVE_FREERTOS=1 -DMGOS_HAVE_I2C=1 -DMGOS_HAVE_MBEDTLS=1 -DMGOS_HAVE_MONGOOSE=1 -DMGOS_HAVE_RPC_COMMON=1 -DMGOS_HAVE_RPC_SERVICE_CONFIG=1 -DMGOS_HAVE_RPC_SERVICE_FS=1 -DMGOS_HAVE_RPC_UART=1 -DMGOS_HAVE_VFS_COMMON=1 -DMGOS_HAVE_VFS_FS_LFS=1 -DMGOS_HAVE_VFS_FS_SPIFFS=1 -DMGOS_HAVE_WIFI=1 -DMGOS_HAVE_ZZ_BOARDS=1 -DMGOS_LFS1_COMPAT=0 -DMGOS_WIFI_ENABLE_AP_STA=1 -DMG_ENABLE_DNS=1 -DMG_ENABLE_DNS_SERVER=1 -DMG_ENABLE_MQTT=1 -DMG_ENABLE_SNTP=1 -DMG_ENABLE_SSL=1 -DMG_SSL_IF=MG_SSL_IF_MBEDTLS -DMG_SSL_IF_MBEDTLS_FREE_CERTS=1
APP_CONF_SCHEMA=/home/sk/mos/trash/build/gen/mos_conf_schema.yml
APP_CXXFLAGS=-DLFS_NO_DEBUG=1 -DMBEDTLS_ECP_ATCA=1 -DMBEDTLS_FREE_CERT_CHAIN=1 -DMBEDTLS_USER_CONFIG_FILE=\"mbedtls_platform_config.h\" -DMBEDTLS_X509_CA_CHAIN_ON_DISK=1 -DMGOS=1 -DMGOS_ENABLE_RPC_CHANNEL_HTTP=1 -DMGOS_ENABLE_SYS_SERVICE=1 -DMGOS_HAVE_ATCA=1 -DMGOS_HAVE_CA_BUNDLE=1 -DMGOS_HAVE_CORE=1 -DMGOS_HAVE_FREERTOS=1 -DMGOS_HAVE_I2C=1 -DMGOS_HAVE_MBEDTLS=1 -DMGOS_HAVE_MONGOOSE=1 -DMGOS_HAVE_RPC_COMMON=1 -DMGOS_HAVE_RPC_SERVICE_CONFIG=1 -DMGOS_HAVE_RPC_SERVICE_FS=1 -DMGOS_HAVE_RPC_UART=1 -DMGOS_HAVE_VFS_COMMON=1 -DMGOS_HAVE_VFS_FS_LFS=1 -DMGOS_HAVE_VFS_FS_SPIFFS=1 -DMGOS_HAVE_WIFI=1 -DMGOS_HAVE_ZZ_BOARDS=1 -DMGOS_LFS1_COMPAT=0 -DMGOS_WIFI_ENABLE_AP_STA=1 -DMG_ENABLE_DNS=1 -DMG_ENABLE_DNS_SERVER=1 -DMG_ENABLE_MQTT=1 -DMG_ENABLE_SNTP=1 -DMG_ENABLE_SSL=1 -DMG_SSL_IF=MG_SSL_IF_MBEDTLS -DMG_SSL_IF_MBEDTLS_FREE_CERTS=1
APP_FS_FILES=/home/sk/mos/trash/deps/ca-bundle/fs/ca.pem /home/sk/mos/trash/fs/index.html
APP_INCLUDES=/home/sk/mos/trash/deps/freertos/include /home/sk/mos/trash/deps/freertos/include/esp32 /home/sk/mos/trash/deps/i2c/include /home/sk/mos/trash/deps/atca/include /home/sk/mos/trash/deps/atca/cryptoauthlib/lib /home/sk/mos/trash/deps/mbedtls/include /home/sk/mos/trash/deps/mbedtls/include/esp32 /home/sk/mos/trash/deps/mbedtls/mbedtls/include /home/sk/mos/trash/deps/vfs-common/include /home/sk/mos/trash/deps/vfs-common/include/esp32 /home/sk/mos/trash/deps/mongoose/include /home/sk/mos/trash/deps/vfs-fs-lfs/include /home/sk/mos/trash/deps/vfs-fs-lfs/littlefs /home/sk/mos/trash/deps/vfs-fs-lfs/littlefs1 /home/sk/mos/trash/deps/vfs-fs-spiffs/include /home/sk/mos/trash/deps/vfs-fs-spiffs/include/spiffs /home/sk/mos/trash/deps/vfs-fs-spiffs/include/esp32 /home/sk/mos/trash/deps/core/include /home/sk/mos/trash/deps/core/include/esp32 /home/sk/mos/trash/deps/rpc-common/include /home/sk/mos/trash/deps/rpc-service-config/include /home/sk/mos/trash/deps/rpc-service-fs/include /home/sk/mos/trash/deps/rpc-uart/include /home/sk/mos/trash/deps/wifi/include /home/sk/mos/trash/deps/wifi/include/esp32
APP_SOURCES=/home/sk/mos/trash/src/ds3231.c /home/sk/mos/trash/src/main.c /home/sk/mos/trash/src/simple.c /home/sk/mos/trash/build/gen/mgos_deps_init.c /home/sk/mos/trash/deps/freertos/src/mgos_freertos.c /home/sk/mos/trash/deps/freertos/src/mgos_freertos_core_dump.c /home/sk/mos/trash/deps/i2c/src/mgos_i2c_master.c /home/sk/mos/trash/deps/i2c/src/esp32/esp32_i2c_master.c /home/sk/mos/trash/deps/atca/src/mgos_atca.c /home/sk/mos/trash/deps/atca/cryptoauthlib/lib/atca_cfgs.c /home/sk/mos/trash/deps/atca/cryptoauthlib/lib/atca_command.c /home/sk/mos/trash/deps/atca/cryptoauthlib/lib/atca_device.c /home/sk/mos/trash/deps/atca/cryptoauthlib/lib/atca_iface.c /home/sk/mos/trash/deps/atca/cryptoauthlib/lib/basic/atca_basic.c /home/sk/mos/trash/deps/atca/cryptoauthlib/lib/basic/atca_helpers.c /home/sk/mos/trash/deps/atca/cryptoauthlib/lib/host/atca_host.c /home/sk/mos/trash/deps/vfs-common/src/mgos_vfs.c /home/sk/mos/trash/deps/vfs-common/src/mgos_vfs_dev.c /home/sk/mos/trash/deps/vfs-common/src/mgos_vfs_internal.c /home/sk/mos/trash/deps/vfs-common/src/esp32/esp32_fs.c /home/sk/mos/trash/deps/vfs-common/src/esp32/esp32_fs_crypt.c /home/sk/mos/trash/deps/vfs-common/src/esp32/esp32_vfs_dev_partition.c /home/sk/mos/trash/deps/vfs-fs-lfs/src/mgos_vfs_lfs.c /home/sk/mos/trash/deps/vfs-fs-lfs/littlefs/lfs.c /home/sk/mos/trash/deps/vfs-fs-lfs/littlefs/lfs_util.c /home/sk/mos/trash/deps/vfs-fs-lfs/littlefs1/lfs1.c /home/sk/mos/trash/deps/vfs-fs-lfs/littlefs1/lfs1_util.c /home/sk/mos/trash/deps/vfs-fs-spiffs/src/mgos_vfs_fs_spiffs.c /home/sk/mos/trash/deps/vfs-fs-spiffs/src/spiffs/spiffs_cache.c /home/sk/mos/trash/deps/vfs-fs-spiffs/src/spiffs/spiffs_check.c /home/sk/mos/trash/deps/vfs-fs-spiffs/src/spiffs/spiffs_gc.c /home/sk/mos/trash/deps/vfs-fs-spiffs/src/spiffs/spiffs_hydrogen.c /home/sk/mos/trash/deps/vfs-fs-spiffs/src/spiffs/spiffs_nucleus.c /home/sk/mos/trash/deps/core/src/mgos_core.c /home/sk/mos/trash/deps/rpc-common/src/mg_rpc.c /home/sk/mos/trash/deps/rpc-common/src/mg_rpc_channel.c /home/sk/mos/trash/deps/rpc-common/src/mg_rpc_channel_http.c /home/sk/mos/trash/deps/rpc-common/src/mgos_rpc.c /home/sk/mos/trash/deps/rpc-service-config/src/mgos_service_config.c /home/sk/mos/trash/deps/rpc-service-fs/src/mgos_service_filesystem.c /home/sk/mos/trash/deps/rpc-uart/src/mgos_rpc_channel_uart.c /home/sk/mos/trash/deps/wifi/src/mgos_wifi.c /home/sk/mos/trash/deps/wifi/src/mjs_wifi.c /home/sk/mos/trash/deps/wifi/src/esp32/esp32_wifi.c
APP_VERSION=1.0
BOARD=
BUILD_DIR=/home/sk/mos/trash/build/objs
ESP_IDF_EXTRA_COMPONENTS=
ESP_IDF_SDKCONFIG_OPTS= CONFIG_SUPPORT_STATIC_ALLOCATION=y 
FFI_SYMBOLS=
FS_STAGING_DIR=/home/sk/mos/trash/build/fs
FW_DIR=/home/sk/mos/trash/build/fw
GEN_DIR=/home/sk/mos/trash/build/gen
MANIFEST_FINAL=/home/sk/mos/trash/build/gen/mos_final.yml
MGOS=1
MGOS_HAVE_ATCA=1
MGOS_HAVE_CA_BUNDLE=1
MGOS_HAVE_CORE=1
MGOS_HAVE_FREERTOS=1
MGOS_HAVE_I2C=1
MGOS_HAVE_MBEDTLS=1
MGOS_HAVE_MONGOOSE=1
MGOS_HAVE_RPC_COMMON=1
MGOS_HAVE_RPC_SERVICE_CONFIG=1
MGOS_HAVE_RPC_SERVICE_FS=1
MGOS_HAVE_RPC_UART=1
MGOS_HAVE_VFS_COMMON=1
MGOS_HAVE_VFS_FS_LFS=1
MGOS_HAVE_VFS_FS_SPIFFS=1
MGOS_HAVE_WIFI=1
MGOS_HAVE_ZZ_BOARDS=1
MGOS_PATH=/home/sk/mos/trash/deps/modules/mongoose-os
MGOS_WIFI_ENABLE_AP_STA=0
PLATFORM=esp32