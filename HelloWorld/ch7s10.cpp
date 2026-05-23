#include "ch7s10.h"
#include <iostream>

void ch7s10() {
    std::cout << "namespace ch7s10constants in ch7s10.h has avogadro and marsGravity.\n";
    std::cout << "  avogadro: " << ch7s10constants::avogadro << " and marsGravity: " << ch7s10constants::marsGravity << "g.\n";
    std::cout << "  these are inline in ch7s10.h, so only instantiated once and shared across files.\n";
}