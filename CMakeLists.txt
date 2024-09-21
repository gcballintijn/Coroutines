cmake_minimum_required(VERSION 3.16)

project(Coroutines
    VERSION 0.0.1
    DESCRIPTION "My coroutine examples project."
    LANGUAGES CXX
)

add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags
    INTERFACE
    cxx_std_20
)

add_library(compiler_options INTERFACE)
target_compile_options(compiler_options
    INTERFACE
    -fcoroutines
    -Wall
    -Wextra
    -pedantic
)

add_executable(cr_return_void cr_return_void.cxx)
target_link_libraries(cr_return_void
    PRIVATE
    compiler_flags
    compiler_options
)

add_executable(cr_return_value cr_return_value.cxx)
target_link_libraries(cr_return_value
    PRIVATE
    compiler_flags
    compiler_options
)

add_executable(cr_yield_value_1 cr_yield_value_1.cxx)
target_link_libraries(cr_yield_value_1
    PRIVATE
    compiler_flags
    compiler_options
)

add_executable(cr_yield_value_2 cr_yield_value_2.cxx)
target_link_libraries(cr_yield_value_2
    PRIVATE
    compiler_flags
    compiler_options
)

add_executable(cr_yield_value_3 cr_yield_value_3.cxx)
target_link_libraries(cr_yield_value_3
    PRIVATE
    compiler_flags
    compiler_options
)
