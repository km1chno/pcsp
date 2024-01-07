#include "shapley.hpp"
#include "visualization.hpp"

#include <map>
#include <vector>

int main() {
  // Shapley values demo.
  std::map<int, bool> f_vals = {{0b000, 0}, {0b001, 0}, {0b010, 0}, {0b011, 1},
                                {0b100, 0}, {0b101, 1}, {0b110, 1}, {0b111, 1}};

  auto f = [&](int x) { return f_vals[x]; };

  std::vector<double> phi = shapley(f, 3);

  // Ppf graph demo.
  draw_ppf(f, 3, 0.01, 100000);
}
