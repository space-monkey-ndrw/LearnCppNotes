#include <iostream>
#include "ch10s4.h"

int someFcn(int i) {
    return i;
}

void print(unsigned int u) {
    std::cout << u << '\n';
}

void ch10s4() {
    std::cout << " === Chapter 10, Section 4: Narrowing Conversions === \n\n";

    double d{5.0};

    std::cout << "printing someFcn(d) gives: " << someFcn(d) << '\n'; // bad - implicit narrowing conversion will give compiler warning

    // good - cast makes narrowing conversion explicit
    std::cout << "printing someFcn(static_cast<int>(d)) gives: " << someFcn(static_cast<int>(d)) << '\n'; // no warning

    // int i {3.5}; won't compile
    std::cout << "doing int i {5.0} won't compile\n";

    int i{static_cast<int>(d)};
    std::cout << "but static_cast<int>(d) will work: " << i << '\n';

    std::cout << "Enter an integral value (5 or -5): ";
    int n{};
    std::cin >> n; // enter 5 or -5
    print(n);
    std::cout << "conversion of -5 to unsigned won't preserve value\n";

    constexpr int n1{5};    // note - constexpr
    unsigned int u1 { n1 }; // conversion is not narrowing due to exclusion clause
    constexpr int n2 { -5 }; // note - constexpr
    // unsigned int u2 { n2 }; // compile error - conversion is narrowing due to value change

    // constexpr int n3 { 5.0 }; // converting from floating point to int does not have
    // an exclusion clause, so is always narrowing even when value fits in range
    // of the destination type

    // We can avoid literals with suffixes
    unsigned int u { 5 }; // okay (we don't need to use `5u`)
    float f { 1.5 };      // okay (we don't need to use `1.5f`)

    // We can avoid static_casts
    constexpr int n4{ 5 };
    double d2 { n4 };       // okay (we don't need a static_cast here)
    short s { 5 };        // okay (there is no suffix for short, we don't need a static_cast here)

    // note - initializing a narrower / lesser ranked floating point type with a constexpr value is allowed as long as in range of destination type, even if the destination type doesn't have enough precision to store the exact value
    float f2 { 1.23456789 }; // not a narrowing conversion, even though precision lost!
}