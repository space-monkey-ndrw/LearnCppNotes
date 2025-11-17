#include <iostream>
#include "ch4q3.h"

void printHeight(double height, int time)
{
	double resultHeight{ height - (9.8 * (time * time) / 2.0) };
	if (resultHeight < 0.0)
		std::cout << "At " << time << " seconds, the ball is on the ground.\n";
	else
		std::cout << "At " << time << " seconds, the ball is at height: " << resultHeight << " meters\n";
}

void ch4q3()
{
	std::cout << "Enter the height of the tower in meters: ";
	double height{};
	std::cin >> height;
	printHeight(height, 0);
	printHeight(height, 1);
	printHeight(height, 2);
	printHeight(height, 3);
	printHeight(height, 4);
	printHeight(height, 5);
}