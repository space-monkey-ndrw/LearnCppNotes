#include "ch11s3.h"
#include <iostream>

void printCh11s3(int x)
{
     std::cout << x << '\n';
}

void printCh11s3(double d)
{
     std::cout << d << '\n';
}

void fooCh11s3(int)
{
}

// void fooCh11s3(const int&) // int& is a reference to a int
// {
// }

void fooCh11s3(double)
{
}

void fooCh11s3(std::string)
{
}

class Y // this defines a new type called Y
{
public:
    operator int() { return 0; } // Here's a user-defined conversion from Y to int
};

void gooCh11s3(char, int)
{
	std::cout << 'a' << '\n';
}

void gooCh11s3(char, double)
{
	std::cout << 'b' << '\n';
}

void gooCh11s3(char, float)
{
	std::cout << 'c' << '\n';
}

void ch11s3() {
    using namespace std;
    cout << "\n === Chapter 11 Section 3 - Func Overloading Resolution, Ambiguous Matches === \n\n";

    cout << "overloaded function printCh11s3() - what happens with printCh11s3('a') and printCh11s3(5L)?\n";
    cout << "printCh11s3('a') is: ";
    printCh11s3('a');
    cout << "printCh11s3(5L) is: error, ambiguous match\n";
    // printCh11s3(5L);

    cout << "steps to resolution: \n";
    cout << " 1. compiler looks for exact match (args in func call exactly match type of params in overloaded func's, then tries trivial conversions)\n";
    cout << "    trivial conversions are lvalue to rvalue, qualification, non-ref to ref\n";
    cout << "    matches made via trivial conversions are exact matches, can result in ambiguous matches\n";
    cout << "int x {1}; and then foo(x); gives ambiguous match\n";
    int x {1};
    // foo(x);
    cout << " 2. then compiler tries to match with numeric promotions\n";
    fooCh11s3('a');  // promoted to match foo(int)
    fooCh11s3(true); // promoted to match foo(int)
    fooCh11s3(4.5f); // promoted to match foo(double)
    cout << " 3. then tries numeric conversions\n";
    fooCh11s3('a'); // 'a' promoted to match foo(int)
    fooCh11s3('a'); // if fooCh11s3(int) didn't exist, 'a' would be converted to match foo(double)
    cout << " 4. then compiler tries user-defined conversions\n";
    Y y; // Here, we're creating an object of type Y (named y)
    fooCh11s3(y); // y is converted to type int using the user-defined conversion from Y to int
    cout << " 5. then compiler tries looking for a matching function that uses ellipsis\n";
    cout << " 6. then compiler gives up and gives a compiler error about no matching functions\n\n";

    cout << "Ambiguous matches: with foo(int){} and foo(double){}, foo(5L) will be ambiguous match to both (through numeric conversion - long to int, and long to double)\n";
    cout << "also: with foo(unsigned int){} and foo(float){}, foo(0) and foo(3.141) will both ambiguous match to both (through numeric conversion - int to unsigned int or float, and double to float or unsigned int)\n";

    cout << "Resolving ambiguous matches: \n";
    cout << "  1. often the best way is to define a new overload that's an exact match\n";
    cout << "  2. can also explicitly cast an arg to match a func. param.\n\n";

    cout << "matching for functions with multiple arguments\n";
    cout << "  compiler applies matching rules to each argument in turn\n";
    cout << "  chosen function has each argument matching at least as well as all other overloads, and at least one argument matching better than all other overloads\n";
    gooCh11s3('x', 'a');
    cout << "  gooCh11s3('x', 'a') - all overloads match first arg exactly, but top overload matches second parameter via promotion, whereas others match via conversion\n";
    cout << "    so gooCh11s3(char, int) is unambiguously the best match\n";
}