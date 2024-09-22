
add_executable(co_await_1 co_await_1.cxx)
target_link_libraries(co_await_1
    PRIVATE
    compiler_flags
    compiler_options
)

add_executable(co_await_2 co_await_2.cxx)
target_link_libraries(co_await_2
    PRIVATE
    compiler_flags
    compiler_options
)

add_executable(co_await_3 co_await_3.cxx)
target_link_libraries(co_await_3
    PRIVATE
    compiler_flags
    compiler_options
)
