LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := pack.c
LOCAL_CFLAGS += -I/usr/include/
LOCAL_MODULE := pack_intel
LOCAL_MODULE_TAGS := optional
include $(BUILD_HOST_EXECUTABLE)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := unpack.c
LOCAL_CFLAGS += -I/usr/include/
LOCAL_MODULE := unpack_intel
LOCAL_MODULE_TAGS := optional
include $(BUILD_HOST_EXECUTABLE)
$(call dist-for-goals,dist_files,$(LOCAL_BUILT_MODULE))
