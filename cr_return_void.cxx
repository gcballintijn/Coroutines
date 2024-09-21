//
// cr_return_void.cxx -- Coroutines
//
// Degenerate coroutine, does nothing, just falls through.
//

#include <cstdlib>
#include <coroutine>
#include <iostream>

struct Promise;

struct Coroutine {
    using promise_type = Promise;
};

struct Promise {
    auto get_return_object()        { return Coroutine{}; }
    auto initial_suspend()          { return std::suspend_never{}; }
    auto final_suspend() noexcept   { return std::suspend_never{}; }
    void return_void()              {}
    void unhandled_exception()      {}
};

Coroutine
coroutine()
{
    std::cout << "coroutine(): return void" << std::endl;
    co_return;
}

int
main(int, char const **)
{
    std::cout << "main(): start()" << std::endl;

    coroutine();

    std::cout << "main(): end()" << std::endl;
    return EXIT_SUCCESS;
}
