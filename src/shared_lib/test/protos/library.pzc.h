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

#ifndef SRC_SHARED_LIB_TEST_PROTOS_LIBRARY_PZC_H_
#define SRC_SHARED_LIB_TEST_PROTOS_LIBRARY_PZC_H_

#include <stdbool.h>
#include <stdint.h>

#include "perfetto/public/pb_macros.h"
#include "src/shared_lib/test/protos/library_internals/galaxies.pzc.h"

PERFETTO_PB_ENUM_IN_MSG(protozero_test_protos_TransgalacticMessage,
                        MessageType){
    PERFETTO_PB_ENUM_IN_MSG_ENTRY(protozero_test_protos_TransgalacticMessage,
                                  REGULAR) = 0,
    PERFETTO_PB_ENUM_IN_MSG_ENTRY(protozero_test_protos_TransgalacticMessage,
                                  EXPRESS) = 1,
};

PERFETTO_PB_MSG(protozero_test_protos_TransgalacticMessage);
PERFETTO_PB_FIELD(protozero_test_protos_TransgalacticMessage,
                  VARINT,
                  enum protozero_test_protos_Galaxy,
                  origin_galaxy,
                  1);
PERFETTO_PB_FIELD(protozero_test_protos_TransgalacticMessage,
                  STRING,
                  const char*,
                  origin_planet,
                  2);
PERFETTO_PB_FIELD(protozero_test_protos_TransgalacticMessage,
                  VARINT,
                  enum protozero_test_protos_Galaxy,
                  destination_galaxy,
                  3);
PERFETTO_PB_FIELD(protozero_test_protos_TransgalacticMessage,
                  STRING,
                  const char*,
                  destination_planet,
                  4);
PERFETTO_PB_FIELD(protozero_test_protos_TransgalacticMessage,
                  STRING,
                  const char*,
                  proto_message,
                  5);

#endif  // SRC_SHARED_LIB_TEST_PROTOS_LIBRARY_PZC_H_
