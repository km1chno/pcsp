#include "bool_function.hpp"
#include "boost/math/special_functions/binomial.hpp"
#include <vector>

/**
 * Returns vector of shapley values of functions coordinates.
 *
 * @complexity O(2^n * n)
 * @param f Boolean function {0, 1}^n -> {0, 1}.
 * @return Vector of length n of coordinates shapley values.
 */
std::vector<double> shapley(const bool_function &f) {
  int n = f.arity;
  std::vector<std::vector<double>> mu(n, std::vector<double>(n + 1, 0));

  for (int s = 0; s < (1 << n); s++)
    for (int j = 0; j < n; j++)
      if (!f(s) && f(s | (1 << j)))
        mu[j][__builtin_popcount(s)]++;

  for (int i = 0; i < n; i++)
    for (int k = 0; k <= n; k++)
      mu[i][k] /= boost::math::binomial_coefficient<double>(n, k);

  std::vector<double> phi(n);

  for (int i = 0; i < n; i++) {
    for (int k = 0; k <= n; k++)
      phi[i] += mu[i][k];
    phi[i] /= (double)n;
  }

  return phi;
}
