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

  // Drawing graphs demo.
  typedef std::shared_ptr<matplot::axes_type> tile_t;
  // bool_function g = common_functions::maj(11);
  // bool_function g = common_functions::proj(11, 0);
  bool_function g = common_functions::thr(11, 7);
  draw_tiled_layout_plot(2, 2,
                         {[=](tile_t t) { plot_epf(t, g, 0.01); },
                          [=](tile_t t) {
                            plot_d_epf(t, g, 0.01, {0.4, 0.5});
                          },
                          [=](tile_t t) {
                            plot_total_influence(t, g, 0.01, {0.4, 0.5});
                          }});
}
