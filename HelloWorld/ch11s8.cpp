#include "ch11s8.h"
#include <iostream>
#include <type_traits> // for std::common_type_t (ch10s5)

using namespace std;

template <typename T>
T max11s8(T x, T y)
{
    return (x < y) ? y : x;
}

double max11s8(double x, double y) 
{
    return (x < y) ? y : x;
}

// template <typename T, typename U> // using two template type param's, T and U
// T max11s8(T x, U y) // x can resolve to type T, and y to type U
// {
//     return (x < y) ? y : x; // though now we have a narrowing conversion problem here
//     // usual arithmetic conversion rules require a common type
//     // common type for int and double is double
//     // BUT the return type is T (int), so double 3.5 gets narrowing converted to int 3
//     // better to use auto return type (implemented below)
// }

template <typename T, typename U>
auto max11s8(T x, U y)
{
    return (x < y) ? y : x;
}

// if we need a func to be forward declared, have to be explicit about return type
//   use std::common_type_t (ch10s5)
// template <typename T, typename U>
// auto max11s8(T x, U y) -> std::common_type_t<T, U>; // returns common type of T and U

// abbreviated function template (C++20)
// auto max11s8(auto x, auto y)
// {
//     return (x < y) ? y : x;
// }

// overloaded function templates:
// Add two values with matching types
template <typename T>
auto add11s8(T x, T y)
{
    return x + y;
}
//
// // Add two values with non-matching types
// // As of C++20 we could also use auto add(auto x, auto y)
template <typename T, typename U>
auto add11s8(T x, U y)
{
    return x + y;
}
//
// // Add three values with any type
// // As of C++20 we could also use auto add(auto x, auto y, auto z)
template <typename T, typename U, typename V>
auto add11s8(T x, U y, V z)
{
    return x + y + z;
}

void ch11s8() {
    cout << "\n === Chapter 11 Section 8 - Function templates with multiple template types === \n\n";
    
    cout << "calling max11s8(int, double) will not work with T max11s8(T x, T y) - compiler error\n";
    // max11s8(1, 2.3); - error: no matching function for call to ‘max11s8(int, double)’
    cout << "compiler won't generate a function max<double>(double, double) then convert the int to a double because\n";
    cout << "  type conversion is done only when resolving overloads, not for template argument deduction\n";

    cout << "\nyou can fix this with static_cast\n";
    cout << "max11s8(static_cast<double>(1, 2.3)) works: " << max11s8(static_cast<double>(1), 2.3) << '\n';

    cout << "\ncan provide an explicit type template arg like double max11s8(double x, double y)\n";
    cout << "  now max11s8(1, 2.3) works: " << max11s8(1, 2.3) << '\n';
    cout << "or can avoid template argument deduction by specifying an explicit type\n";
    cout << "  max11s8<double>(1, 2.3) works: " << max11s8<double>(1, 2.3) << '\n';

    cout << "\nfunction templates with multiple type param's\n";
    cout << "define multiple template types so we don't have to think about types when calling max()\n";

    cout << "\nabbreviated function templates (C++20)\n";
    cout << " (i am using C++17 as of this writing)\n";
    cout << "C++20 introduces a new use of the auto keyword: abbreviated function template\n";
    cout << "when auto keyword is used as a parameter type in a normal func, the compiler automatically\n";
    cout << "  converts the func into a func template with each auto param becoming an independent template type parameter\n";
    cout << "this form is preferred when wanting each template type param to be independent type\n";
    cout << "but, no easy way to use abbreviated function templates and make multiple auto param's the same type\n";

    cout << "\nfunction templates may be overloaded\n";
    cout << "add11s8(1.2, 3.4) is: " << add11s8(1.2, 3.4) << '\n'; // instantiates and calls add<double>()
    cout << "add11s8(5.6, 7) is: " << add11s8(5.6, 7) << '\n';   // instantiates and calls add<double, int>()
    cout << "add11s8(8, 9, 10) is: " << add11s8(8, 9, 10) << '\n'; // instantiates and calls add<int, int, int>()
    cout << "note for add(1.2, 3.4), compiler prefers add<T>(T, T) over add<T, U>(T, U)\n";
    cout << "partial ordering of function templates = rules for determining which matching func template is preferred\n";
    cout << "  basically, the more restrictive/specialized will be preferred\n";
    cout << "  if multiple func templates match and compiler can't determine which is more restrictive, compiler error - ambiguous match\n";
}

// template <typename T, typename U>
// auto max11s8(T x, U y) -> std::common_type_t<T, U>
// {
//     return (x < y) ? y : x;
// }
// 
// above is shorthand in C++20 for:
// template <typename T, typename U>
// auto max(T x, U y)
// {
//     return (x < y) ? y : x;
// }