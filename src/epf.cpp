#include "bool_function.hpp"
#include <differentiation.hpp>

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
double epf(const bool_function &f, double p) {
  uint32_t n = f.arity;
  double y = 0;

  double q = 1.0 - p;
  std::vector<double> pow_p(n + 1, 1);
  for (int i = 1; i <= n; i++)
    pow_p[i] = pow_p[i - 1] * p;
  std::vector<double> pow_q(n + 1, 1);
  for (int i = 1; i <= n; i++)
    pow_q[i] = pow_q[i - 1] * q;

  for (uint32_t S = 0; S < (1 << n); S++) {
    uint32_t k = __builtin_popcount(S);
    if (f(S))
      y += pow_p[k] * pow_q[n - k];
  }

  return y;
}

/**
 * Returns approximate value of e_p(f) derivative for boolean function f in
 * point p.
 *
 * @complexity O(2^n * n)
 * @param f Boolean function {0, 1}^n -> {0, 1}.
 * @param p The point in which epf derivative functions shall be evaluated.
 * @return d/dp e_p(f) in point p.
 */
double d_epf_numerical(const bool_function &f, double p) {
  auto epf_lambda = [=](double x) -> double { return epf(f, x); };
  return numcalc::diff<numcalc::f_x>(epf_lambda, p);
}
