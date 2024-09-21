
add_executable(co_return_void co_return_void.cxx)
target_link_libraries(co_return_void
    PRIVATE
    compiler_flags
    compiler_options
)

add_executable(co_return_value co_return_value.cxx)
target_link_libraries(co_return_value
    PRIVATE
    compiler_flags
    compiler_options
)
