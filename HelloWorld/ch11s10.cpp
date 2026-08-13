#include "ch11s10.h"
#include "ch11s10max.h"
#include <iostream>

using namespace std;

void ch11s10() {
    cout << "\n === Chapter 11 Section 10 - Using Func Templates in Mult Files === \n\n";
    
    cout << "put all template code in a header file instead of source file\n";
    cout << "foo11s10 is in .h file, calling with 1 gives: " << foo11s10(1) << '\n';
    cout << "  calling with (2.3) gives: " << foo11s10(2.3) << '\n';
    cout << "note: functions implicitly instantiated from templates are implicitly incline - can be def'd in mult files as long as def's are identical\n";
    
    cout << "\nanother ex: have max11s10() template in ch11s10max.h, included here\n";
    cout << "max11s10(3, 5) is: " << max11s10(3, 5) << '\n';
}