#include "ch11s6.h"
#include <iostream>

using namespace std;

template <typename T> // this is the template parameter declaration defining T as a type template parameter
T max11s6 (T x, T y) // this is the function template definition for max<T>
{
    return (x < y) ? y : x;
}

void ch11s6() {
    cout << "\n === Chapter 11 Section 6 - Function Templates === \n\n";
    
    cout << "calling max11s6(1,2) with ints is: " << max11s6(1,2) << '\n';
    cout << "calling max11s6(1.0,2.1) with doubles is: " << max11s6(1.0,2.1) << '\n';
    
    cout << "\nfunction template = a function-like def'n used to generate functions\n";
    cout << "primary template = the actual function template\n";
    cout << "instantiated functions = the func's generated from the primary template\n";

    cout << "placeholder types = type template param's = template types = the param /return types or types used in the func body, to be specified later, by user of template\n";
    cout << "template parameter declaration = def's the template param's that will be used\n";

    cout << "\ntemplate param's are typically named with T, a placeholder\n";
    cout << "can also use something like TAllocator, or just Allocator\n";
}