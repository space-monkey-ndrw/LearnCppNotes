#include <iostream>
#include "ch10s6.h"

using namespace std;

void ch10s6() {
    cout << "\n === Chapter 10, Section 6: Explicit Type Conversion === \n\n";
    int x {10};
    int y {4};
    double d = x/y; // does integer division, d becomes 2.0
    // need to static_cast either x or y to force floating point division
    
    // C-style cast:
    cout << (double)x / y << '\n';

    // C-style function style cast:
    cout << double(x) / y << '\n';

    cout << "avoid C-style casts\n";
    // they can perform a variety of different conversions, depending on how it's used
    //  static cast, const cast, or reinterpret cast
    // unclear which casts it will perform
    // also makes code harder to read & search for

    char c {'a'};
    cout << static_cast<int>(c) << " = 'a' as int\n";

    cout << "floating point division with static cast x / y = " << static_cast<double>(x) / y << '\n';

    cout << "can suppress narrowing conversion warnings with static cast: \n";
    int i {48};
    char c1 { static_cast<char>(i) };
    cout << "int i 48 static_cast to char is: " << c1 << '\n';

    i = 100;
    i = static_cast<int>(i/2.5);
    cout << "int i 100 / 2.5 static cast to int is: " << i << '\n';

    // casting vs initializing a temp object
    cout << "temp double initialized with int x 10, / y 2.5 is: " << double{x} / y << '\n'; // ok if int is 32b, narrowing if x is 64b
    // want floating point division, so one operand needs to be floating point type

    unsigned char c2 { 'a' };
    // cout << unsigned int { c2 } << '\n';
    // compile error because direct-list-initialization of a temporary only allows single-word type names (a syntax quirk of C++)
    // int {x} is valid, but unsigned int {x} is not
    // this gives line 44: error: expected primary-expression before ‘<<’ token

    using uint = unsigned int;
    cout << "temp unsigned int, initialized as unsigned char 'a': " << uint {c} << '\n';
    // we can get around the syntax quirk above using a single-word type alias
}