#include "ch5quiz.h"
#include <string>
#include <string_view>
#include <iostream>
#include <cstdint>
#include <limits>

std::string getName(int personNum)
{
	std::cout << "Enter the name of person #" << personNum << ": ";
	std::string name{};
	std::getline(std::cin >> std::ws, name);

	return name;
}

int getAge(std::string_view name)
{
	std::cout << "Enter the age of " << name << ": ";
	int age{};
	std::cin >> age;

	return age;
}

void printOlder(std::string_view name1, int age1, std::string_view name2, int age2)
{
	if (age1 > age2) {
		std::cout << name1 << " (age " << age1 << ") is older than " << name2 << " (age " << age2 << ").\n";
	}
	else {
		std::cout << name2 << " (age " << age2 << ") is older than " << name1 << " (age " << age1 << ").\n";
	}
}

void ch5quiz()
{
	const std::string name1{ getName(1) };
	const int age1{ getAge(name1) };

	const std::string name2{ getName(2) };
	const int age2{ getAge(name2) };

	printOlder(name1, age1, name2, age2);
}

void questionTwo()
{
	std::cout << "ch5quiz Q2: How old are you?\n";

	std::uint8_t age{};
	std::cin >> age;
	std::cout << "age entered: " << age << '\n';

	std::cout << "Allowed to drive a car in Texas: ";

	if (age >= 16)
		std::cout << "Yes";
	else
		std::cout << "No";

	std::cout << ".\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void q2fixed()
{
	std::cout << "ch5quiz Q2 (fixed): How old are you?\n";

	int age{};
	std::cin >> age;
	std::cout << "age entered: " << age << '\n';

	std::cout << "Allowed to drive a car in Texas: ";

	constexpr int minAge{ 16 };

	if (age >= minAge)
		std::cout << "Yes";
	else
		std::cout << "No";

	std::cout << '\n';
}