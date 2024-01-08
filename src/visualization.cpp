#include "bool_function.hpp"
#include "epf.hpp"
#include "influence.hpp"
#include <boost/dynamic_bitset/dynamic_bitset.hpp>
#include <boost/random.hpp>
#include <matplot/core/axes_type.h>
#include <matplot/freestanding/axes_functions.h>
#include <matplot/matplot.h>
#include <matplot/util/common.h>

/**
 * Generic function for composing many subplots in tiled layout.
 *
 * @param plot_functions Sequence of functions plotting their graphs.
 */
void draw_tiled_layout_plot(
    int rows, int cols,
    std::vector<std::function<void(std::shared_ptr<matplot::axes_type>)>>
        plot_functions) {
  matplot::tiledlayout(rows, cols);
  for (auto &f : plot_functions)
    f(matplot::nexttile());
  matplot::show();
}

/**
 * Plot epf function for given boolean function of arity n.
 *
 * @complexity O(2^n * n * 1/step)
 * @param tile Matplot tile on which the graph should be plotted.
 * @param f The boolean function.
 * @param step The x-axis step.
 */
void plot_epf(std::shared_ptr<matplot::axes_type> tile, const bool_function &f,
              double step) {
  std::vector<double> x = matplot::linspace(0, 1, 1.0 / step);
  std::vector<double> y =
      matplot::transform(x, [=](double p) -> double { return epf(f, p); });

  matplot::plot(tile, x, y);
  matplot::title("E_p(f)");
}

/**
 * Plot derivative of epf function for given boolean function of arity n.
 *
 * @complexity O(2^n * n * 1/step)
 * @param tile Matplot tile on which the graph should be plotted.
 * @param f The boolean function.
 * @param step The x-axis step.
 */
void plot_d_epf(std::shared_ptr<matplot::axes_type> tile,
                const bool_function &f, double step, std::vector<double> mark) {
  std::vector<double> x = matplot::linspace(0, 1, 1.0 / step);
  std::vector<double> y = matplot::transform(
      x, [=](double p) -> double { return d_epf_numerical(f, p); });

  matplot::plot(tile, x, y);
  matplot::title(tile, "d/dp E_p(f)");

  matplot::hold(matplot::on);
  for (auto &mx : mark) {
    double my = d_epf_numerical(f, mx);
    matplot::text(mx, my,
                  "d/dp E_p(f)(" + std::to_string(mx) +
                      ") = " + std::to_string(my));
    matplot::plot(tile, {mx}, {my}, "--xr");
  }
  matplot::hold(matplot::off);
}

/**
 * Plot total influence for bias for given boolean function f of arity n.
 *
 * @complexity O(2^n * n * 1/step)
 * @param f The boolean function.
 * @param step The x-axis step.
 * @param mark Vector of marked x points on the graph. Can be empty.
 */
void plot_total_influence(std::shared_ptr<matplot::axes_type> tile,
                          const bool_function &f, double step,
                          std::vector<double> mark) {
  std::vector<double> x = matplot::linspace(0, 1, 1.0 / step);
  std::vector<double> y = matplot::transform(
      x, [=](double p) -> double { return total_influence(f, p); });

  matplot::plot(tile, x, y);
  matplot::title(tile, "Total Influence");

  matplot::hold(matplot::on);
  for (auto &mx : mark) {
    double my = total_influence(f, mx);
    matplot::text(mx, my,
                  "Inf(" + std::to_string(mx) + ") = " + std::to_string(my));
    matplot::plot(tile, {mx}, {my}, "--xr");
  }
  matplot::hold(matplot::off);
}
