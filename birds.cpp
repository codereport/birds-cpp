
// Godbolt: https://godbolt.org/z/v8s6jT9od

#include <stdio.h>

auto I  = [](auto a) { return a; };                                                       // Identity
auto K  = [](auto a) { return [=](auto b) { return a; }; };                               // Kestrel
auto Ki = [](auto a) { return [=](auto b) { return K(I)(a)(b); }; };                      // Kite
auto W  = [](auto a) { return [=](auto b) { return a(b)(b); }; };                         // Warbler
auto C  = [](auto a) { return [=](auto b) { return [=](auto c) { return a(c)(b); }; }; }; // Cardinal
auto B  = [](auto a) { return [=](auto b) { return [=](auto c) { return a(b(c)); }; }; }; // Bluebird

auto B1 = [](auto a) { 
    return [=](auto b) { 
        return [=](auto c) { 
            return [=](auto d) { 
                return a(b(c(d))); }; }; }; }; // Blackbird

int main () {

    auto times   = [](auto a) { return [a](auto b) { return a * b; }; };
    auto add     = [](auto a) { return [a](auto b) { return a + b; }; };
    auto square  = W(times); 

    auto const a = K(42)(1729);
    auto const b = I(42);
    auto const c = Ki(42)(1729);
    auto const d = C(K)(42)(1729);
    auto const e = square(5);
    auto const f = B(add(1))(times(2))(10);
    auto const g = B1(times(2))(add(1))(times(2))(10);

    printf("%i, %i, %i, %i, %i, %i, %i", a, b, c, d, e, f, g);

    return 0;
}
