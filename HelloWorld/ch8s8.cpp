#include "ch8s8.h"
#include <iostream>

void ch8s8q2() {
	char counter{ 'a' };
	while (counter <= 'z') {
		std::cout << counter << ' ' << static_cast<int>(counter) << ' ';
		++counter;
	}
	std::cout << '\n' << '\n';
}

void ch8s8q3() {
	int outer{ 5 };
	while (outer >= 1) {
		int inner{ outer };
		while (inner >= 1) {
			std::cout << inner-- << ' ';
		}
		std::cout << '\n';
		outer--;
	}
}

void ch8s8q4() {
	int outer{ 1 };
	while (outer <= 5) {
		int inner{ 5 };
		while (inner >= 1) {
			if (inner > outer) std::cout << "  ";
			else std::cout << inner << ' ';
			inner--;
		}
		std::cout << '\n';
		outer++;
	}
}