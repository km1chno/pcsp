#include "bool_function.hpp"
#include "common_functions.hpp"
#include "shapley.hpp"
#include "visualization.hpp"

#include <map>
#include <vector>

int main() {
  // Shapley values demo.
  std::map<int, bool> f_vals = {{0b000, 0}, {0b001, 0}, {0b010, 0}, {0b011, 1},
                                {0b100, 0}, {0b101, 1}, {0b110, 1}, {0b111, 1}};

  auto f = [&](int x) { return f_vals[x]; };

  bool_function F(f, 3);

  std::vector<double> phi = shapley(F);

  // Ppf graph demo.
  draw_ppf(common_functions::proj(28, 0), 0.01, 100000);
}
