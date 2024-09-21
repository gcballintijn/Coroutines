# Coroutines
Coroutine example code.

Degenerate cases.
* `co_return_void` -- does nothing, just falls through.
* `co_return_value` -- does nothing, just falls through with a return value.
* `co_yield_value_1` -- does nothing, just falls through with a return value.
* `co_yield_value_2` -- does nothing, just yields a value (blocking).
* `co_await_1` -- does nothing, just falls through.

Blocking.
* `cr_yield_value_3` -- blocks twice, yielding a value.
* `co_await_2` -- blocks twice.
