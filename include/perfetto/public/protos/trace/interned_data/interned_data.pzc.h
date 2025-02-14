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

#ifndef INCLUDE_PERFETTO_PUBLIC_PROTOS_TRACE_INTERNED_DATA_INTERNED_DATA_PZC_H_
#define INCLUDE_PERFETTO_PUBLIC_PROTOS_TRACE_INTERNED_DATA_INTERNED_DATA_PZC_H_

#include <stdbool.h>
#include <stdint.h>

#include "perfetto/public/pb_macros.h"

PERFETTO_PB_MSG_DECL(perfetto_protos_Callstack);
PERFETTO_PB_MSG_DECL(perfetto_protos_DebugAnnotationName);
PERFETTO_PB_MSG_DECL(perfetto_protos_DebugAnnotationValueTypeName);
PERFETTO_PB_MSG_DECL(perfetto_protos_EventCategory);
PERFETTO_PB_MSG_DECL(perfetto_protos_EventName);
PERFETTO_PB_MSG_DECL(perfetto_protos_Frame);
PERFETTO_PB_MSG_DECL(perfetto_protos_HistogramName);
PERFETTO_PB_MSG_DECL(perfetto_protos_InternedGpuRenderStageSpecification);
PERFETTO_PB_MSG_DECL(perfetto_protos_InternedGraphicsContext);
PERFETTO_PB_MSG_DECL(perfetto_protos_InternedString);
PERFETTO_PB_MSG_DECL(perfetto_protos_LogMessageBody);
PERFETTO_PB_MSG_DECL(perfetto_protos_Mapping);
PERFETTO_PB_MSG_DECL(perfetto_protos_ProfiledFrameSymbols);
PERFETTO_PB_MSG_DECL(perfetto_protos_SourceLocation);
PERFETTO_PB_MSG_DECL(perfetto_protos_UnsymbolizedSourceLocation);

PERFETTO_PB_MSG(perfetto_protos_InternedData);
PERFETTO_PB_FIELD(perfetto_protos_InternedData,
                  MSG,
                  perfetto_protos_EventCategory,
                  event_categories,
                  1);
PERFETTO_PB_FIELD(perfetto_protos_InternedData,
                  MSG,
                  perfetto_protos_EventName,
                  event_names,
                  2);
PERFETTO_PB_FIELD(perfetto_protos_InternedData,
                  MSG,
                  perfetto_protos_DebugAnnotationName,
                  debug_annotation_names,
                  3);
PERFETTO_PB_FIELD(perfetto_protos_InternedData,
                  MSG,
                  perfetto_protos_DebugAnnotationValueTypeName,
                  debug_annotation_value_type_names,
                  27);
PERFETTO_PB_FIELD(perfetto_protos_InternedData,
                  MSG,
                  perfetto_protos_SourceLocation,
                  source_locations,
                  4);
PERFETTO_PB_FIELD(perfetto_protos_InternedData,
                  MSG,
                  perfetto_protos_UnsymbolizedSourceLocation,
                  unsymbolized_source_locations,
                  28);
PERFETTO_PB_FIELD(perfetto_protos_InternedData,
                  MSG,
                  perfetto_protos_LogMessageBody,
                  log_message_body,
                  20);
PERFETTO_PB_FIELD(perfetto_protos_InternedData,
                  MSG,
                  perfetto_protos_HistogramName,
                  histogram_names,
                  25);
PERFETTO_PB_FIELD(perfetto_protos_InternedData,
                  MSG,
                  perfetto_protos_InternedString,
                  build_ids,
                  16);
PERFETTO_PB_FIELD(perfetto_protos_InternedData,
                  MSG,
                  perfetto_protos_InternedString,
                  mapping_paths,
                  17);
PERFETTO_PB_FIELD(perfetto_protos_InternedData,
                  MSG,
                  perfetto_protos_InternedString,
                  source_paths,
                  18);
PERFETTO_PB_FIELD(perfetto_protos_InternedData,
                  MSG,
                  perfetto_protos_InternedString,
                  function_names,
                  5);
PERFETTO_PB_FIELD(perfetto_protos_InternedData,
                  MSG,
                  perfetto_protos_ProfiledFrameSymbols,
                  profiled_frame_symbols,
                  21);
PERFETTO_PB_FIELD(perfetto_protos_InternedData,
                  MSG,
                  perfetto_protos_Mapping,
                  mappings,
                  19);
PERFETTO_PB_FIELD(perfetto_protos_InternedData,
                  MSG,
                  perfetto_protos_Frame,
                  frames,
                  6);
PERFETTO_PB_FIELD(perfetto_protos_InternedData,
                  MSG,
                  perfetto_protos_Callstack,
                  callstacks,
                  7);
PERFETTO_PB_FIELD(perfetto_protos_InternedData,
                  MSG,
                  perfetto_protos_InternedString,
                  vulkan_memory_keys,
                  22);
PERFETTO_PB_FIELD(perfetto_protos_InternedData,
                  MSG,
                  perfetto_protos_InternedGraphicsContext,
                  graphics_contexts,
                  23);
PERFETTO_PB_FIELD(perfetto_protos_InternedData,
                  MSG,
                  perfetto_protos_InternedGpuRenderStageSpecification,
                  gpu_specifications,
                  24);
PERFETTO_PB_FIELD(perfetto_protos_InternedData,
                  MSG,
                  perfetto_protos_InternedString,
                  kernel_symbols,
                  26);
PERFETTO_PB_FIELD(perfetto_protos_InternedData,
                  MSG,
                  perfetto_protos_InternedString,
                  debug_annotation_string_values,
                  29);

#endif  // INCLUDE_PERFETTO_PUBLIC_PROTOS_TRACE_INTERNED_DATA_INTERNED_DATA_PZC_H_
