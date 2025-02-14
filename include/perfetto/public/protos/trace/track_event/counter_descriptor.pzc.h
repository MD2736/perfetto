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

#ifndef INCLUDE_PERFETTO_PUBLIC_PROTOS_TRACE_TRACK_EVENT_COUNTER_DESCRIPTOR_PZC_H_
#define INCLUDE_PERFETTO_PUBLIC_PROTOS_TRACE_TRACK_EVENT_COUNTER_DESCRIPTOR_PZC_H_

#include <stdbool.h>
#include <stdint.h>

#include "perfetto/public/pb_macros.h"

PERFETTO_PB_ENUM_IN_MSG(perfetto_protos_CounterDescriptor, BuiltinCounterType){
    PERFETTO_PB_ENUM_IN_MSG_ENTRY(perfetto_protos_CounterDescriptor,
                                  COUNTER_UNSPECIFIED) = 0,
    PERFETTO_PB_ENUM_IN_MSG_ENTRY(perfetto_protos_CounterDescriptor,
                                  COUNTER_THREAD_TIME_NS) = 1,
    PERFETTO_PB_ENUM_IN_MSG_ENTRY(perfetto_protos_CounterDescriptor,
                                  COUNTER_THREAD_INSTRUCTION_COUNT) = 2,
};

PERFETTO_PB_ENUM_IN_MSG(perfetto_protos_CounterDescriptor, Unit){
    PERFETTO_PB_ENUM_IN_MSG_ENTRY(perfetto_protos_CounterDescriptor,
                                  UNIT_UNSPECIFIED) = 0,
    PERFETTO_PB_ENUM_IN_MSG_ENTRY(perfetto_protos_CounterDescriptor,
                                  UNIT_TIME_NS) = 1,
    PERFETTO_PB_ENUM_IN_MSG_ENTRY(perfetto_protos_CounterDescriptor,
                                  UNIT_COUNT) = 2,
    PERFETTO_PB_ENUM_IN_MSG_ENTRY(perfetto_protos_CounterDescriptor,
                                  UNIT_SIZE_BYTES) = 3,
};

PERFETTO_PB_MSG(perfetto_protos_CounterDescriptor);
PERFETTO_PB_FIELD(perfetto_protos_CounterDescriptor,
                  VARINT,
                  enum perfetto_protos_CounterDescriptor_BuiltinCounterType,
                  type,
                  1);
PERFETTO_PB_FIELD(perfetto_protos_CounterDescriptor,
                  STRING,
                  const char*,
                  categories,
                  2);
PERFETTO_PB_FIELD(perfetto_protos_CounterDescriptor,
                  VARINT,
                  enum perfetto_protos_CounterDescriptor_Unit,
                  unit,
                  3);
PERFETTO_PB_FIELD(perfetto_protos_CounterDescriptor,
                  STRING,
                  const char*,
                  unit_name,
                  6);
PERFETTO_PB_FIELD(perfetto_protos_CounterDescriptor,
                  VARINT,
                  int64_t,
                  unit_multiplier,
                  4);
PERFETTO_PB_FIELD(perfetto_protos_CounterDescriptor,
                  VARINT,
                  bool,
                  is_incremental,
                  5);

#endif  // INCLUDE_PERFETTO_PUBLIC_PROTOS_TRACE_TRACK_EVENT_COUNTER_DESCRIPTOR_PZC_H_
