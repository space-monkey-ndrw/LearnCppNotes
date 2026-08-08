#include "ch10s9.h"
#include <iostream>

auto fooCh10s9(bool b) {
    if (b) return 5.1; // all returns must use values of the same type (here, double)
    else return 6.0;   //   otherwise we get an error
}

auto addCh10s9(unsigned short x, char y) {
    return x+y;
}

auto add2ch10s9(int x, int y) -> int {
    return (x+y);
}

void ch10s9() {
    using namespace std;
    cout << "\n === Chapter 10 Section 9 - Type Deduction for Func's === \n\n";

    cout << "return type deduction with auto keyword\n";
    cout << " - all returns must use same type, or error (see fooCh10s9())\n";
    cout << "   fooCh10s9(true) is: " << fooCh10s9(true) << "\n\n";

    cout << "benefits:\n";
    cout << " - negates risk of unintentional conversions from mis-matched return types\n";
    cout << " - simplifies long / complex / non-obvious return types (see addCh10s9())\n";
    cout << "   addCh10s9(static_cast<unsigned short>(4), 'y') is: " << addCh10s9(static_cast<unsigned short>(4), 'y') << "\n\n";

    cout << "downsides:\n";
    cout << " 1. functions with auto return type must be fully defined before use (fwd decl'n not sufficient)\n";
    cout << " 2. less clear what type will be returned from a function's prototype\n\n";

    cout << "trailing return type syntax\n";
    cout << " use auto keyword then -> then specify return type (see add2ch10s9)\n";
    cout << " 1. easier to read when func has complex return type\n";
    cout << "    std::common_type_t<int, double> compare(int, double); // harder to read (where is the name of the function in this mess?)\n  auto compare(int, double) -> std::common_type_t<int, double>; // easier to read (we don't have to read the return type unless we care)\n";
    cout << " 2. aligns names of functions when declaring multiple functions, easier to read\n";
    cout << "    auto add(int x, int y) -> int;\n  auto divide(double x, double y) -> double;\n  auto printSomething() -> void;\n  auto generateSubstring(const std::string &s, int start, int len) -> std::string;\n";
    cout << " 3. needed if func's return type must be deduced from type of param's\n";
    cout << " 4. required for some advanced C++ features (like lambdas)\n\n";

    cout << "type deduction can't be used for func. param. types\n";
    cout << "  bad: void addAndPrint(auto x, auto y) - gives error\n";
}