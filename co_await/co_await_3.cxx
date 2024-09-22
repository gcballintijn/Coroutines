//
// co_await_3.cxx -- Coroutines
//
// Coroutine, block, data in, resume, and data out.
//

#include <cstdlib>
#include <coroutine>
#include <iostream>

struct Promise;
using Handle = std::coroutine_handle<Promise>;

struct Coroutine {
    using promise_type = Promise;

    Handle _handle;

    int resume();
};

struct Promise {
    int _returned_value{0};

    auto get_return_object()        { return Coroutine{Handle::from_promise(*this)}; }
    auto initial_suspend()          { return std::suspend_never{}; }
    auto final_suspend() noexcept   { return std::suspend_never{}; }
    void return_value(int value)    { _returned_value = value; }
    void unhandled_exception()      {}
};

struct Blocker {
    int _provided_value{0};

    bool await_ready()          { return false; }
    void await_suspend(Handle)  {}
    int await_resume()          { return _provided_value; }
};

Blocker blocker{};

int Coroutine::resume() {
    _handle.resume();
    return _handle.promise()._returned_value;
}

Coroutine
coroutine()
{
    std::cout << "coroutine(): suspend_always" << std::endl;

    int value = co_await blocker;

    std::cout << "coroutine(): co_return " << value << std::endl;
    co_return value;
}

int
main(int, char const **)
{
    std::cout << "main(): start" << std::endl;

    auto instance = coroutine();
    blocker._provided_value = 42;
    int value = instance.resume();

    std::cout << "main(): end, value = " << value << std::endl;
    return EXIT_SUCCESS;
}
