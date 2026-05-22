#include <iostream>

inline double pi() { return 3.14159; }

void ch7s9() {
    std::cout << "Modern usage of the inline keyword means 'multiple definitions allowed'.\n";
    std::cout << "  meaning it can be defined in multiple translation units, as long as:\n";
    std::cout << "  1. compiler has full definition in each T.U., and\n";
    std::cout << "  2. every definition needs to be identical.\n";
    std::cout << "The linker will consolidate all inline function definitions into one definition,\n";
    std::cout << "  so that there's no O.D.R. violations.\n";
    std::cout << "Example: inline double pi() { return 3.14159; }\n";
    std::cout << "  could be in main.cpp and ch79.cpp, and the linker will de-dupe them.\n";
    std::cout << "Inline functions are usually defined in header files, which makes them useful header-only libraries.\n";
    std::cout << "  we also put inline pi() in ch79.h, NOT included in ch79.cpp or main.cpp because only 1 definition allowed per T.U. and we already put one definition in main.cpp and ch79.cpp\n";

    std::cout << "calling pi() from ch79.cpp prints: " << pi() << '\n';
}