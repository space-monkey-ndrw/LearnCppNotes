#include "ch10s8.h"
#include <iostream>
#include <string>
#include <string_view>
#include <typeinfo>

int addCh10s8(int x, int y) {
    return x+y;
}

std::string_view getStringCh10s8() {
    using namespace std::literals;  // required to use literal suffixes - included in 'using namespace std' below at start of ch10s8()
    auto s {"some string"sv};
    return s;
}

void ch10s8() {
    using namespace std; // bad practice in real life, fine for notes

    cout << "\n=== Chapter 10, Section 8 - type deduction w/ the auto keyword ===\n\n";
    auto aa {5.0};
    cout << "use auto keyword to make compiler deduce type: auto d {5.0} is: " << aa << '\n';

    cout << "can also use with function calls, literal suffixes, and const / constexpr\n";

    auto sum { addCh10s8(3, 4) };
    cout << "auto sum { add(3+4) } prints as: " << sum << '\n';
    auto a {1.23f};
    auto b {5u};
    cout << "auto a {1.23f} is: " << a << " and auto b {5u} is: " << b << '\n';

    cout << "type deduction must have something to deduce from\n";
    cout << "  can't just do auto a; or auto b {}; or auto c {foo()}; where foo() returns void\n";

    cout << "type deduction drops const from the deduced type\n";
    const int c { 5 };
    auto d { c };
    cout << "const int c { 5 }; has type const int, auto d { c }; has type int (not const)\n";

    cout << "type deduction for string literals is const char*, not std::string\n";
    cout << "  if you want the deduced type to be std::string or std::string_view, use literal suffixes s or sv\n";
    // using namespace std::literals;  // required to use literal suffixes - included by the 'using namespace std' at start of ch10s8()
    auto s1 {"goo"s};
    auto s2 {"moo"sv};
    cout << "auto s1 {\"goo\"s}; is type deduced as std::string, and auto s2 {\"moo\"sv}; is std::string_view\n";

    cout << "constexpr is not part of type system, cannot be deduced as part of type deduction\n";
    cout << "constexpr variable is implicitly const, which will be dropped by type deduction\n";
    constexpr double e { 3.4 };  // e has type const double (constexpr not part of type, const is implicit)

    auto f { e };                // f has type double (const dropped)
    const auto g { e };          // g has type const double (const dropped but reapplied)
    constexpr auto h { e };      // h has type const double (const dropped but implicitly reapplied by constexpr)

    cout << "e is type constexpr double, f is double, g is const double, and h is constexpr double\n";

    cout << "type deduction has benefits and downsides:\n";
    cout << "benefits:\n";
    cout << "  - more readability, all auto var's line up in code\n";
    cout << "  - forces you to initialize your variables (doesn't work on uninitialized var's)\n";
    cout << "  - guaranteed to have no unintended performance-impacting conversions (example in code)\n";
    // std::string_view getStringCh10s8(); is some function that returns a std::string_view
    std::string s3 { getStringCh10s8() }; // bad: expensive conversion from std::string_view to std::string (assuming you didn't want this)
    auto s4 { getStringCh10s8() };        // good: no conversion required
    cout << "  s3 is type: std::string which could be an unintended expensive conversion\n";
    cout << "  s4 is type: std::string_view which has no unintended conversion\n";

    cout << "downsides:\n";
    cout << "  - obscures object's type info in code (IDE should display type on hover)\n";
    cout << "    can cause errors with int/float division, unsigned values, etc.\n";
    cout << "  - if type of initializer changes, deduced type changes (maybe unexpectedly)\n";

    auto i {5}; // oops, we wanted a double here - but type deduction will make this an int
    auto j {4}; // same... wanted a double here but deduced to int
    cout << i/j << " integer division, when we wanted floating point division\n";

    auto gravity {9.8};
    auto sumCh10s8 { addCh10s8(4, 5) + gravity };
    cout << "changing return type of add or type of gravity variable will change deduced type of sum: " << sumCh10s8 << '\n';
}