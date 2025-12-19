#include "ch6s3q2.h"
#include <iostream>

constexpr bool isEven(int x)
{
	return (x % 2) == 0;
}

void ch6s3q2()
{
	std::cout << "Enter an int: ";
	int x{};
	std::cin >> x;

	if (isEven(x))
		std::cout << x << " is even\n";
	else
		std::cout << x << " is odd\n";
}