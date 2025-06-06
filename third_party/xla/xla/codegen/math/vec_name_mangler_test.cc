/* Copyright 2025 The OpenXLA Authors.

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

#include "xla/codegen/math/vec_name_mangler.h"

#include <gtest/gtest.h>

namespace xla::codegen::math {
namespace {

TEST(VecNameManglerTest, GetMangledName) {
  EXPECT_EQ(GetMangledNamePrefix(
                /*is_masked=*/false, /*vector_width=*/4,
                {VecParamCardinality::kScalar, VecParamCardinality::kVector,
                 VecParamCardinality::kLinear}),
            "_ZGV_LLVM_N4svl");
}

TEST(VecNameManglerTest, GetTanhMangledPrefix) {
  EXPECT_EQ(GetMangledNamePrefix(
                /*is_masked=*/false, /*vector_width=*/4,
                {VecParamCardinality::kVector}),
            "_ZGV_LLVM_N4v");
}

}  // namespace
}  // namespace xla::codegen::math
