#include "ch11s5.h"
#include <iostream>

using namespace std;

void printCh11s5(int x, int y=9) // 9 is the default arg
{
    cout << "x: " << x << "\ny: " << y << '\n';
}

// void goo (int x (5)); // compiler error
// void boo (int x {5}); // compiler error

void ch11s5() {
    
    cout << "\n === Chapter 11 Section 5 - Default Arg's === \n\n";
    
    cout << "printCh11s5(1,2) and y will use user-supplied arg of 2:\n";
    printCh11s5(1,2);
    cout << "printCh11s5(3) will use default arg y=9:\n";
    printCh11s5(3);
    cout << "\nmust use equals sign to specify default args, parenthesis or brace init. won't work (compiler error)\n";
    cout << "default args are handled by compiler at the call site.  printCh11s5(3) becomes printCh11s5(3,9)\n";
    cout << "default args are great when func needs a value that has a reasonable default, that can also be overridden\n";
    cout << "  - like a int rollDie(int sides=6) or void openLogFile(std::string filename=\"default.log\")\n";
    cout << "also useful when adding a new arg to a func (so you don't break all existing calls to the function)\n\n";

    cout << "can have multiple default args\n";
    cout << " - can't do something like print(,,3) to only override one arg\n";
    cout << " - this has 3 major consequences:\n";
    cout << "   1. explicitly provided args must be the leftmost args (args with defaults can't be skipped)\n";
    // print();           // okay: both arguments defaulted
    // print("Macaroni"); // okay: d defaults to 10.0
    // print(20.0);       // error: does not match above function (cannot skip argument for sv)
    cout << "   2. if a param is given a default arg, all subsequent params (to the right) must also have default arg's\n";
    // void print(int x=10, int y); // not allowed
    cout << "   3. if more than one param has default arg, leftmost param should be most likely to be overridden\n\n";
    cout << "default args cannot be redeclared, and must be declared before use\n";
    cout << " - meaning if a func has a fwd decl'n and a func def'n, default arg can be declared in either but not both\n";
    // void print(int x, int y=4); // forward declaration

    // void print(int x, int y=4) // compile error: redefinition of default argument
    // {
    //     std::cout << "x: " << x << '\n';
    //     std::cout << "y: " << y << '\n';
    // }
    cout << " - also means default arg must be decl'd in the translation unit before use\n";
    // void print(int x, int y); // forward declaration, no default argument

    // int main()
    // {
    //     print(3); // compile error: default argument for y hasn't been defined yet

    //     return 0;
    // }

    // void print(int x, int y=4)
    // {
    //     std::cout << "x: " << x << '\n';
    //     std::cout << "y: " << y << '\n';
    // }
    cout << " - best to declare default args in fwd decl'n and not func def'n (particularly if it's in a header file)\n";
    //   foo.h:
    // #ifndef FOO_H
    // #define FOO_H
    // void print(int x, int y=4);
    // #endif
    //   main.cpp:
    // void print(int x, int y)
    // {
    //     std::cout << "x: " << x << '\n';
    //     std::cout << "y: " << y << '\n';
    // }

    // int main()
    // {
    //     print(5);

    //     return 0;
    // }
    cout << "\nfunc's with default arg's may be overloaded\n";
    // #include <string_view>

    // void print(std::string_view s)
    // {
    //     std::cout << s << '\n';
    // }

    // void print(char c = ' ')
    // {
    //     std::cout << c << '\n';
    // }

    // int main()
    // {
    //     print("Hello, world"); // resolves to print(std::string_view)
    //     print('a');            // resolves to print(char)
    //     print();               // resolves to print(char)

    //     return 0;
    // }
    cout << "default val's are not part of func's signature, so these are differentiated overloads\n";
    // void print(int x);                  // signature print(int)
    // void print(int x, int y = 10);      // signature print(int, int)
    // void print(int x, double y = 20.5); // signature print(int, double)
    cout << "\ndefault args can lead to ambiguous matches\n";
    // void foo(int x = 0)
    // {
    // }

    // void foo(double d = 0.0)
    // {
    // }

    // int main()
    // {
    //     foo(); // ambiguous function call

    //     return 0;
    // }

    //   another example:
    // void print(int x);                  // signature print(int)
    // void print(int x, int y = 10);      // signature print(int, int)
    // void print(int x, double y = 20.5); // signature print(int, double)

    // int main()
    // {
    //     print(1, 2);   // will resolve to print(int, int)
    //     print(1, 2.5); // will resolve to print(int, double)
    //     print(1);      // ambiguous function call

    //     return 0;
    // }

    cout << "\ndefault args don't work for func's called through func pointers\n";
    // covered in 20.1
}