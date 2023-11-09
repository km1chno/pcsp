#ifndef POLY_H
#define POLY_H

#include <map>
#include <vector>
#include "math.hpp"

struct BinPol {
  int n; // arity
  std::vector<int> f;

  BinPol(int _n, std::map<int, int> _f) {
    this->n = _n;
    f.assign((1<<_n), 0);
    for (int x = 0; x < (1<<_n); x++)
      f[x] = _f[x];
  }

  /** Returns vertor of coorditanes shapley value. */
  std::vector<double> shapley() {
    std::vector<std::vector<double>> mu(n, std::vector<double>(n+1, 0));
    for (int s = 0; s < (1<<n); s++) {
      for (int j = 0; j < n; j++) {
        if (!f[s] && f[s|(1<<j)]) {
          mu[j][__builtin_popcount(s)]++;
          std::cout << "going from " << s << " to " << (s|(1<<j)) << "\n";
        }
      }
    }
    for (int i = 0; i < n; i++) 
      for (int k = 0; k <= n; k++)
        mu[i][k] /= choose(n, k);
    
    std::vector<double> phi(n);

    for (int i = 0; i < n; i++) {
      for (int k = 0; k <= n; k++) phi[i] += mu[i][k];
      phi[i] /= (double)n;
    }

    return phi;
  }
};

#endif
