//
// cr_yield_value_1.cxx -- Coroutines
//
// Degenerate coroutine, does nothing, just yields a value (falling through).
//

#include <cstdlib>
#include <coroutine>
#include <iostream>

struct Promise;

struct Coroutine {
    using promise_type = Promise;

    Promise& _promise;
};

struct Promise {
    int _value{0};

    auto get_return_object()        { return Coroutine{*this}; }
    auto initial_suspend()          { return std::suspend_never{}; }
    auto final_suspend() noexcept   { return std::suspend_never{}; }
    auto yield_value(int value)     { _value = value; return std::suspend_never{}; }
    void unhandled_exception()      {}
};

Coroutine
coroutine()
{
    std::cout << "coroutine(): yield 42" << std::endl;

    co_yield 42;

    std::cout << "coroutine(): return" << std::endl;
}

int
main(int, char const **)
{
    std::cout << "Coroutine: yield value" << std::endl;

    auto instance = coroutine();

    std::cout << "return value = " << instance._promise._value << std::endl;

    return EXIT_SUCCESS;
}
