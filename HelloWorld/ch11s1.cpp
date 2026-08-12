#include "ch11s1.h"
#include <iostream>

int addCh11s1(int x, int y) {
    return x+y;
}

double addCh11s1(double x, double y) {
    return x+y;
}

void ch11s1() {
    using namespace std;
    cout << "\n === Chapter 11 Section 1 - Intro to Func Overloading === \n\n";

    cout << "overloaded function addCh11s1().  Overload param's have type int and double\n";
    printf("addCh11s1(1,2) is %d and addCh11s1(3.4, 5.6) is %.1f\n", addCh11s1(1,2), addCh11s1(3.4, 5.6));
}