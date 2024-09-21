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

add_subdirectory(co_return)
add_subdirectory(co_yield)
add_subdirectory(co_await)
