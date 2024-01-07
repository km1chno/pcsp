#include "bool_function.hpp"
#include "random.hpp"
#include <boost/dynamic_bitset/dynamic_bitset.hpp>
#include <boost/random.hpp>
#include <matplot/matplot.h>
#include <matplot/util/common.h>
#include <stdint.h>

/**
 * Draws a line plot of P_p(f): [0, 1] -> [0, 1] function for given boolean
 * function f defines as P_p(f)(p) = E[f(x)] where x \in {0, 1}^n and x_i = 1
 * with probability p for each i.
 *
 * @complexity O(step * precision)
 * @param f The boolean function.
 * @param step The x-axis step.
 * @param precision How many samples for each x should be taken.
 */
void draw_ppf(const bool_function &f, double step, uint32_t precision) {
  std::vector<double> x = matplot::linspace(0, 1, 1.0 / step);

  auto eval_ppf = [&](double p) -> double {
    double val = 0;
    for (int i = 0; i < precision; i++) {
      if (f((Random::random32(p) & ((1 << f.arity) - 1))))
        val++;
    }
    return val / (double)precision;
  };

  std::vector<double> y = matplot::transform(x, eval_ppf);

  matplot::plot(x, y);

  matplot::show();
}
