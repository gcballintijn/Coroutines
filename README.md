# Coroutines
Coroutine example code.

Degenerate cases.
* `cr_return_void` -- does nothing, just falls through.
* `cr_return_value_1` -- does nothing, just falls through with a return value.
* `cr_return_value_2` -- does nothing, just yields a value (blocking).

Blocking.
* `cr_return_value_3` -- blocks twice, yielding a value.
