#pragma once
#ifndef CH10S7_H
#define CH10S7_H
#include <iostream>
#include <cstdint>
using Mhz = double;
void ch10s7();

// #ifdef INT_2_BYTES
// using int8_t = char;
// using int16_t = int;
// using int32_t = long;
// #else
// using int8_t = char;
// using int16_t = short;
// using int32_t = int;
// #endif

#include <string> // for std::string
#include <vector> // for std::vector
#include <utility> // for std::pair

using VectPairSI = std::vector<std::pair<std::string, int>>;
bool hasDuplicates(VectPairSI pairlist);

void ch10s7quiz();
#endif