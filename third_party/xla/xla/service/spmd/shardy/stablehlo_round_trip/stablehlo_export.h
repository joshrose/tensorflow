/* Copyright 2024 The OpenXLA Authors.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef XLA_SERVICE_SPMD_SHARDY_STABLEHLO_ROUND_TRIP_STABLEHLO_EXPORT_H_
#define XLA_SERVICE_SPMD_SHARDY_STABLEHLO_ROUND_TRIP_STABLEHLO_EXPORT_H_

#include "llvm/Support/CommandLine.h"
#include "mlir/Pass/PassOptions.h"
#include "mlir/Pass/PassRegistry.h"
#include "mlir/Support/LLVM.h"

namespace xla {
namespace sdy {

struct StablehloExportPipelineOptions
    : public mlir::PassPipelineOptions<StablehloExportPipelineOptions> {
  Option<bool> keepHloShardingConstraints{
    *this, "keep-hlo-sharding-constraints",
    llvm::cl::desc(
        "Whether to convert SDY sharding constraints to @Sharding custom "
        "calls - the HLO sharding constraint op. Else export "
        "them to MHLO copy ops. By default, export to MHLO copy ops."),
    llvm::cl::init(false)};
};

// Register the xla-sdy-stablehlo-export-pipeline.
void registerStablehloExportPipeline();

// Add the xla-sdy-stablehlo-export-pipeline in `pm`. The pipeline, including a
// sequence of passes, exports the Shardy dialect into an StableHLO module meant
// for the XLA compiler with HLO shardings.
void addStablehloExportPipeline(mlir::OpPassManager& pm,
                                const StablehloExportPipelineOptions& options =
                                    StablehloExportPipelineOptions());

}  // namespace sdy
}  // namespace xla

#endif  // XLA_SERVICE_SPMD_SHARDY_STABLEHLO_ROUND_TRIP_STABLEHLO_EXPORT_H_
