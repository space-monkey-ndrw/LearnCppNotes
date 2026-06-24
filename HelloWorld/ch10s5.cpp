#include <iostream>
#include <typeinfo> // for typeid()
#include <cxxabi.h> // for demangling type names (i, d...) into strings (int, double...)
#include "ch10s5.h"

using namespace std;

void ch10s5() {
    cout << "\n === Chapter 10, Section 5: Arithmetic Conversions === \n\n";

    int i {2};
    int status;
    char* realName = abi::__cxa_demangle(typeid(i).name(), 0, 0, &status);
    cout << "name of the type for int i: \t" << realName << '\n'; // show us the name of the type for i

    double d {3.5};
    cout << "name of the type for double d: \t" << typeid(d).name() << '\n';

    cout << "name of the type for i+d: \t" << typeid(i+d).name() << ' ' << i+d << '\n';

    short a{ 4 };
    short b{ 5 };
    cout << "name of the type for shorts a+b: \t" << typeid(a + b).name() << ' ' << a + b << '\n'; // show us the type of a + b
    cout << "short is not in priority list, so both get integral promoted to int\n";

    realName = abi::__cxa_demangle(typeid(5u-10).name(), 0, 0, &status);
    cout << realName << ' ' << 5u - 10 << '\n'; // 5u means treat 5 as an unsigned integer
    // by default this prints typename j, which is unsigned int

    cout << "-3 < 5u is: \t" << boolalpha << (-3 < 5u) << '\n'; // -3 gets converted to an unsigned int, and overflows to a large number
    
    using commonType = common_type_t<int,double>;
    cout << "common type of <int, double> is: \t" << typeid(commonType).name() << '\n';
}