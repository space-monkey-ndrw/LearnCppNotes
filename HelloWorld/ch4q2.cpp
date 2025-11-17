#include "ch4q2.h"
#include <iostream>

double getDouble()
{
	double d1{};
	std::cout << "Enter a double: ";
	std::cin >> d1;
	return d1;
}

char getOperator()
{
	std::cout << "Enter +, -, *, or /: ";
	char c1{};
	std::cin >> c1;
	return c1;
}

void printResult(double d1, double d2, char c1)
{
	double result{};

	if (c1 == '*')
		result = d1 * d2;
	else if (c1 == '/')
		result = d1 / d2;
	else if (c1 == '+')
		result = d1 + d2;
	else if (c1 == '-')
		result = d1 - d2;
	else
	{
		std::cout << "Invalid operator\n";
		return;
	}

	std::cout << d1 << " " << c1 << " " << d2 << " is " << result << '\n';
}

void ch4q2()
{
	double x{ getDouble() };
	double y{ getDouble() };

	char operation{ getOperator() };

	printResult(x, y, operation);
}