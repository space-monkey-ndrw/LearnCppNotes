#include "ch12summaryQuiz.h"
#include <iostream>
#include <algorithm> // for std::swap()

void sort2(int& lesser, int& greater) {
	/* 
	if (lesser > greater) {
		std::swap(lesser, greater);
	}
	*/

	/* if writing our own swap, could do: */
	if (lesser > greater) { 
		int swap { greater };
	 	greater = lesser;
		lesser = swap;
	}
}

void ch12summaryQuiz()
{
    int x { 7 };
	int y { 5 };

	std::cout << x << ' ' << y << '\n'; // should print 7 5

	sort2(x, y); // make sure sort works when values need to be swapped
    std::cout << x << ' ' << y << '\n'; // should print 5 7

    sort2(x, y); // make sure sort works when values don't need to be swapped
	// since values were already swapped, x should be 5 and y should be 7
    std::cout << x << ' ' << y << '\n'; // should print 5 7
}