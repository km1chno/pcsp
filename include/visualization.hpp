#pragma once

#include "bool_function.hpp"
#include <matplot/core/axes_type.h>

/**
 * Generic function for composing many subplots in tiled layout.
 *
 * @param plot_functions Sequence of functions plotting their graphs.
 */
void draw_tiled_layout_plot(
    int rows, int cols,
    std::vector<std::function<void(std::shared_ptr<matplot::axes_type>)>>
        plot_functions);

/**
 * Plot epf function for given boolean function of arity n.
 *
 * @complexity O(2^n * n * 1/step)
 * @param tile Matplot tile on which the graph should be plotted.
 * @param f The boolean function.
 * @param step The x-axis step.
 */
void plot_epf(std::shared_ptr<matplot::axes_type> tile, const bool_function &f,
              double step);

/**
 * Plot derivative of epf function for given boolean function of arity n.
 *
 * @complexity O(2^n * n * 1/step)
 * @param tile Matplot tile on which the graph should be plotted.
 * @param f The boolean function.
 * @param step The x-axis step.
 */
void plot_d_epf(std::shared_ptr<matplot::axes_type> tile,
                const bool_function &f, double step, std::vector<double> mark);

/**
 * Plot total influence for bias for given boolean function f of arity n.
 *
 * @complexity O(2^n * n * 1/step)
 * @param tile Matplot tile on which the graph should be plotted.
 * @param f The boolean function.
 * @param step The x-axis step.
 * @param mark Vector of marked x points on the graph. Can be empty.
 */
void plot_total_influence(std::shared_ptr<matplot::axes_type> tile,
                          const bool_function &f, double step,
                          std::vector<double> mark);
