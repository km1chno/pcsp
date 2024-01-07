#pragma once

#include "bool_function.hpp"
#include <stdint.h>

/**
 * Draws a line plot of P_p(f): [0, 1] -> [0, 1] function for given boolean
 * function f defines as P_p(f)(p) = E[f(x)] where x \in {0, 1}^n and x_i = 1
 * with probability p for each i.
 *
 * @complexity O(step * precision)
 * @param f The boolean function.
 * @param step The x-axis step.
 * @param precision How many samples for each x should be taken.
 */
void draw_ppf(const bool_function &f, double step, uint32_t precision);
