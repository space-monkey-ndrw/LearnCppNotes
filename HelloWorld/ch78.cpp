#include <iostream>

// forward declarations
int initX();
int initY();

int g_x78{ initX() };
int g_y78{ initY() };

int initX()
{
    return g_y78;
}

int initY()
{
    return 5;
}

int ch78()
{
    std::cout << "g_x78 is: " << g_x78 << '\n';
    std::cout << "g_y78 is: " << g_y78 << '\n';
    std::cout << "prints 0 5 because g_x78 is initialized first, and g_y78 isn't initialized when initX() is called\n";
    std::cout << "static initialization order fiasco: order of objects with static storage duration in different\n";
    std::cout << "translation units is ambiguous\n";
    
    return 0;
}

