# Copyright 2023 The OpenXLA Authors.
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

load("//xla/python/ifrt_proxy/common:ifrt_proxy.bzl", "default_ifrt_proxy_visibility", "ifrt_proxy_cc_test")
load("//xla/tsl:tsl.bzl", "if_google", "internal_visibility")

package(
    # copybara:uncomment default_applicable_licenses = ["//tensorflow:license"],
    default_visibility = internal_visibility(default_ifrt_proxy_visibility),
)

cc_library(
    name = "grpc_client_session",
    srcs = [
        "grpc_client_session.cc",
    ],
    hdrs = ["grpc_client_session.h"],
    deps = [
        ":client_session",
        "//xla/pjrt/distributed:util",
        "//xla/python/ifrt",
        "//xla/python/ifrt_proxy/common:grpc_credentials_possibly_insecure_wrapper",
        "//xla/python/ifrt_proxy/common:grpc_ifrt_service_cc_grpc_proto",
        "//xla/python/ifrt_proxy/common:grpc_ifrt_service_proto_cc",
        "//xla/python/ifrt_proxy/common:ifrt_service_proto_cc",
        "@com_github_grpc_grpc//:grpc",
        "@com_github_grpc_grpc//:grpc++",
        "@com_google_absl//absl/base",
        "@com_google_absl//absl/base:core_headers",
        "@com_google_absl//absl/container:flat_hash_map",
        "@com_google_absl//absl/functional:bind_front",
        "@com_google_absl//absl/log",
        "@com_google_absl//absl/log:check",
        "@com_google_absl//absl/status",
        "@com_google_absl//absl/status:statusor",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/synchronization",
        "@local_tsl//tsl/platform:env",
        "@local_tsl//tsl/platform:errors",
        "@local_tsl//tsl/platform:logging",
        "@local_tsl//tsl/platform:unbounded_work_queue",
        "@local_tsl//tsl/profiler/lib:traceme",
    ],
)

ifrt_proxy_cc_test(
    name = "grpc_client_session_test",
    srcs = [
        "grpc_client_session_test.cc",
    ],
    deps = [
        ":grpc_client_session",
        ":version",
        "//xla/python/ifrt:serdes_version",
        "//xla/python/ifrt_proxy/common:grpc_credentials",
        "//xla/python/ifrt_proxy/common:grpc_ifrt_service_cc_grpc_proto",
        "//xla/python/ifrt_proxy/common:grpc_ifrt_service_proto_cc",
        "//xla/python/ifrt_proxy/common:ifrt_service_proto_cc",
        "//xla/python/ifrt_proxy/common:test_utils",
        "@com_github_grpc_grpc//:gpr",
        "@com_github_grpc_grpc//:grpc++",
        "@com_google_absl//absl/base:core_headers",
        "@com_google_absl//absl/container:flat_hash_set",
        "@com_google_absl//absl/log",
        "@com_google_absl//absl/log:check",
        "@com_google_absl//absl/log:log_sink_registry",
        "@com_google_absl//absl/status",
        "@com_google_absl//absl/status:statusor",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/synchronization",
        "@com_google_absl//absl/time",
        "@com_google_googletest//:gtest_main",
        "@local_tsl//tsl/platform:errors",
        "@local_tsl//tsl/platform:logging",
        "@local_tsl//tsl/platform:status_matchers",
        "@local_tsl//tsl/platform:statusor",
        "@local_tsl//tsl/platform:test",
    ],
)

