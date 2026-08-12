#include "ch10quiz.h"
#include <iostream>
using namespace std;

void ch10quiz1() {
    cout << "what type of conversion in each case?  no conversion, numeric promotion, numeric conversion, or won't compile due to narrowing conversion (Q&A in code comments)\n";
    int a { 5 }; // 1a
    int b { 'a' }; // 1b
    // int c { 5.4 }; // 1c
    int d { true }; // 1d
    int e { static_cast<int>(5.4) }; // 1e

    double f { 5.0f }; // 1f
    double g { 5 }; // 1g

    // Extra credit section
    long h { 5 }; // 1h

    float i { f }; // 1i (uses previously defined variable f)
    float j { 5.0 }; // 1j

    // answers
    // 1a - no conversion
    // 1b - numeric promotion (char to int)
    // 1c - won't compile due to narrowing conversion (won't compile on my machine)
    // 1d - numeric promotion (bool to int)
    // 1e - numeric conversion  (double to int)
    // 1f - numeric promotion (float to double)
    // 1g - numeric conversion (int to double)
    // 1h - numeric conversion (int to long)
    // 1i - won't compile due to narrowing conversion (will compile on my machine, only gives a warning)
    // 1j - numeric conversion (double to float) (allowed since 5.0 is constexpr and fits in range of float)
}

using Degrees = double;
using Radians = double;

namespace constants {
    constexpr double pi {3.14159};
}

Radians convertToRadians (Degrees degrees) {
    return degrees * constants::pi / 180;
}

void ch10quiz2() {
    cout << "2a) Update program to use type aliases for degrees and radians values\n";
    cout << "Enter a number of degrees: ";
    Degrees degrees {};
    cin >> degrees;

    Radians radians { convertToRadians(degrees) };
    cout << degrees << " degrees is " << radians << " radians\n";

    cout << "2b) explain why this statement will/won't compile: radians = degrees (answer in code comments)\n";
    // it will compile, both Degrees and Radians are aliases for double
}

void ch10quiz() {
    ch10quiz1();
    ch10quiz2();
}