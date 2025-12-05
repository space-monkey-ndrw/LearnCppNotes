#include <iostream>
#include "ch5s7q1.h"
#include <string>

void ch5s7q1()
{
	std::cout << "Enter your full name: ";
	std::string name{};
	std::getline(std::cin >> std::ws, name);

	std::cout << "Enter your age: ";
	int age{};
	std::cin >> age;

	std::cout << "Length of name + your age = " << age + static_cast<int>(name.length()) << '\n';
}