cc_library(
    name = "rpc_helper",
    srcs = [
        "rpc_helper.cc",
    ],
    hdrs = ["rpc_helper.h"],
    deps = [
        ":client_session",
        ":host_buffer",
        "//xla/python/ifrt",
        "//xla/python/ifrt:serdes_any_version_accessor",
        "//xla/python/ifrt:serdes_version",
        "//xla/python/ifrt_proxy/common:ifrt_service_proto_cc",
        "//xla/python/ifrt_proxy/common:prof_util",
        "//xla/python/ifrt_proxy/common:test_utils",
        "//xla/python/ifrt_proxy/common:types",
        "//xla/tsl/platform:env",
        "//xla/tsl/platform:status_to_from_proto",
        "//xla/tsl/profiler/utils:xplane_schema",
        "@com_google_absl//absl/base:core_headers",
        "@com_google_absl//absl/functional:any_invocable",
        "@com_google_absl//absl/functional:bind_front",
        "@com_google_absl//absl/functional:function_ref",
        "@com_google_absl//absl/log",
        "@com_google_absl//absl/log:check",
        "@com_google_absl//absl/status",
        "@com_google_absl//absl/status:statusor",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/synchronization",
        "@com_google_absl//absl/time",
        "@local_tsl//tsl/platform:env",
        "@local_tsl//tsl/platform:random",
        "@local_tsl//tsl/platform:status_to_from_proto",
        "@local_tsl//tsl/profiler/lib:traceme",
        "@local_tsl//tsl/profiler/lib:traceme_encode",
    ] + if_google(["@com_google_absl//absl/types:source_location"]),
)

ifrt_proxy_cc_test(
    name = "rpc_helper_test",
    srcs = ["rpc_helper_test.cc"],
    deps = [
        ":client_session",
        ":mock_client_session",
        ":rpc_helper",
        ":version",
        "//xla/python/ifrt",
        "//xla/python/ifrt:serdes_version",
        "//xla/python/ifrt_proxy/common:ifrt_service_proto_cc",
        "//xla/python/ifrt_proxy/common:test_utils",
        "//xla/python/ifrt_proxy/common:types",
        "//xla/python/ifrt_proxy/common:types_proto_cc",
        "@com_google_absl//absl/log:check",
        "@com_google_absl//absl/status",
        "@com_google_absl//absl/synchronization",
        "@com_google_absl//absl/time",
        "@com_google_googletest//:gtest_main",
        "@local_tsl//tsl/platform:test",
    ],
)

cc_library(
    name = "client",
    srcs = ["client.cc"],
    hdrs = ["client.h"],
    deps = [
        ":array",
        ":compiler",
        ":device",
        ":memory",
        ":rpc_helper",
        "//xla:xla_data_proto_cc",
        "//xla/pjrt:pjrt_device_description",
        "//xla/pjrt:pjrt_layout",
        "//xla/python/ifrt",
        "//xla/python/ifrt:attribute_map",
        "//xla/python/ifrt:basic_device_list",
        "//xla/python/ifrt:user_context",
        "//xla/python/ifrt_proxy/common:common_serdes",
        "//xla/python/ifrt_proxy/common:ifrt_service_proto_cc",
        "//xla/python/ifrt_proxy/common:types",
        "//xla/python/ifrt_proxy/common:versions",
        "//xla/python/pjrt_ifrt:pjrt_attribute_map_util",
        "//xla/tsl/concurrency:ref_count",
        "//xla/tsl/platform:statusor",
        "@com_google_absl//absl/base:core_headers",
        "@com_google_absl//absl/container:flat_hash_map",
        "@com_google_absl//absl/container:flat_hash_set",
        "@com_google_absl//absl/container:inlined_vector",
        "@com_google_absl//absl/log",
        "@com_google_absl//absl/log:check",
        "@com_google_absl//absl/memory",
        "@com_google_absl//absl/status",
        "@com_google_absl//absl/status:statusor",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/synchronization",
        "@com_google_absl//absl/types:span",
        "@llvm-project//llvm:Support",
        "@local_tsl//tsl/platform:casts",
        "@local_tsl//tsl/profiler/lib:traceme",
    ],
)

