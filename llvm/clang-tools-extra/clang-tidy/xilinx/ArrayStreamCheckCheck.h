// (c) Copyright 2016-2020 Xilinx, Inc.
// All Rights Reserved.
//
// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#ifndef LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_XILINX_ARRAYSTREAMCHECKCHECK_H
#define LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_XILINX_ARRAYSTREAMCHECKCHECK_H

#include "../ClangTidy.h"

namespace clang {
namespace tidy {
namespace xilinx {

/// ArrayStreamCheckCheck - checks the function parameters which are
/// arrays/pointers/references. These arrays/pointers/references are implying
/// stream (axis/ap_fifo) interfaces in HLS.
/// We require those arrays to be volatile such that we can prevent
/// compiler optimizations (e.g. instruction reordering/deletion etc.)
/// that are illegal for HLS stream accesses.
class ArrayStreamCheckCheck : public ClangTidyCheck {
public:
  ArrayStreamCheckCheck(StringRef Name, ClangTidyContext *Context)
      : ClangTidyCheck(Name, Context) {}
  void registerMatchers(ast_matchers::MatchFinder *Finder) override;
  void check(const ast_matchers::MatchFinder::MatchResult &Result) override;
};

} // namespace xilinx
} // namespace tidy
} // namespace clang

#endif // LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_XILINX_ARRAYSTREAMCHECKCHECK_H
