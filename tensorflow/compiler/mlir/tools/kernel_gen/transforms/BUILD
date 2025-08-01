load("@llvm-project//mlir:tblgen.bzl", "gentbl_cc_library")
load(
    "@local_config_rocm//rocm:build_defs.bzl",
    "if_rocm_is_configured",
)
load(
    "@local_xla//xla/tsl/platform/default:cuda_build_defs.bzl",
    "if_cuda_is_configured",
)
load("@rules_cc//cc:cc_library.bzl", "cc_library")
load("//tensorflow:tensorflow.default.bzl", "get_compatible_with_portable")

package(
    # copybara:uncomment default_applicable_licenses = ["//tensorflow:license"],
    default_visibility = ["//tensorflow/compiler/mlir/tools/kernel_gen:friends"],
    licenses = ["notice"],
)

cc_library(
    name = "utils",
    srcs = ["utils.cc"],
    hdrs = ["utils.h"],
    compatible_with = get_compatible_with_portable(),
    deps = [
        "@llvm-project//llvm:Support",
        "@llvm-project//mlir:IR",
        "@llvm-project//mlir:LLVMDialect",
    ],
)

cc_library(
    name = "tf_framework_legalize_to_llvm",
    srcs = ["tf_framework_legalize_to_llvm.cc"],
    hdrs = ["rewriters.h"],
    compatible_with = get_compatible_with_portable(),
    deps = [
        ":utils",
        "//tensorflow/compiler/mlir/tools/kernel_gen/ir:tf_framework_ops",
        "@llvm-project//mlir:FuncDialect",
        "@llvm-project//mlir:IR",
        "@llvm-project//mlir:LLVMCommonConversion",
        "@llvm-project//mlir:LLVMDialect",
        "@llvm-project//mlir:Support",
        "@llvm-project//mlir:TransformUtils",
        "@llvm-project//mlir:Transforms",
    ],
)

cc_library(
    name = "bufferize",
    srcs = ["bufferize.cc"],
    hdrs = ["rewriters.h"],
    compatible_with = get_compatible_with_portable(),
    deps = [
        "//tensorflow/compiler/mlir/tools/kernel_gen/ir:tf_framework_ops",
        "@llvm-project//mlir:ArithDialect",
        "@llvm-project//mlir:BufferizationTransforms",
        "@llvm-project//mlir:ComplexDialect",
        "@llvm-project//mlir:FuncDialect",
        "@llvm-project//mlir:IR",
        "@llvm-project//mlir:MemRefDialect",
        "@llvm-project//mlir:SCFDialect",
        "@llvm-project//mlir:TransformUtils",
        "@llvm-project//mlir:Transforms",
        "@stablehlo//:chlo_ops",
    ],
)

cc_library(
    name = "embed_tf_framework",
    srcs = ["embed_tf_framework.cc"],
    hdrs = ["rewriters.h"],
    compatible_with = get_compatible_with_portable(),
    deps = [
        "//tensorflow/compiler/mlir/tools/kernel_gen/ir:tf_framework_ops",
        "@llvm-project//mlir:ControlFlowDialect",
        "@llvm-project//mlir:FuncDialect",
        "@llvm-project//mlir:IR",
        "@llvm-project//mlir:MemRefDialect",
        "@llvm-project//mlir:Support",
        "@llvm-project//mlir:TransformUtils",
        "@llvm-project//mlir:Transforms",
    ],
)

gentbl_cc_library(
    name = "kernel_gen_passes_inc_gen",
    compatible_with = get_compatible_with_portable(),
    tbl_outs = {"kernel_gen_passes.h.inc": [
        "-gen-pass-decls",
        "-name=KernelGen",
    ]},
    tblgen = "@llvm-project//mlir:mlir-tblgen",
    td_file = "passes.td",
    deps = ["@llvm-project//mlir:PassBaseTdFiles"],
)

