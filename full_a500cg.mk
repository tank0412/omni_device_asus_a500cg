#
# Copyright 2013 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# Get the long list of APNs
PRODUCT_COPY_FILES := device/asus/a500cg/configs/apns-conf.xml:system/etc/apns-conf.xml

# Inherit from the common Open Source product configuration
$(call inherit-product, vendor/omni/config/gsm.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/aosp_base_telephony.mk)
$(call inherit-product, vendor/omni/config/common.mk)
#$(call inherit-product, $(SRC_TARGET_DIR)/product/full_x86.mk)
$(call inherit-product, device/asus/a500cg/device.mk)
#$(call inherit-product, vendor/asus/a500cg/a500cg-vendor.mk)
#$(call inherit-product-if-exists, vendor/google/gapps/gapps.mk)
# Inherit common CM stuff


PRODUCT_NAME := omni_a500cg
PRODUCT_DEVICE := a500cg
PRODUCT_BRAND := Android
PRODUCT_MODEL := ASUS_T00F
PRODUCT_MANUFACTURER := asus


