#include "ch11s2.h"
#include <iostream>

int addCh11s2(int x, int y) {
    return x+y;
}

int addCh11s2(int x, int y, int z) {
    return x+y+z;
}

double addCh11s2(double x, double y) {
    return x+y;
}

double addCh11s2(int x, double y) {
    return x+y;
}

double addCh11s2(double x, int y) {
    return x+y;
}

// typedef int Height; // typedef
// using Age = int; // type alias

// void print(int value);
// void print(Age value); // not differentiated from print(int)
// void print(Height value); // not differentiated from print(int)

// void print(int);
// void print(const int); // not differentiated from print(int)

void ch11s2() {
    using namespace std;
    cout << "\n === Chapter 11 Section 2 - Func Overloading Differentiation === \n\n";

    cout << "can overload based on number of params, type of params\n";
    cout << "  ellipsis are considered to be a unique type of param.\n";
    cout << "  type aliases, typedefs, and const qualifiers are not considered\n";
    cout << "  return type is also not considered\n";

}