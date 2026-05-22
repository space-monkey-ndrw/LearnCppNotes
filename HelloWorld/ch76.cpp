#include <iostream>

[[maybe_unused]] constexpr int g_x76{ 59 }; // internal linkage, only visible in this translation unit (source file)
void printGx76()
{
    std::cout << "g_x76 from ch76.cpp is: " << g_x76 << '\n';
}

static int add76(int x, int y)
{
    return x + y;
}

int publicadd76(int x, int y)
{
    return add76(x, y);
}