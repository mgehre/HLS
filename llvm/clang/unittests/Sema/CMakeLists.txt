set(LLVM_LINK_COMPONENTS
  Support
  )

add_clang_unittest(SemaTests
  ExternalSemaSourceTest.cpp
  APIntTypeTest.cpp
  CodeCompleteTest.cpp
  )

target_link_libraries(SemaTests
  PRIVATE
  clangAST
  clangBasic
  clangFrontend
  clangParse
  clangSema
  clangTooling
  )
