#include "chO2quiz.h"
#include <bitset>
#include <iostream>

// "rotl" is bitwise rotate left
std::bitset<4> rotl(std::bitset<4> bits)
{
	bool bit3set{ bits.test(3) };
	bits <<= 1;
	if (bit3set)
		bits.set(0);
	return bits;
}

std::bitset<4> rotl2(std::bitset<4> bits)
{
	return (bits << 1) | (bits >> 3);
}

