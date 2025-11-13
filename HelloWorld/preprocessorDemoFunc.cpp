#include <iostream>

void doStuff()
{
#ifdef PRINT
	std::cout << "#ifdef PRINT\n";
#endif
#ifndef PRINT
	std::cout << "#ifndef PRINT - we did #define PRINT in HelloWorld.cpp, but becomes invalid at end of that code\n";
#endif
}