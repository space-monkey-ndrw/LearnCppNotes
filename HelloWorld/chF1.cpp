#include "chF1.h"
#include <iostream>

using namespace std;

constexpr double calcCircumference(double radius)
{
    constexpr double pi { 3.14159265359 };
    return 2.0 * pi * radius;
}

constexpr int greaterF1(int x, int y)
{
    return (x > y ? x : y);
}

void chF1()
{
    cout << "\n === Chapter F Section 1 - Constexpr functions === \n\n";

    constexpr double circumference { calcCircumference(3.0) };
    cout << "circle has circumference: " << circumference << '\n';
    cout << "calcCircumference() must be evaluated at compile, since it's used in the initialize for constexpr circumference\n";
    cout << "compiler replaces the calcCircumference(3.0) with its returned value of 18.8496\n";
    
    int x {5};
    int y {6};
    cout << "constexpr func's can also eval. at runtime: " << greaterF1(x, y) << " is greater\n";
}