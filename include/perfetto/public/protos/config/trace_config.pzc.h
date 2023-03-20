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

#ifndef INCLUDE_PERFETTO_PUBLIC_PROTOS_CONFIG_TRACE_CONFIG_PZC_H_
#define INCLUDE_PERFETTO_PUBLIC_PROTOS_CONFIG_TRACE_CONFIG_PZC_H_

#include <stdbool.h>
#include <stdint.h>

#include "perfetto/public/pb_macros.h"

#include "perfetto/public/protos/common/builtin_clock.pzc.h"

PERFETTO_PB_MSG_DECL(perfetto_protos_DataSourceConfig);
PERFETTO_PB_MSG_DECL(perfetto_protos_TraceConfig_AndroidReportConfig);
PERFETTO_PB_MSG_DECL(perfetto_protos_TraceConfig_BufferConfig);
PERFETTO_PB_MSG_DECL(perfetto_protos_TraceConfig_BuiltinDataSource);
PERFETTO_PB_MSG_DECL(perfetto_protos_TraceConfig_CmdTraceStartDelay);
PERFETTO_PB_MSG_DECL(perfetto_protos_TraceConfig_DataSource);
PERFETTO_PB_MSG_DECL(perfetto_protos_TraceConfig_GuardrailOverrides);
PERFETTO_PB_MSG_DECL(perfetto_protos_TraceConfig_IncidentReportConfig);
PERFETTO_PB_MSG_DECL(perfetto_protos_TraceConfig_IncrementalStateConfig);
PERFETTO_PB_MSG_DECL(perfetto_protos_TraceConfig_ProducerConfig);
PERFETTO_PB_MSG_DECL(perfetto_protos_TraceConfig_StatsdMetadata);
PERFETTO_PB_MSG_DECL(perfetto_protos_TraceConfig_TraceFilter);
PERFETTO_PB_MSG_DECL(perfetto_protos_TraceConfig_TriggerConfig);
PERFETTO_PB_MSG_DECL(perfetto_protos_TraceConfig_TriggerConfig_Trigger);

PERFETTO_PB_ENUM_IN_MSG(perfetto_protos_TraceConfig, LockdownModeOperation){
    PERFETTO_PB_ENUM_IN_MSG_ENTRY(perfetto_protos_TraceConfig,
                                  LOCKDOWN_UNCHANGED) = 0,
    PERFETTO_PB_ENUM_IN_MSG_ENTRY(perfetto_protos_TraceConfig,
                                  LOCKDOWN_CLEAR) = 1,
    PERFETTO_PB_ENUM_IN_MSG_ENTRY(perfetto_protos_TraceConfig,
                                  LOCKDOWN_SET) = 2,
};

PERFETTO_PB_ENUM_IN_MSG(perfetto_protos_TraceConfig, CompressionType){
    PERFETTO_PB_ENUM_IN_MSG_ENTRY(perfetto_protos_TraceConfig,
                                  COMPRESSION_TYPE_UNSPECIFIED) = 0,
    PERFETTO_PB_ENUM_IN_MSG_ENTRY(perfetto_protos_TraceConfig,
                                  COMPRESSION_TYPE_DEFLATE) = 1,
};

PERFETTO_PB_ENUM_IN_MSG(perfetto_protos_TraceConfig, StatsdLogging){
    PERFETTO_PB_ENUM_IN_MSG_ENTRY(perfetto_protos_TraceConfig,
                                  STATSD_LOGGING_UNSPECIFIED) = 0,
    PERFETTO_PB_ENUM_IN_MSG_ENTRY(perfetto_protos_TraceConfig,
                                  STATSD_LOGGING_ENABLED) = 1,
    PERFETTO_PB_ENUM_IN_MSG_ENTRY(perfetto_protos_TraceConfig,
                                  STATSD_LOGGING_DISABLED) = 2,
};

PERFETTO_PB_ENUM_IN_MSG(perfetto_protos_TraceConfig_TriggerConfig, TriggerMode){
    PERFETTO_PB_ENUM_IN_MSG_ENTRY(perfetto_protos_TraceConfig_TriggerConfig,
                                  UNSPECIFIED) = 0,
    PERFETTO_PB_ENUM_IN_MSG_ENTRY(perfetto_protos_TraceConfig_TriggerConfig,
                                  START_TRACING) = 1,
    PERFETTO_PB_ENUM_IN_MSG_ENTRY(perfetto_protos_TraceConfig_TriggerConfig,
                                  STOP_TRACING) = 2,
};

PERFETTO_PB_ENUM_IN_MSG(perfetto_protos_TraceConfig_BufferConfig, FillPolicy){
    PERFETTO_PB_ENUM_IN_MSG_ENTRY(perfetto_protos_TraceConfig_BufferConfig,
                                  UNSPECIFIED) = 0,
    PERFETTO_PB_ENUM_IN_MSG_ENTRY(perfetto_protos_TraceConfig_BufferConfig,
                                  RING_BUFFER) = 1,
    PERFETTO_PB_ENUM_IN_MSG_ENTRY(perfetto_protos_TraceConfig_BufferConfig,
                                  DISCARD) = 2,
};

