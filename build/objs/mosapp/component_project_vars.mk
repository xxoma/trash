# Automatically generated build file. Do not edit.
COMPONENT_INCLUDES += $(PROJECT_PATH)/mosapp/include
COMPONENT_LDFLAGS += -L$(BUILD_DIR_BASE)/mosapp $(BUILD_DIR_BASE)/libmbedtls-esp32-2.15.0.a $(BUILD_DIR_BASE)/libmongoose-esp32-2.15.0.a -Wl,--whole-archive -lmosapp -Wl,--no-whole-archive
COMPONENT_LINKER_DEPS += 
COMPONENT_SUBMODULES += 
COMPONENT_LIBRARIES += mosapp
component-mosapp-build: 
