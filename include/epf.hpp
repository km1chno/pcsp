#include "bool_function.hpp"

/**
 * Returns value of e_p(f) function for boolean function f in point p.
 * For f: {0, 1}^n -> {0, 1}, the epf: [0, 1] -> [0, 1] function is defined as:
 *
 * e_p(f) = E[f(x)] if Pr(x_i = 1) = p for all i \in [n] independently.
 *
 * @complexity O(2^n * n)
 * @param f Boolean function {0, 1}^n -> {0, 1}.
 * @param p The point in which epf functions shall be evaluated.
 * @return e_p(f).
 */
double epf(const bool_function &f, double p);

/**
 * Returns approximate value of e_p(f) derivative for boolean function f in
 * point p.
 *
 * @complexity O(2^n * n)
 * @param f Boolean function {0, 1}^n -> {0, 1}.
 * @param p The point in which epf derivative functions shall be evaluated.
 * @return d/dp e_p(f) in point p.
 */
double d_epf_numerical(const bool_function &f, double p);
