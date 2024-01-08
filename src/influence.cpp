#include "bool_function.hpp"
#include <numeric>

/**
 * Returns vector of p-biased influence values of functions coordinates.
 *
 * @complexity O(2^n * n)
 * @param f Boolean function {0, 1}^n -> {0, 1}.
 * @param p Bias parameter.
 * @return Vector of of length n of Inf^p_i(f)
 */
std::vector<double> influence(const bool_function &f, double p = 0.5) {
  uint32_t n = f.arity;
  std::vector<double> inf(n, 0);

  double q = 1.0 - p;
  std::vector<double> pow_p(n + 1, 1);
  for (int i = 1; i <= n; i++)
    pow_p[i] = pow_p[i - 1] * p;
  std::vector<double> pow_q(n + 1, 1);
  for (int i = 1; i <= n; i++)
    pow_q[i] = pow_q[i - 1] * q;

  for (uint32_t S = 0; S < (1 << n); S++) {
    uint32_t k = __builtin_popcount(S);
    for (int i = 0; i < n; i++)
      if (f(S | (1 << i)) != f(S & (~(1 << i))))
        inf[i] += 4 * pow_p[k] * pow_q[n - k];
  }

  for (int i = 0; i < n; i++)
    inf[i] *= p * q;

  return inf;
}

/**
 * Returns p-biased influence of boolean function.
 *
 * @complexity O(2^n * n)
 * @param f Boolean function {0, 1}^n -> {0, 1}.
 * @param p Bias parameter.
 * @return Inf^p(f)
 */
double total_influence(const bool_function &f, double p = 0.5) {
  std::vector<double> inf = influence(f, p);
  return std::reduce(inf.begin(), inf.end());
}
