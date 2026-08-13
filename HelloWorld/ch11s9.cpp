#include "ch11s9.h"
#include <iostream>
#include <cassert>
#include <cmath> // for std::sqrt

using namespace std;

template <int N>
void print11s9()
{
    cout << N << '\n'; // use value of N here
}

// call to print11s9<5>() and compiler creates something like this:
// template <>
// void print11s9<5>()
// {
//     cout << 5 << '\n';
// }

double getSqrt11s9(double d)
{
    assert(d >= 0.0 && "getSqrt11s9(): d must be non-negative");

    // the assert above will likely compile out in non-debug builds
    if (d>=0)
        return std::sqrt(d);

    return 0.0;
}

// template <double D> // requires C++20 for floating point non-type param's
// double getSqrt11s9()
// {
//     static_assert(D >= 0.0 && "getSqrt11s9(): d must be non-negative");

//     if constexpr (D>=0) // ignore the constexpr here for this example
//         return std::sqrt(D); // std::sqrt isn't a constexpr func (until C++26)

//     return 0.0;
// }

// having this overloaded func template with a different kind of NTT param results in ambiguous matches:
// template <char N>
// void print11s9()
// {
//     cout << N << '\n';
// }

template <auto N> // deduce NTT. param from template arg
void printAuto11s9()
{
    cout << N << '\n';
}

template <int N>
constexpr int factorial ()
{
    int count {N};
    int product {N};
    static_assert(N >= 0, "factorial: N must be >= 0");

    if constexpr (N > 0)
    {
        while (count >= 2)
        {
            count -= 1;
            product *= count;
        }
        return product;
    }

    return 1;
}

void ch11s9quizA()
{
    static_assert(factorial<0>() == 1);
    cout << "factorial<" << 0 << ">() is: " << factorial<0>() << '\n';
    static_assert(factorial<3>() == 6);
    cout << "factorial<" << 3 << ">() is: " << factorial<3>() << '\n';
    static_assert(factorial<5>() == 120);
    cout << "factorial<" << 5 << ">() is: " << factorial<5>() << '\n';
    cout << "factorial<" << 7 << ">() is: " << factorial<7>() << '\n';

    // factorial<-3>(); // should fail to compile
}

void ch11s9() {
    cout << "\n === Chapter 11 Section 9 - Non-type template param's === \n\n";
    
    cout << "non-type template param = fixed type that serves as a placeholder for a constexpr val passed in as a template arg\n";
    cout << "can be any of the following types: \n";
    cout << " - integral type\n";
    cout << " - enumeration type\n";
    cout << " - std::nullptr_t\n";
    cout << " - a floating point type (since C++20)\n";
    cout << " - a pointer or reference to an obj\n";
    cout << " - a pointer or reference to a func\n";
    cout << " - a pointer or reference to a member func\n";
    cout << " - a literal class type (since C++20)\n";

    cout << "\nwe saw an example in chO.1 with std::bitset\n";
    cout << "std::bitset<8> bits { 0b0000'0101 }; // the <8> is a non-type template param\n";
    cout << "in this case, the N-T.T. param is used to tell std::bitset how many bits to store\n";

    cout << "\ndefining our own N-T.T. param's\n";
    cout << "print11s9<5>() prints: ";
    print11s9<5>(); // 5 is our NTT. arg
    cout << "like T is typically used for first type template param, N is convention for an int NTT. param\n";

    cout << "\nwhat are NTT. param's useful for?\n";
    cout << "as of C++20 func param's cannot be constexpr (for normal & constexpr & consteval func's)\n";
    cout << "getSqrt11s9(5.0) is: " << getSqrt11s9(5.0) << '\n';
    // crashes at runtime
    // cout << "getSqrt11s9(-5.0) is: " << getSqrt11s9(-5.0) << '\n';
    // would be better if we could static_assert so that errors like this will be caught at compile time
    // but, static_assert requires a constexpr, and func param's can't be constexpr
    cout << "getSqrt11s9(-5.0) will crash at runtime\n";
    cout << "to use static_assert so it errors at compile time instead, use NTT. param\n";
    // i'm using C++17 so these two won't work:
    // cout << "getSqrt11s9<5.0>() is: " << getSqrt11s9<5.0>() << '\n';
    // cout << "getSqrt11s9<-5.0>() is: " << getSqrt11s9<-5.0>() << '\n';
    cout << "NTT. params are used primarily when we need to pass constexpr val's to func's (or class types) so they can be used in contexts that require a constexpr\n";
    
    cout << "\nimplicit conversions for NTT. arg's\n";
    cout << "certain NTT. arg's can be implicitly converted to match a NTT. param of a different type\n";
    cout << "  print11s9<5>() no conversion needed: ";
    print11s9<5>();
    cout << "  print11s9<'c'>() and 'c' converted to type int, prints: ";
    print11s9<'c'>();
    cout << "in this context, only certain types of constexpr are allowed.  most common are: \n";
    cout << " - integral promotions (eg char to int)\n";
    cout << " - integral conversions (eg char to long or int to char)\n";
    cout << " - user-defined conversions (eg some program-defined class to int)\n";
    cout << " - Lvalue to Rvalue conversions (eg some variable x to the value of x)\n";
    cout << "note this list is less permissive than the type of implicit conversions allowed for list initialization\n";
    cout << "  for example, can list-init a var of type double using a constexpr int\n";
    cout << "  but a constexpr int NTT. arg will not convert to a double NTT. param\n";
    cout << "unlike with normal func's, the algorithm for matching func template calls to func template def'ns is simple\n";
    cout << "and certain matches are not prioritized over others based on the type of conversion required (or lack thereof)\n";
    cout << "  Thus, if a func template is overloaded for diff kinds of NTT. param's, it can easily become an ambiguous match\n";
    // print<5>();   // ambiguous match with int N = 5 and char N = 5
    // print<'c'>(); // ambiguous match with int N = 99 and char N = 'c'

    cout << "\ntype deduction for NTT. param's using auto keyword\n";
    cout << "as of C++17, NTT. params may use auto to have compiler deduce the NTT. param from the template arg\n";
    cout << "printAuto11s9<5>() and N is deduced as int 5: \n";
    printAuto11s9<5>();
    cout << "printAuto11s9<'c'>() and N is deduced as char c: \n";
    printAuto11s9<'c'>();

    ch11s9quizA();
}