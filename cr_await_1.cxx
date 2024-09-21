//
// cr_await_1.cxx -- Coroutines
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
    void unhandled_exception()      {}
};

Coroutine
coroutine()
{
    std::cout << "coroutine(): suspend_never" << std::endl;

    co_await std::suspend_never{};

    std::cout << "coroutine(): return" << std::endl;
}

int
main(int, char const **)
{
    std::cout << "main(): start" << std::endl;

    coroutine();

    std::cout << "main(): end" << std::endl;
    return EXIT_SUCCESS;
}
