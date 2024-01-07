#pragma once

#include <functional>
#include <stdint.h>
#include <vector>

/**
 * Returns vector of shapley values of functions coordinates.
 *
 * @complexity O(2^n * n)
 * @param f Boolean function {0, 1}^n -> {0, 1}.
 * @param n Functions arity.
 * @return Vector of length n of coordinates shapley values.
 */
std::vector<double> shapley(std::function<bool(uint32_t)> f, uint32_t n);
