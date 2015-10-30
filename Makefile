#
# Copyright (c) 2015, Wind River Systems, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# These environment variables are defined externally by the SDK
# environment
ARCH := ${SDK_ZEPHYR_ARCH}
PLATFORM_CONFIG := ${SDK_ZEPHYR_PLATFORM}

MDEF_FILE = prj.mdef
KERNEL_TYPE = micro
CONF_FILE = prj_$(ARCH).conf

ZEPHYR_BASE := ${WIND_PROJECT_ROOT}/zephyr
export ZEPHYR_BASE

include ${ZEPHYR_BASE}/Makefile.inc