PERFETTO_PB_MSG(perfetto_protos_TraceConfig);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  MSG,
                  perfetto_protos_TraceConfig_BufferConfig,
                  buffers,
                  1);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  MSG,
                  perfetto_protos_TraceConfig_DataSource,
                  data_sources,
                  2);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  MSG,
                  perfetto_protos_TraceConfig_BuiltinDataSource,
                  builtin_data_sources,
                  20);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  VARINT,
                  uint32_t,
                  duration_ms,
                  3);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  VARINT,
                  bool,
                  prefer_suspend_clock_for_duration,
                  36);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  VARINT,
                  bool,
                  enable_extra_guardrails,
                  4);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  VARINT,
                  enum perfetto_protos_TraceConfig_LockdownModeOperation,
                  lockdown_mode,
                  5);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  MSG,
                  perfetto_protos_TraceConfig_ProducerConfig,
                  producers,
                  6);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  MSG,
                  perfetto_protos_TraceConfig_StatsdMetadata,
                  statsd_metadata,
                  7);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  VARINT,
                  bool,
                  write_into_file,
                  8);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  STRING,
                  const char*,
                  output_path,
                  29);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  VARINT,
                  uint32_t,
                  file_write_period_ms,
                  9);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  VARINT,
                  uint64_t,
                  max_file_size_bytes,
                  10);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  MSG,
                  perfetto_protos_TraceConfig_GuardrailOverrides,
                  guardrail_overrides,
                  11);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  VARINT,
                  bool,
                  deferred_start,
                  12);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  VARINT,
                  uint32_t,
                  flush_period_ms,
                  13);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  VARINT,
                  uint32_t,
                  flush_timeout_ms,
                  14);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  VARINT,
                  uint32_t,
                  data_source_stop_timeout_ms,
                  23);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  VARINT,
                  bool,
                  notify_traceur,
                  16);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  VARINT,
                  int32_t,
                  bugreport_score,
                  30);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  MSG,
                  perfetto_protos_TraceConfig_TriggerConfig,
                  trigger_config,
                  17);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  STRING,
                  const char*,
                  activate_triggers,
                  18);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  MSG,
                  perfetto_protos_TraceConfig_IncrementalStateConfig,
                  incremental_state_config,
                  21);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  VARINT,
                  bool,
                  allow_user_build_tracing,
                  19);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  STRING,
                  const char*,
                  unique_session_name,
                  22);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  VARINT,
                  enum perfetto_protos_TraceConfig_CompressionType,
                  compression_type,
                  24);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  MSG,
                  perfetto_protos_TraceConfig_IncidentReportConfig,
                  incident_report_config,
                  25);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  VARINT,
                  enum perfetto_protos_TraceConfig_StatsdLogging,
                  statsd_logging,
                  31);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  VARINT,
                  int64_t,
                  trace_uuid_msb,
                  27);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  VARINT,
                  int64_t,
                  trace_uuid_lsb,
                  28);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  MSG,
                  perfetto_protos_TraceConfig_TraceFilter,
                  trace_filter,
                  33);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  MSG,
                  perfetto_protos_TraceConfig_AndroidReportConfig,
                  android_report_config,
                  34);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig,
                  MSG,
                  perfetto_protos_TraceConfig_CmdTraceStartDelay,
                  cmd_trace_start_delay,
                  35);

PERFETTO_PB_MSG(perfetto_protos_TraceConfig_CmdTraceStartDelay);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_CmdTraceStartDelay,
                  VARINT,
                  uint32_t,
                  min_delay_ms,
                  1);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_CmdTraceStartDelay,
                  VARINT,
                  uint32_t,
                  max_delay_ms,
                  2);

PERFETTO_PB_MSG(perfetto_protos_TraceConfig_AndroidReportConfig);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_AndroidReportConfig,
                  STRING,
                  const char*,
                  reporter_service_package,
                  1);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_AndroidReportConfig,
                  STRING,
                  const char*,
                  reporter_service_class,
                  2);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_AndroidReportConfig,
                  VARINT,
                  bool,
                  skip_report,
                  3);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_AndroidReportConfig,
                  VARINT,
                  bool,
                  use_pipe_in_framework_for_testing,
                  4);

PERFETTO_PB_MSG(perfetto_protos_TraceConfig_TraceFilter);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_TraceFilter,
                  STRING,
                  const char*,
                  bytecode,
                  1);

