#ifndef MATH_H
#define MATH_H
#include <vector>

std::vector<std::vector<double>> _choose(21, std::vector<double>(21, 0));

inline double choose(int n, int k) {
  return _choose[n][k];
}

void preprocess() {
  _choose[0][0] = 1;
  for (int n = 1; n <= 20; n++) {
    _choose[n][0] = 1;
    for (int k = 1; k <= 20; k++) 
      _choose[n][k] = _choose[n-1][k-1] + _choose[n-1][k];
  }
}

#endif
