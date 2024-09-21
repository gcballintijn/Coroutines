//
// co_yield_value_2.cxx -- Coroutines
//
// Coroutine, blocks twice, yielding a value.
//

#include <cstdlib>
#include <coroutine>
#include <iostream>

struct Promise;
using Handle = std::coroutine_handle<Promise>;

struct Coroutine {
    using promise_type = Promise;

    Promise& _promise;

    void resume() { Handle::from_promise(_promise).resume(); }
};

struct Promise {
    int _value{0};

    auto get_return_object()        {return Coroutine{*this}; }
    auto initial_suspend()          { return std::suspend_always{}; }
    auto final_suspend() noexcept   { return std::suspend_never{}; }
    auto yield_value(int value)     { _value = value; return std::suspend_always{}; }
    void unhandled_exception()      {}
};

Coroutine
coroutine()
{
    std::cout << "coroutine(): yield 42" << std::endl;

    co_yield 42;

    std::cout << "coroutine(): end" << std::endl;
}

int
main(int, char const **)
{
    std::cout << "main(): start" << std::endl;

    auto instance = coroutine();
    instance.resume();
    std::cout << "main(): value = " << instance._promise._value << std::endl;
    instance.resume();

    std::cout << "main(): end" << std::endl;
    return EXIT_SUCCESS;
}