ifrt_proxy_cc_test(
    name = "client_test",
    srcs = ["client_test.cc"],
    deps = [
        ":array",
        ":client",
        ":client_session",
        ":host_buffer",
        ":mock_client_session",
        ":mock_host_buffer",
        ":rpc_helper",
        ":version",
        "//xla:shape_util",
        "//xla/pjrt:pjrt_layout",
        "//xla/python/ifrt",
        "//xla/python/ifrt:attribute_map",
        "//xla/python/ifrt:serdes_version",
        "//xla/python/ifrt_proxy/common:ifrt_service_proto_cc",
        "//xla/python/ifrt_proxy/common:types",
        "//xla/service:computation_placer_hdr",
        "//xla/tsl/concurrency:ref_count",
        "//xla/tsl/platform:status_matchers",
        "//xla/tsl/platform:statusor",
        "@com_google_absl//absl/status",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/strings:string_view",
        "@com_google_absl//absl/types:span",
        "@com_google_googletest//:gtest_main",
        "@llvm-project//llvm:Support",
        "@local_tsl//tsl/platform",
        "@local_tsl//tsl/platform:protobuf",
    ],
)

cc_library(
    name = "device",
    srcs = ["device.cc"],
    hdrs = ["device.h"],
    deps = [
        "//xla/pjrt:pjrt_device_description",
        "//xla/python/ifrt",
        "//xla/python/ifrt:attribute_map",
        "//xla/python/pjrt_ifrt:pjrt_attribute_map_util",
        "@com_google_absl//absl/container:flat_hash_map",
        "@com_google_absl//absl/status",
        "@com_google_absl//absl/status:statusor",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/types:span",
        "@llvm-project//llvm:Support",
    ],
)

cc_library(
    name = "array",
    srcs = ["array.cc"],
    hdrs = ["array.h"],
    deps = [
        ":global_flags",
        ":rpc_helper",
        "//xla:status_macros",
        "//xla/pjrt:pjrt_layout",
        "//xla/python/ifrt",
        "//xla/python/ifrt:client_impl_util",
        "//xla/python/ifrt:sharding_serdes",
        "//xla/python/ifrt:user_context",
        "//xla/python/ifrt_proxy/common:array_util",
        "//xla/python/ifrt_proxy/common:ifrt_service_proto_cc",
        "//xla/python/ifrt_proxy/common:types",
        "//xla/python/ifrt_proxy/common:types_proto_cc",
        "//xla/python/ifrt_proxy/common:versions",
        "//xla/tsl/concurrency:ref_count",
        "//xla/tsl/platform:errors",
        "//xla/tsl/platform:status_to_from_proto",
        "//xla/tsl/platform:statusor",
        "@com_google_absl//absl/base:core_headers",
        "@com_google_absl//absl/cleanup",
        "@com_google_absl//absl/container:inlined_vector",
        "@com_google_absl//absl/log",
        "@com_google_absl//absl/log:check",
        "@com_google_absl//absl/status",
        "@com_google_absl//absl/status:statusor",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/strings:cord",
        "@com_google_absl//absl/strings:str_format",
        "@com_google_absl//absl/synchronization",
        "@com_google_absl//absl/types:span",
        "@llvm-project//llvm:Support",
        "@local_tsl//tsl/profiler/lib:traceme",
    ],
)

ifrt_proxy_cc_test(
    name = "array_test",
    srcs = ["array_test.cc"],
    deps = [
        ":array",
        ":client_session",
        ":mock_client_session",
        ":mock_host_buffer",
        ":rpc_helper",
        ":version",
        "//xla:shape_util",
        "//xla/pjrt:pjrt_layout",
        "//xla/python/ifrt",
        "//xla/python/ifrt:basic_device_list",
        "//xla/python/ifrt:mock",
        "//xla/python/ifrt:serdes_version",
        "//xla/python/ifrt:user_context",
        "//xla/python/ifrt_proxy/common:ifrt_service_proto_cc",
        "//xla/python/ifrt_proxy/common:test_utils",
        "//xla/python/ifrt_proxy/common:types",
        "//xla/python/ifrt_proxy/common:types_proto_cc",
        "//xla/tsl/concurrency:ref_count",
        "//xla/tsl/lib/core:status_test_util",
        "//xla/tsl/platform:status_matchers",
        "//xla/tsl/platform:statusor",
        "@com_google_absl//absl/status",
        "@com_google_absl//absl/status:statusor",
        "@com_google_absl//absl/strings:string_view",
        "@com_google_absl//absl/time",
        "@com_google_absl//absl/types:span",
        "@com_google_googletest//:gtest_main",
        "@local_tsl//tsl/platform:protobuf",
    ],
)

