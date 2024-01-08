#pragma once

#include "bool_function.hpp"

/**
 * Returns vector of p-biased influence values of functions coordinates.
 *
 * @complexity O(2^n * n)
 * @param f Boolean function {0, 1}^n -> {0, 1}.
 * @param p Bias parameter.
 * @return Vector of of length n of Inf^p_i(f)
 */
std::vector<double> influence(const bool_function &f, double p = 0.5);

/**
 * Returns p-biased influence of boolean function.
 *
 * @complexity O(2^n * n)
 * @param f Boolean function {0, 1}^n -> {0, 1}.
 * @param p Bias parameter.
 * @return Inf^p(f)
 */
double total_influence(const bool_function &f, double p = 0.5);
