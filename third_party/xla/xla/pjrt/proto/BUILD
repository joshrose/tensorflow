# copybara:uncomment load("@rules_python//python:proto.bzl", "py_proto_library")
load("//xla/tsl:tsl.bzl", "if_google")
load("//xla/tsl:tsl.default.bzl", "get_compatible_with_libtpu_portable")
load(
    "//xla/tsl/platform:build_config.bzl",
    "tf_proto_library",
)

package(
    # copybara:uncomment default_applicable_licenses = ["//tensorflow:license"],
    licenses = ["notice"],
)

tf_proto_library(
    name = "compile_options_proto",
    srcs = ["compile_options.proto"],
    protodeps = [
        "//xla:xla_data_proto",
        "//xla:xla_proto",
        "//xla/stream_executor:device_description_proto",
    ],
    visibility = ["//visibility:public"],
)

# copybara:uncomment_begin(google-only)
# py_proto_library(
#     name = "compile_options_py_pb2",
#     visibility = ["//visibility:public"],
#     deps = [":compile_options_proto"],
# )
# copybara:uncomment_end

tf_proto_library(
    name = "execute_options_proto",
    srcs = ["execute_options.proto"],
    visibility = ["//visibility:public"],
)

tf_proto_library(
    name = "executable_metadata_proto",
    srcs = ["executable_metadata.proto"],
    visibility = ["//visibility:public"],
)

tf_proto_library(
    name = "pjrt_value_type_proto",
    srcs = ["pjrt_value_type.proto"],
    visibility = ["//visibility:public"],
)

tf_proto_library(
    name = "pjrt_partial_program_proto",
    srcs = ["pjrt_partial_program.proto"],
    visibility = ["//visibility:public"],
)

tf_proto_library(
    name = "topology_description_proto",
    srcs = ["topology_description.proto"],
    compatible_with = get_compatible_with_libtpu_portable(),
    visibility = ["//visibility:public"],
    deps = if_google(["@com_google_protobuf//:any"]),
)