cc_library(
    name = "client_session",
    hdrs = ["client_session.h"],
    deps = [
        "//xla/python/ifrt",
        "//xla/python/ifrt_proxy/common:ifrt_service_proto_cc",
        "@com_google_absl//absl/status",
    ],
)

cc_library(
    name = "mock_client_session",
    testonly = True,
    hdrs = ["mock_client_session.h"],
    deps = [
        ":client_session",
        "//xla/python/ifrt",
        "//xla/python/ifrt_proxy/common:ifrt_service_proto_cc",
        "//xla/python/ifrt_proxy/common:test_utils",
        "@com_google_absl//absl/status",
        "@com_google_googletest//:gtest_for_library",
    ],
)

cc_library(
    name = "compiler",
    srcs = ["compiler.cc"],
    hdrs = ["compiler.h"],
    deps = [
        ":executable",
        ":rpc_helper",
        "//xla:debug_options_flags",
        "//xla/pjrt:host_callback",
        "//xla/python/ifrt",
        "//xla/python/ifrt:serdes",
        "//xla/python/ifrt_proxy/common:ifrt_service_proto_cc",
        "//xla/python/ifrt_proxy/server:host_callback",
        "//xla/python/pjrt_ifrt",
        "//xla/python/pjrt_ifrt:xla_ifrt",
        "//xla/tsl/concurrency:ref_count",
        "//xla/tsl/platform:errors",
        "@com_google_absl//absl/status",
        "@com_google_absl//absl/status:statusor",
        "@com_google_absl//absl/strings",
        "@llvm-project//llvm:Support",
        "@local_tsl//tsl/platform:status_to_from_proto",
        "@local_tsl//tsl/platform:statusor",
        "@local_tsl//tsl/profiler/lib:traceme",
    ],
)

ifrt_proxy_cc_test(
    name = "compiler_test",
    srcs = ["compiler_test.cc"],
    deps = [
        ":client_session",
        ":compiler",
        ":host_buffer",
        ":mock_client_session",
        ":mock_host_buffer",
        ":rpc_helper",
        ":version",
        "//xla/python/ifrt",
        "//xla/python/ifrt:mock",
        "//xla/python/ifrt:serdes",
        "//xla/python/ifrt:serdes_version",
        "//xla/python/ifrt_proxy/common:ifrt_service_proto_cc",
        "//xla/python/ifrt_proxy/common:test_utils",
        "//xla/tsl/platform:statusor",
        "@com_google_absl//absl/log:check",
        "@com_google_absl//absl/status",
        "@com_google_absl//absl/status:statusor",
        "@com_google_absl//absl/strings:string_view",
        "@com_google_absl//absl/time",
        "@com_google_googletest//:gtest_main",
        "@llvm-project//llvm:Support",
        "@local_tsl//tsl/platform:protobuf",
        "@local_tsl//tsl/platform:status_matchers",
        "@local_tsl//tsl/platform:statusor",
        "@local_tsl//tsl/platform:test",
    ],
)

