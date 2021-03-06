/* Copyright (c) 2019 PaddlePaddle Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. */

#pragma once

namespace paddle {
namespace lite {
namespace arm {
namespace math {

template <typename T>
void reduce_sum_onedim(const T* src, T* dst, int left, int right, int dim);

template <typename T>
void reduce_sum_n(const T* src,
                  T* dst,
                  int num_in,
                  int channel_in,
                  int height_in,
                  int width_in);

template <typename T>
void reduce_sum_c(const T* src,
                  T* dst,
                  int num_in,
                  int channel_in,
                  int height_in,
                  int width_in);

template <typename T>
void reduce_sum_h(const T* src,
                  T* dst,
                  int num_in,
                  int channel_in,
                  int height_in,
                  int width_in);

template <typename T>
void reduce_sum_w(const T* src,
                  T* dst,
                  int num_in,
                  int channel_in,
                  int height_in,
                  int width_in);

template <typename T>
void reduce_sum_nc(const T* src,
                   T* dst,
                   int num_in,
                   int channel_in,
                   int height_in,
                   int width_in);

template <typename T>
void reduce_sum_ch(const T* src,
                   T* dst,
                   int num_in,
                   int channel_in,
                   int height_in,
                   int width_in);

template <typename T>
void reduce_sum_hw(const T* src,
                   T* dst,
                   int num_in,
                   int channel_in,
                   int height_in,
                   int width_in);

template <typename T>
void reduce_sum_all(const T* src, T* dst, int all_size);

}  // namespace math
}  // namespace arm
}  // namespace lite
}  // namespace paddle
