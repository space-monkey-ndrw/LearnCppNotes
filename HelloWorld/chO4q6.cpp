#include "chO4q6.h"
#include <iostream>
#include <cstdint>

void chO4q6()
{
	std::cout << "Enter a number between 0 and 255: ";
	int number{};
	std::cin >> number;
	std::uint8_t bitValue{ static_cast<std::uint8_t>(number) };

	std::cout << number << " as an 8bit unsigned int: ";

	for (int i = 7; i >= 0; --i) {
		if ((bitValue >> i) & 1) std::cout << '1';
		else std::cout << '0';
		if ((i % 4) == 0) std::cout << ' ';
	}
	std::cout << '\n';
}

void chO4q6givenSolution()
{
	std::cout << "Enter int 0 to 255: ";
	int x{};
	std::cin >> x;

	std::cout << x << " in binary is: ";
	std::cout << ((x / 128) % 2);
	std::cout << ((x / 64) % 2);
	std::cout << ((x / 32) % 2);
	std::cout << ((x / 16) % 2);
	std::cout << ' ';
	std::cout << ((x / 8) % 2);
	std::cout << ((x / 4) % 2);
	std::cout << ((x / 2) % 2);
	std::cout << ((x / 1) % 2);
}

