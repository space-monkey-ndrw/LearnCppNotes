#include "ch10s7.h"

void ch10s7() {
    using Distance = double;

    Distance milesToDestination {3.1};

    std::cout << "\nusing Distance = double, and Distance milesToDestination is: " << milesToDestination << '\n';

    using Miles = long;
    using Speed = long;
    Miles distance {5};
    Speed mph {3200};

    distance = mph;
    std::cout << "Miles and Speed are both aliases for type long\n";
    std::cout << "can do distance = mph, giving distance: " << distance << " and mph: " << mph << '\n';

    Mhz freq {5.5};
    std::cout << "using Mhz = double in header, so Mhz freq = " << freq << '\n';
    std::cout << "type aliases follow same scoping rules as variable identifiers\n";
    std::cout << "  block scope if defined in a block\n";
    std::cout << "  global scope if defined in global namespace\n";
    std::cout << "  #included type aliases from header are imported into global namespace\n";

    std::cout << "\ntypedef is an older way of creating type aliases.  Don't use them\n";
    typedef long Radians;
    using Radians = long;
    // these aliases are identical
    
    std::cout << "syntax for typedefs can get ugly with complex types\n";
    typedef int (*FcnType)(double, char);
    using FcnType = int(*)(double, char);

    std::cout << "type aliases are commmonly used for platform independent coding:\n";
    std::cout << "  see #ifdef INT_2_BYTES in header file\n";
    std::cout << "  this is why printing an 8-bit fixed width int using std::cout likely gives a char value\n";
    std::int8_t x {97}; // int8_t is usually a typedef for signed char
    std::cout << "int8_t x {97} prints as: " << x << '\n';

    std::cout << "type aliases useful for making complex types easier to read, like:\n";
    std::cout << "  using VectPairSI = std::vector<std::pair<std::string, int>>; (in header)\n";
    VectPairSI pairlist;
    std::cout << std::boolalpha;
    std::cout << "calling hasDuplicates(VectPairSI pairlist) gives: " << hasDuplicates(pairlist) << '\n';

    std::cout << "\ntype aliases are also useful for documenting meaning of a value\n";
    std::cout << "  like using TestScore = int;\n";
    std::cout << "  then TestScore gradeTest();\n";
    std::cout << "  it's clear that gradeTest returns a test score\n";

    ch10s7quiz();
}

bool hasDuplicates(VectPairSI pairlist) {
    return false;
}

void ch10s7quiz() {
    std::cout << "given a function prototype int printData(); change the return value to a type alias named PrintError (ans in .cpp code file)\n\n";
    // answer below
    // using PrintError = int;
    // PrintError printData();
}

