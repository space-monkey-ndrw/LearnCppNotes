#include "ch11s7.h"
#include <iostream>

using namespace std;

template <typename T>
T max11s7 (T x, T y)
{
    return (x < y) ? y : x;
}

template <typename T>
double someFcn11s7(T, double)
{
    return 5.1;
}

template <typename T>
T addOne11s7(T x)
{
    return x + 1;
}

template <typename T>
void print11s7(T val, int times=1)
{
    while (times--) {
        cout << val;
    }
    cout << '\n';
}

// function template specialization, with = delete, gives a compiler error on use for this func
template <>
const char* addOne11s7(const char* x) = delete;

template <typename T>
void printIDAndValue(T value) 
{
    static int id {0};
    cout << ++id << ") " << value << '\n';
}

void ch11s7() {
    cout << "\n === Chapter 11 Section 7 - Function Template Instantiation === \n\n";
    
    cout << "template argument = specifies the actual type to use instead of placeholder\n";

    cout << "\nmax11s7<int>(1,2) is: " << max11s7<int>(1,2) << '\n';

    cout << "\n(function template) instantiation = process of creating func's w/ specific types from function templates (with template types)\n";
    cout << "implicit instantiation = when a func is instantiated due to a func call\n";
    cout << "specialization = function instance = a func that is instantiated from a template\n";

    cout << "\nthe compiler clones the primary template and replaces template type T with the actual type we've specified\n";
    cout << "if you do something like max<double>(1,2), the int arg's are implicitly converted to double\n";

    cout << "\ntemplate argument deduction = compiler deduces type from arg's\n";
    cout << "max<>(1,2) and max(1,2) will both work for template arg deduction\n";
    cout << "note: normal function call syntax like max(1,2) will prefer a non-template func over an equally viable function instantiated from a template\n";
    // example: 
    // template <typename T>
    // T max(T x, T y)
    // {
    //     std::cout << "called max<int>(int, int)\n";
    //     return (x < y) ? y : x;
    // }
    //
    // int max(int x, int y)
    // {
    //     std::cout << "called max(int, int)\n";
    //     return (x < y) ? y : x;
    // }
    //
    // std::cout << max<int>(1, 2) << '\n'; // calls max<int>(int, int)
    // std::cout << max<>(1, 2) << '\n';    // deduces max<int>(int, int) (non-template functions not considered)
    // std::cout << max(1, 2) << '\n';      // calls max(int, int)

    // another example:
    // This function template can handle many types, so its implementation is generic
    // template <typename T>
    // void print(T x)
    // {
    //     std::cout << x; // print T however it normally prints
    // }
    //
    // This function only needs to consider how to print a bool, so it can specialize how it handles
    // printing of a bool
    // void print(bool x)
    // {
    //     std::cout << std::boolalpha << x; // print bool as true or false, not 1 or 0
    // }
    //
    // print<bool>(true); // calls print<bool>(bool) -- prints 1
    // print<>(true);     // deduces print<bool>(bool) (non-template functions not considered) -- prints 1
    // print(true);       // calls print(bool) -- prints true

    cout << "\nfunction templates with non-template param's\n";
    cout << "someFcn11s7(1, 3.4) matches someFcn11s7(int, double): " << someFcn11s7(1,3.4) << '\n';
    cout << "someFcn11s7(1, 3.4f) matches someFcn11s7(int, double) (float is promoted to double): " << someFcn11s7(1,3.4f) << '\n';
    cout << "someFcn11s7(1.2, 3.4) matches someFcn11s7(double, double): " << someFcn11s7(1.2,3.4) << '\n';
    cout << "someFcn11s7(1.2f, 3.4) matches someFcn11s7(float, double): " << someFcn11s7(1.2f, 3.4) << '\n';
    cout << "someFcn11s7(1.2f, 3.4f) matches someFcn11s7(int, double): " << someFcn11s7(1.2f, 3.4f) << '\n';

    cout << "\ninstantiated func's may not always compile\n";
    cout << "addOne11s7(1) works, addOne11s7(2.3) works\n";
    
    cout << "what about string hello {\"hello world\"}; and addOne11s7(hello) ?\n";
    string hello {"hello world"};
    // cout << addOne11s7(hello) << '\n';
    cout << "compiler error, since x+1 doesn't make sense when x is a std::string\n";

    cout << "\ninstantiated func's may not always make sense semantically\n";
    // cout << "addOne11s7(\"Hello Mars!\") gives: " << addOne11s7("Hello Mars!") << '\n';
    cout << "calling addOne11s7 on a C-style string literal - details in ch17s9\n";
    cout << "can disallow this with function template specialization\n";
    cout << "  lets us overload a func template for a specific set of args, along with = delete, which tells compiler that using this func should give a compilation error\n";
    // added function template specialization for const char*, and = delete, so now calling addOne11s7("Hello Mars!") gives compiler error

    cout << "\nfunc templates and default arg's for non-template param's\n";
    cout << "print(5) prints 5, 1 time\n";
    print11s7(5);
    cout << "print('a', 3) prints 'a', 3 times\n";
    print11s7('a', 3);

    cout << "\nbeware func templates with modifiable static local var's\n";
    printIDAndValue(12);
    printIDAndValue(13);
    printIDAndValue(14.5);
    cout << "call to printIDAndValue(14.5) starts with 1) and not 3) because 14.5 is a double which causes compiler to create a new func instance for double, which has its own static int id\n";
    // compiler actually compiles and executes something like this:
    // template <typename T>
    // void printIDAndValue(T value);
    //
    // template <>
    // void printIDAndValue<int>(int value)
    // {
    //     static int id{ 0 };
    //     std::cout << ++id << ") " << value << '\n';
    // }
    //
    // template <>
    // void printIDAndValue<double>(double value)
    // {
    //     static int id{ 0 };
    //     std::cout << ++id << ") " << value << '\n';
    // }

    cout << "\ngeneric programming\n";
    cout << "generic types = another name for template types\n";
    cout << "generic programming = programming with templates\n";

    cout << "\nfunction template drawbacks\n";
    cout << "1) compiler will create and compile a func for each func call with a unique set of type args\n";
    cout << "  this can lead to bloat and slow compilation (one template can become many funcs)\n";
    cout << "2) tends to produce hard to read error messages\n";
}