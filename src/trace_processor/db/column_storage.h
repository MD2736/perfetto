/*
 * Copyright (C) 2022 The Android Open Source Project
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

#ifndef SRC_TRACE_PROCESSOR_DB_COLUMN_STORAGE_H_
#define SRC_TRACE_PROCESSOR_DB_COLUMN_STORAGE_H_

#include "src/trace_processor/containers/nullable_vector.h"

namespace perfetto {
namespace trace_processor {

// Base class for allowing type erasure when defining plug-in implementations
// of backing storage for columns.
class ColumnStorageBase {
 public:
  ColumnStorageBase() = default;
  virtual ~ColumnStorageBase();

  ColumnStorageBase(const ColumnStorageBase&) = delete;
  ColumnStorageBase& operator=(const ColumnStorageBase&) = delete;

  ColumnStorageBase(ColumnStorageBase&&) = default;
  ColumnStorageBase& operator=(ColumnStorageBase&&) noexcept = default;
};

// Class used for implementing storage for non-null columns.
template <typename T>
class ColumnStorage : public ColumnStorageBase {
 public:
  ColumnStorage() = default;

  explicit ColumnStorage(const ColumnStorage&) = delete;
  ColumnStorage& operator=(const ColumnStorage&) = delete;

  ColumnStorage(ColumnStorage&&) = default;
  ColumnStorage& operator=(ColumnStorage&&) noexcept = default;

  T Get(uint32_t idx) const { return deque_[idx]; }
  void Append(T val) { deque_.emplace_back(val); }
  void Set(uint32_t idx, T val) { deque_[idx] = val; }
  uint32_t size() const { return static_cast<uint32_t>(deque_.size()); }

  template <bool IsDense>
  static ColumnStorage<T> Create() {
    static_assert(!IsDense, "Invalid for non-null storage to be dense.");
    return ColumnStorage<T>();
  }

 private:
  std::deque<T> deque_;
};

// Class used for implementing storage for nullable columns.
template <typename T>
class ColumnStorage<base::Optional<T>> : public ColumnStorageBase {
 public:
  ColumnStorage() = default;

  explicit ColumnStorage(const ColumnStorage&) = delete;
  ColumnStorage& operator=(const ColumnStorage&) = delete;

  ColumnStorage(ColumnStorage&&) = default;
  ColumnStorage& operator=(ColumnStorage&&) noexcept = default;

  base::Optional<T> Get(uint32_t idx) const { return nv_.Get(idx); }
  void Append(T val) { nv_.Append(val); }
  void Append(base::Optional<T> val) { nv_.Append(val); }
  void Set(uint32_t idx, T val) { nv_.Set(idx, val); }
  uint32_t size() const { return nv_.size(); }
  bool IsDense() const { return nv_.IsDense(); }

  template <bool IsDense>
  static ColumnStorage<base::Optional<T>> Create() {
    return IsDense ? ColumnStorage<base::Optional<T>>::Dense()
                   : ColumnStorage<base::Optional<T>>::Sparse();
  }

 private:
  explicit ColumnStorage(NullableVector<T> nv) : nv_(std::move(nv)) {}

  static ColumnStorage<base::Optional<T>> Sparse() {
    return ColumnStorage<base::Optional<T>>(NullableVector<T>::Sparse());
  }
  static ColumnStorage<base::Optional<T>> Dense() {
    return ColumnStorage<base::Optional<T>>(NullableVector<T>::Dense());
  }

  NullableVector<T> nv_;
};

}  // namespace trace_processor
}  // namespace perfetto

#endif  // SRC_TRACE_PROCESSOR_DB_COLUMN_STORAGE_H_