cc_library(
    name = "gpu_passes",
    srcs = [
        "gpu_kernel_to_blob_pass.cc",
        "tf_kernel_to_llvm_pass.cc",
    ],
    hdrs = ["passes.h"],
    copts = if_cuda_is_configured(["-DGOOGLE_CUDA=1"]) + if_rocm_is_configured(["-DTENSORFLOW_USE_ROCM=1"]),
    deps = [
        ":embed_tf_framework",
        ":kernel_gen_passes_inc_gen",
        "//tensorflow/compiler/mlir/tensorflow",
        "//tensorflow/compiler/mlir/tools/kernel_gen/ir:tf_framework_ops",
        "//tensorflow/core:lib",
        "//tensorflow/core/platform:errors",
        "@llvm-project//llvm:Support",
        "@llvm-project//llvm:TargetParser",
        "@llvm-project//llvm:TransformUtils",
        "@llvm-project//mlir:AffineDialect",
        "@llvm-project//mlir:ArithDialect",
        "@llvm-project//mlir:ArithToLLVM",
        "@llvm-project//mlir:ArithTransforms",
        "@llvm-project//mlir:ComplexDialect",
        "@llvm-project//mlir:ComplexToLLVM",
        "@llvm-project//mlir:ControlFlowDialect",
        "@llvm-project//mlir:ControlFlowToLLVM",
        "@llvm-project//mlir:FuncDialect",
        "@llvm-project//mlir:FuncToLLVM",
        "@llvm-project//mlir:FuncTransforms",
        "@llvm-project//mlir:GPUDialect",
        "@llvm-project//mlir:GPUToGPURuntimeTransforms",
        "@llvm-project//mlir:GPUTransforms",
        "@llvm-project//mlir:IR",
        "@llvm-project//mlir:LLVMCommonConversion",
        "@llvm-project//mlir:LLVMDialect",
        "@llvm-project//mlir:LinalgDialect",
        "@llvm-project//mlir:LinalgTransforms",
        "@llvm-project//mlir:MathDialect",
        "@llvm-project//mlir:MathToLLVM",
        "@llvm-project//mlir:MathToLibm",
        "@llvm-project//mlir:MemRefDialect",
        "@llvm-project//mlir:MemRefToLLVM",
        "@llvm-project//mlir:MemRefTransforms",
        "@llvm-project//mlir:NVVMToLLVMIRTranslation",  # buildcleaner: keep
        "@llvm-project//mlir:Pass",
        "@llvm-project//mlir:ROCDLToLLVMIRTranslation",  # buildcleaner: keep
        "@llvm-project//mlir:ReconcileUnrealizedCasts",
        "@llvm-project//mlir:SCFDialect",
        "@llvm-project//mlir:SCFToControlFlow",
        "@llvm-project//mlir:SCFTransforms",
        "@llvm-project//mlir:ShapeDialect",
        "@llvm-project//mlir:ShapeToStandard",
        "@llvm-project//mlir:ShapeTransforms",
        "@llvm-project//mlir:Support",
        "@llvm-project//mlir:TensorDialect",
        "@llvm-project//mlir:TensorTransforms",
        "@llvm-project//mlir:ToLLVMIRTranslation",
        "@llvm-project//mlir:TransformUtils",
        "@llvm-project//mlir:Transforms",
        "@llvm-project//mlir:VectorDialect",
        "@llvm-project//mlir:VectorToLLVM",
        "@llvm-project//mlir:VectorTransforms",
        "@local_xla//xla:debug_options_flags",
        "@local_xla//xla:xla_proto_cc",
        "@local_xla//xla/mlir_hlo",
        "@local_xla//xla/mlir_hlo:mhlo_passes",
        "@local_xla//xla/mlir_hlo:type_conversion",
        "@local_xla//xla/service/gpu:gpu_asm_opts_util",
        "@local_xla//xla/service/gpu:target_constants",
        "@local_xla//xla/stream_executor:device_description",
    ] + if_cuda_is_configured([
        "@local_tsl//tsl/platform:cuda_root_path",
        "@local_xla//xla/stream_executor/cuda:cuda_asm_compiler",
        "@local_xla//xla/service/gpu/llvm_gpu_backend:nvptx_backend",
    ]) + if_rocm_is_configured([
        "@local_xla//xla/stream_executor/gpu:asm_compiler",
        "@local_xla//xla/service/gpu/llvm_gpu_backend:amdgpu_backend",
        "//tensorflow/core/platform:rocm_rocdl_path",
    ]),
)

cc_library(
    name = "passes",
    srcs = [
        "broadcast_propagation_pass.cc",
        "buffer_reuse_pass.cc",
        "bufferize_pass.cc",
        "copy_cleanup_pass.cc",
        "embed_tf_framework_pass.cc",
        "func_to_jit_invocations.cc",
        "fuse_inner_parallel_loops_pass.cc",
        "merge_assuming_ops_pass.cc",
        "parallel_loops_to_sequential.cc",
        "rewrite_tf_framework_assert.cc",
        "same_shape_propagation.cc",
        "shape_simplification_pass.cc",
        "shape_to_descriptors_pass.cc",
        "tensorflow_abi_knowledge_propagation.cc",
    ],
    hdrs = ["passes.h"],
    compatible_with = get_compatible_with_portable(),
    deps = [
        ":bufferize",  # buildcleaner: keep
        ":embed_tf_framework",  # buildcleaner: keep
        ":kernel_gen_passes_inc_gen",
        ":tf_framework_legalize_to_llvm",  # buildcleaner: keep
        "//tensorflow/compiler/mlir/tools/kernel_gen/ir:tf_framework_ops",
        "@llvm-project//llvm:Support",
        "@llvm-project//mlir:Analysis",
        "@llvm-project//mlir:ArithDialect",
        "@llvm-project//mlir:BufferizationTransforms",
        "@llvm-project//mlir:ControlFlowDialect",
        "@llvm-project//mlir:FuncDialect",
        "@llvm-project//mlir:GPUDialect",
        "@llvm-project//mlir:IR",
        "@llvm-project//mlir:InferTypeOpInterface",
        "@llvm-project//mlir:LLVMDialect",
        "@llvm-project//mlir:LinalgDialect",
        "@llvm-project//mlir:MathDialect",
        "@llvm-project//mlir:MemRefDialect",
        "@llvm-project//mlir:Pass",
        "@llvm-project//mlir:SCFDialect",
        "@llvm-project//mlir:SCFToControlFlow",
        "@llvm-project//mlir:SCFTransforms",
        "@llvm-project//mlir:ShapeDialect",
        "@llvm-project//mlir:ShapeToStandard",
        "@llvm-project//mlir:ShapeTransforms",
        "@llvm-project//mlir:SideEffectInterfaces",
        "@llvm-project//mlir:Support",
        "@llvm-project//mlir:TensorDialect",
        "@llvm-project//mlir:TransformUtils",
        "@local_xla//xla/mlir_hlo",
        "@local_xla//xla/mlir_hlo:mhlo_passes",
        "@local_xla//xla/mlir_hlo:transforms_passes",
        "@stablehlo//:base",
    ],
)
