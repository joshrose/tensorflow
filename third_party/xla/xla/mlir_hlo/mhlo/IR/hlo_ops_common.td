/* Copyright 2022 The OpenXLA Authors.

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

#ifndef MLIR_HLO_DIALECT_MHLO_IR_HLO_OPS_COMMON
#define MLIR_HLO_DIALECT_MHLO_IR_HLO_OPS_COMMON

def MHLO_Dialect : Dialect {
  let name = "mhlo";
  let cppNamespace = "::mlir::mhlo";

  let useDefaultAttributePrinterParser = 0;
  let useDefaultTypePrinterParser = 0;
}

include "mhlo/IR/hlo_base.td"
include "mhlo/IR/hlo_ops_enums.td"
include "mhlo/IR/hlo_ops_attrs.td"
include "mhlo/IR/hlo_ops_typedefs.td"

#endif // MLIR_HLO_DIALECT_MHLO_IR_HLO_OPS_COMMON
