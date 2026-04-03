#include "ch7s3.h"
#include <iostream>

void ch7s3() {
	int smaller{};
	int larger{};

	std::cout << "Enter an int: ";
	std::cin >> smaller;
	std::cout << "Enter a larger int: ";
	std::cin >> larger;

	if (larger < smaller)
	{
		std::cout << "Swapping the values\n";
		int temp{ smaller };
		smaller = larger;
		larger = temp;
	} // temp dies here

	std::cout << "The smaller value is " << smaller << '\n';
	std::cout << "The larger value is " << larger << '\n';
} // smaller and larger die here