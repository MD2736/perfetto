/*
 * Copyright (C) 2023 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SRC_SHARED_LIB_TEST_PROTOS_LIBRARY_INTERNALS_GALAXIES_PZC_H_
#define SRC_SHARED_LIB_TEST_PROTOS_LIBRARY_INTERNALS_GALAXIES_PZC_H_

#include <stdbool.h>
#include <stdint.h>

#include "perfetto/public/pb_macros.h"
#include "src/shared_lib/test/protos/upper_import.pzc.h"

PERFETTO_PB_ENUM(protozero_test_protos_Galaxy){
    PERFETTO_PB_ENUM_ENTRY(protozero_test_protos_MILKY_WAY) = 1,
    PERFETTO_PB_ENUM_ENTRY(protozero_test_protos_ANDROMEDA) = 2,
    PERFETTO_PB_ENUM_ENTRY(protozero_test_protos_SUNFLOWER) = 3,
};

#endif  // SRC_SHARED_LIB_TEST_PROTOS_LIBRARY_INTERNALS_GALAXIES_PZC_H_
