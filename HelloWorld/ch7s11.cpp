#include "ch7s11.h"
#include <iostream>

void incrementAndPrint() {
    static int s_value{1};
    ++s_value;
    std::cout << s_value << '\n';
}

void ch7s11() {
    std::cout << " Static Local Variables\n";
    std::cout << "  using static keyword on a local variable changes its duration from automatic to static.\n";
    std::cout << "  Static duration -> variable is created/destroyed at start/end of program\n";
    std::cout << "  this means it retains value, even when out of scope.\n";
    std::cout << "static int s_value is 1 w/ local scope to incrementAndPrint().\n";
    std::cout << "Calling incrementAndPrint() thrice.  If it weren't static it'd print 2 three times:\n";
    incrementAndPrint();
    incrementAndPrint();
    incrementAndPrint();
}