PERFETTO_PB_MSG(perfetto_protos_TraceConfig_IncidentReportConfig);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_IncidentReportConfig,
                  STRING,
                  const char*,
                  destination_package,
                  1);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_IncidentReportConfig,
                  STRING,
                  const char*,
                  destination_class,
                  2);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_IncidentReportConfig,
                  VARINT,
                  int32_t,
                  privacy_level,
                  3);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_IncidentReportConfig,
                  VARINT,
                  bool,
                  skip_incidentd,
                  5);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_IncidentReportConfig,
                  VARINT,
                  bool,
                  skip_dropbox,
                  4);

PERFETTO_PB_MSG(perfetto_protos_TraceConfig_IncrementalStateConfig);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_IncrementalStateConfig,
                  VARINT,
                  uint32_t,
                  clear_period_ms,
                  1);

PERFETTO_PB_MSG(perfetto_protos_TraceConfig_TriggerConfig);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_TriggerConfig,
                  VARINT,
                  enum perfetto_protos_TraceConfig_TriggerConfig_TriggerMode,
                  trigger_mode,
                  1);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_TriggerConfig,
                  MSG,
                  perfetto_protos_TraceConfig_TriggerConfig_Trigger,
                  triggers,
                  2);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_TriggerConfig,
                  VARINT,
                  uint32_t,
                  trigger_timeout_ms,
                  3);

PERFETTO_PB_MSG(perfetto_protos_TraceConfig_TriggerConfig_Trigger);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_TriggerConfig_Trigger,
                  STRING,
                  const char*,
                  name,
                  1);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_TriggerConfig_Trigger,
                  STRING,
                  const char*,
                  producer_name_regex,
                  2);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_TriggerConfig_Trigger,
                  VARINT,
                  uint32_t,
                  stop_delay_ms,
                  3);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_TriggerConfig_Trigger,
                  VARINT,
                  uint32_t,
                  max_per_24_h,
                  4);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_TriggerConfig_Trigger,
                  FIXED64,
                  double,
                  skip_probability,
                  5);

PERFETTO_PB_MSG(perfetto_protos_TraceConfig_GuardrailOverrides);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_GuardrailOverrides,
                  VARINT,
                  uint64_t,
                  max_upload_per_day_bytes,
                  1);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_GuardrailOverrides,
                  VARINT,
                  uint32_t,
                  max_tracing_buffer_size_kb,
                  2);

PERFETTO_PB_MSG(perfetto_protos_TraceConfig_StatsdMetadata);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_StatsdMetadata,
                  VARINT,
                  int64_t,
                  triggering_alert_id,
                  1);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_StatsdMetadata,
                  VARINT,
                  int32_t,
                  triggering_config_uid,
                  2);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_StatsdMetadata,
                  VARINT,
                  int64_t,
                  triggering_config_id,
                  3);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_StatsdMetadata,
                  VARINT,
                  int64_t,
                  triggering_subscription_id,
                  4);

PERFETTO_PB_MSG(perfetto_protos_TraceConfig_ProducerConfig);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_ProducerConfig,
                  STRING,
                  const char*,
                  producer_name,
                  1);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_ProducerConfig,
                  VARINT,
                  uint32_t,
                  shm_size_kb,
                  2);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_ProducerConfig,
                  VARINT,
                  uint32_t,
                  page_size_kb,
                  3);

PERFETTO_PB_MSG(perfetto_protos_TraceConfig_BuiltinDataSource);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_BuiltinDataSource,
                  VARINT,
                  bool,
                  disable_clock_snapshotting,
                  1);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_BuiltinDataSource,
                  VARINT,
                  bool,
                  disable_trace_config,
                  2);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_BuiltinDataSource,
                  VARINT,
                  bool,
                  disable_system_info,
                  3);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_BuiltinDataSource,
                  VARINT,
                  bool,
                  disable_service_events,
                  4);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_BuiltinDataSource,
                  VARINT,
                  enum perfetto_protos_BuiltinClock,
                  primary_trace_clock,
                  5);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_BuiltinDataSource,
                  VARINT,
                  uint32_t,
                  snapshot_interval_ms,
                  6);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_BuiltinDataSource,
                  VARINT,
                  bool,
                  prefer_suspend_clock_for_snapshot,
                  7);

PERFETTO_PB_MSG(perfetto_protos_TraceConfig_DataSource);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_DataSource,
                  MSG,
                  perfetto_protos_DataSourceConfig,
                  config,
                  1);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_DataSource,
                  STRING,
                  const char*,
                  producer_name_filter,
                  2);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_DataSource,
                  STRING,
                  const char*,
                  producer_name_regex_filter,
                  3);

PERFETTO_PB_MSG(perfetto_protos_TraceConfig_BufferConfig);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_BufferConfig,
                  VARINT,
                  uint32_t,
                  size_kb,
                  1);
PERFETTO_PB_FIELD(perfetto_protos_TraceConfig_BufferConfig,
                  VARINT,
                  enum perfetto_protos_TraceConfig_BufferConfig_FillPolicy,
                  fill_policy,
                  4);

#endif  // INCLUDE_PERFETTO_PUBLIC_PROTOS_CONFIG_TRACE_CONFIG_PZC_H_
