#include <iostream>

int getInteger()
{
	std::cout << "Enter int: ";
	int x{};
	std::cin >> x;

	return x;
}