cc_library(
    name = "executable",
    srcs = ["executable.cc"],
    hdrs = ["executable.h"],
    deps = [
        ":array",
        ":host_buffer",
        ":rpc_helper",
        "//xla:shape_util",
        "//xla:xla_data_proto_cc",
        "//xla/hlo/ir:hlo",
        "//xla/pjrt:host_callback",
        "//xla/pjrt:pjrt_executable",
        "//xla/pjrt:pjrt_layout",
        "//xla/python/ifrt",
        "//xla/python/ifrt:attribute_map",
        "//xla/python/ifrt:sharding_serdes",
        "//xla/python/ifrt:user_context",
        "//xla/python/ifrt_proxy/common:ifrt_service_proto_cc",
        "//xla/python/ifrt_proxy/common:types",
        "//xla/python/ifrt_proxy/common:versions",
        "//xla/python/pjrt_ifrt",
        "//xla/tsl/concurrency:ref_count",
        "//xla/tsl/platform:env",
        "//xla/tsl/platform:errors",
        "//xla/tsl/platform:status_to_from_proto",
        "//xla/tsl/platform:statusor",
        "@com_google_absl//absl/base:core_headers",
        "@com_google_absl//absl/base:nullability",
        "@com_google_absl//absl/cleanup",
        "@com_google_absl//absl/container:flat_hash_map",
        "@com_google_absl//absl/container:flat_hash_set",
        "@com_google_absl//absl/container:node_hash_set",
        "@com_google_absl//absl/log",
        "@com_google_absl//absl/log:check",
        "@com_google_absl//absl/status",
        "@com_google_absl//absl/status:statusor",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/strings:cord",
        "@com_google_absl//absl/synchronization",
        "@com_google_absl//absl/types:span",
        "@llvm-project//llvm:Support",
        "@local_tsl//tsl/platform:platform_port",
        "@local_tsl//tsl/platform:protobuf",
        "@local_tsl//tsl/profiler/lib:traceme",
    ],
)

cc_library(
    name = "host_buffer",
    hdrs = ["host_buffer.h"],
    deps = [
        "//xla/python/ifrt",
        "@com_google_absl//absl/status:statusor",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/strings:cord",
    ],
)

cc_library(
    name = "mock_host_buffer",
    testonly = True,
    hdrs = ["mock_host_buffer.h"],
    deps = [
        ":host_buffer",
        "//xla/python/ifrt",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/strings:cord",
        "@com_google_googletest//:gtest_for_library",
    ],
)

cc_library(
    name = "grpc_host_buffer",
    srcs = ["grpc_host_buffer.cc"],
    hdrs = ["grpc_host_buffer.h"],
    deps = [
        ":host_buffer",
        "//xla/pjrt/distributed:util",
        "//xla/python/ifrt",
        "//xla/python/ifrt_proxy/common:grpc_ifrt_service_cc_grpc_proto",
        "//xla/python/ifrt_proxy/common:grpc_ifrt_service_proto_cc",
        "//xla/python/ifrt_proxy/common:ifrt_service_proto_cc",
        "//xla/python/ifrt_proxy/common:prof_util",
        "//xla/tsl/protobuf:status_proto_cc",
        "@com_github_grpc_grpc//:grpc++",
        "@com_google_absl//absl/log",
        "@com_google_absl//absl/status",
        "@com_google_absl//absl/status:statusor",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/strings:cord",
        "@com_google_absl//absl/strings:string_view",
        "@local_tsl//tsl/platform:unbounded_work_queue",
        "@local_tsl//tsl/profiler/lib:traceme",
    ],
)

cc_library(
    name = "grpc_client",
    srcs = ["grpc_client.cc"],
    deps = [
        ":client",
        ":global_flags",
        ":grpc_client_session",
        ":grpc_host_buffer",
        ":registry",
        ":rpc_helper",
        ":version",
        "//xla/pjrt/distributed:util",
        "//xla/python/ifrt",
        "//xla/python/ifrt:attribute_map",
        "//xla/python/ifrt:serdes_any_version_accessor",
        "//xla/python/ifrt:serdes_version",
        "//xla/python/ifrt_proxy/common:grpc_ifrt_service_proto_cc",
        "//xla/python/ifrt_proxy/common:ifrt_service_proto_cc",
        "//xla/tsl/platform:errors",
        "//xla/tsl/platform:statusor",
        "@com_github_grpc_grpc//:grpc++",
        "@com_google_absl//absl/log",
        "@com_google_absl//absl/log:check",
        "@com_google_absl//absl/log:log_entry",
        "@com_google_absl//absl/status:statusor",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/strings:string_view",
        "@com_google_absl//absl/time",
        "@local_tsl//tsl/platform:stacktrace",
    ],
    alwayslink = True,
)

