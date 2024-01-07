#pragma once

#include "bool_function.hpp"
#include <vector>

/**
 * Returns vector of shapley values of functions coordinates.
 *
 * @complexity O(2^n * n)
 * @param f Boolean function {0, 1}^n -> {0, 1}.
 * @return Vector of length n of coordinates shapley values.
 */
std::vector<double> shapley(const bool_function &f);
