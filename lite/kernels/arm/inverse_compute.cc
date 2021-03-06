// Copyright (c) 2019 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "lite/kernels/arm/inverse_compute.h"
#include <string>
#include <vector>
#include "lite/backends/arm/math/funcs.h"
#include "lite/core/op_registry.h"
#include "lite/core/tensor.h"
#include "lite/core/type_system.h"

#include "lite/core/profile/precision_profiler.h"

namespace paddle {
namespace lite {
namespace kernels {
namespace arm {

template <typename T>
void InverseCompute<T>::Run() {
  auto& param = Param<operators::InverseParam>();
  lite::Tensor* input = param.Input;
  lite::Tensor* output = param.Output;

  lite::arm::math::inverse_func<T>(input, output);
#ifdef LITE_WITH_PROFILE
  kernel_func_name_ = "inverse_func";
#endif
  return;
}

}  // namespace arm
}  // namespace kernels
}  // namespace lite
}  // namespace paddle

REGISTER_LITE_KERNEL(inverse,
                     kARM,
                     kFloat,
                     kNCHW,
                     paddle::lite::kernels::arm::InverseCompute<float>,
                     fp32)
    .BindInput("Input",
               {LiteType::GetTensorTy(TARGET(kARM), PRECISION(kFloat))})
    .BindOutput("Output",
                {LiteType::GetTensorTy(TARGET(kARM), PRECISION(kFloat))})
    .BindPaddleOpVersion("inverse", 1)
    .Finalize();