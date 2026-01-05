#pragma once
#ifndef INTEXP_H
#define INTEXP_H
#include <cstdint> // for std::int64_t
const std::int64_t powint(std::int64_t base, int exp);
const std::int64_t powint_safe(std::int64_t base, int exp);
#endif