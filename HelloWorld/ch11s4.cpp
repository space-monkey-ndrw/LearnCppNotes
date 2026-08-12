#include "ch11s4.h"
#include <iostream>

using namespace std;

// this function takes precedence for args of type int
void printIntCh11s4(int x) {
    cout << x << '\n';
}

void printIntCh11s4(char) = delete; // calls to this function will stop compilation
void printIntCh11s4(bool) = delete; // calls to this function will stop compilation

// this function template takes precedence for args of other types (not int)
// calls to this function template will stop compilation
template <typename T>
void printIntCh11s4(T x) = delete;


void ch11s4() {
    
    cout << "\n === Chapter 11 Section 4 - Deleting Functions === \n\n";
    
    cout << "printIntCh11s4(97) works:";
    printIntCh11s4(97);
    cout << "\nprintIntCh11s4('a') will give compilation error\n";
    // printIntCh11s4('a');
    cout << "\nprintIntCh11s4(true) will give compilation error\n";
    // printIntCh11s4(true);
    cout << "\nprintIntCh11s4(5.0) will give compilation error - ambiguous match\n";
    // printIntCh11s4(5.0);
    cout << "  deleted func's are still considered - double can be converted to int, char, bool, so none is unambiguously the best match\n";
    cout << "  the function template eliminates the ambiguous match, still gives error since deleted\n";
    cout << "  note that the function template makes this an exact match for printIntCh11s4(T) [with T = double]\n";
}