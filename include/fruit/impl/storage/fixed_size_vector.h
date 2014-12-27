/*
 * Copyright 2014 Google Inc. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FRUIT_FIXED_SIZE_VECTOR_H
#define FRUIT_FIXED_SIZE_VECTOR_H

namespace fruit {
namespace impl {

/**
 * Similar to std::vector<T>, but the capacity is fixed at construction time, and no reallocations ever happen.
 */
template <typename T>
class FixedSizeVector {
private:
  // v_end is before v_begin here, because it's the most commonly accessed field.
  T* v_end;
  T* v_begin;
#ifdef FRUIT_EXTRA_DEBUG
  T* v_end_of_storage;
#endif
  
public:
  FixedSizeVector(std::size_t capacity = 0);
  ~FixedSizeVector();
  
  // This yields undefined behavior (instead of reallocating) if the vector's capacity is exceeded.
  void push_back(T x);
  
  T* begin();
  T* end();
};

} // namespace impl
} // namespace fruit

#include "fixed_size_vector.defn.h"

#endif // FRUIT_FIXED_SIZE_VECTOR_H