cc_library(
    name = "registry",
    srcs = ["registry.cc"],
    hdrs = ["registry.h"],
    visibility = internal_visibility(default_ifrt_proxy_visibility + if_google([
        "//xla/python/ifrt_proxy/common/google:cc_client_users",
    ])),
    deps = [
        ":global_flags",
        "//xla/python/ifrt",
        "//xla/python/ifrt:attribute_map",
        "@com_google_absl//absl/base:core_headers",
        "@com_google_absl//absl/container:flat_hash_map",
        "@com_google_absl//absl/log",
        "@com_google_absl//absl/log:check",
        "@com_google_absl//absl/status",
        "@com_google_absl//absl/status:statusor",
        "@com_google_absl//absl/strings",
        "@com_google_absl//absl/strings:string_view",
        "@com_google_absl//absl/synchronization",
        "@com_google_absl//absl/time",
    ],
)

cc_library(
    name = "memory",
    hdrs = ["memory.h"],
    deps = [
        "//xla/pjrt:pjrt_client",
        "//xla/python/ifrt",
        "@com_google_absl//absl/strings:string_view",
        "@com_google_absl//absl/types:span",
        "@llvm-project//llvm:Support",
    ],
)

cc_library(
    name = "version",
    hdrs = ["version.h"],
    deps = ["//xla/python/ifrt_proxy/common:versions"],
)

ifrt_proxy_cc_test(
    name = "executable_test",
    srcs = ["executable_test.cc"],
    deps = [
        ":array",
        ":client_session",
        ":executable",
        ":host_buffer",
        ":mock_client_session",
        ":mock_host_buffer",
        ":rpc_helper",
        ":version",
        "//xla:shape_util",
        "//xla:xla_data_proto_cc",
        "//xla/python/ifrt",
        "//xla/python/ifrt:basic_device_list",
        "//xla/python/ifrt:mock",
        "//xla/python/ifrt:serdes_version",
        "//xla/python/ifrt:sharding_serdes",
        "//xla/python/ifrt_proxy/common:ifrt_service_proto_cc",
        "//xla/python/ifrt_proxy/common:test_utils",
        "//xla/python/ifrt_proxy/common:types",
        "//xla/tsl/concurrency:ref_count",
        "//xla/tsl/platform:statusor",
        "@com_google_absl//absl/status",
        "@com_google_absl//absl/time",
        "@com_google_absl//absl/types:span",
        "@com_google_googletest//:gtest_main",
        "@llvm-project//llvm:Support",
        "@local_tsl//tsl/platform:protobuf",
        "@local_tsl//tsl/platform:status_matchers",
    ],
)

# Export headers referenced by the google-internal-version of global_flags.
exports_files(
    ["global_flags.h"],
    visibility = if_google(
        ["//xla/python/ifrt_proxy/client/google:__pkg__"],
        ["//visibility:private"],
    ),
)

cc_library(
    name = "global_flags_oss",
    srcs = [
        "global_flags.h",
        "global_flags_oss.cc",
    ],
    visibility = ["//visibility:private"],
    deps = [
        "@com_google_absl//absl/debugging:leak_check",
        "@com_google_absl//absl/log:check",
        "@com_google_absl//absl/strings",
    ],
)

cc_library(
    name = "global_flags",
    hdrs = ["global_flags.h"],
    deps = [if_google("//xla/python/ifrt_proxy/client/google:global_flags_google", ":global_flags_oss")],
)
