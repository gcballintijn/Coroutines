//
// co_await.cxx -- Coroutines
//
// Coroutine, blocks twice.
//

#include <cstdlib>
#include <coroutine>
#include <iostream>

struct Promise;
using Handle = std::coroutine_handle<Promise>;

struct Coroutine {
    using promise_type = Promise;

    Handle _handle;
};

struct Promise {
    auto get_return_object()        { return Coroutine{Handle::from_promise(*this)}; }
    auto initial_suspend()          { return std::suspend_always{}; }
    auto final_suspend() noexcept   { return std::suspend_never{}; }
    void unhandled_exception()      {}
};

Coroutine
coroutine()
{
    std::cout << "coroutine(): suspend_always" << std::endl;

    co_await std::suspend_always{};

    std::cout << "coroutine(): return" << std::endl;
}

int
main(int, char const **)
{
    std::cout << "main(): start" << std::endl;

    auto instance = coroutine();
    instance._handle.resume();
    instance._handle.resume();

    std::cout << "main(): end" << std::endl;
    return EXIT_SUCCESS;
}
