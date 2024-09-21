//
// cr_return_value.cxx -- Coroutines
//
// Degenerate coroutine, does nothing, just falls through with a return value.
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
    void return_value(int value)    { _value = value; }
    void unhandled_exception()      {}
};

Coroutine
coroutine()
{
    std::cout << "coroutine(): return 42" << std::endl;

    co_return 42;
}

int
main(int, char const **)
{
    std::cout << "Coroutine: return value" << std::endl;

    auto instance = coroutine();

    std::cout << "return value = " << instance._promise._value << std::endl;

    return EXIT_SUCCESS;
}
