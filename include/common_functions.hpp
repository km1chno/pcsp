#pragma once

#include "bool_function.hpp"
#include <boost/dynamic_bitset.hpp>
#include <stdint.h>

class common_functions {
public:
  /**
   * Returns n-ary projection to coordinate i defined as:
   *
   * proj(n, i)(x) = x_i.
   */
  static bool_function proj(uint32_t n, uint32_t i);

  /**
   * Returns n-ary threshold for param t defined as:
   *
   * thr(n, t)(x) = 1 iff |x| >= t.
   */
  static bool_function thr(uint32_t n, uint32_t t);

  /**
   * Returns n-ary (n must be odd!) majority, defined as:
   *
   * maj(n)(x) = 1 iff |x| >= \ceil{n/2}.
   */
  static bool_function maj(uint32_t n);
};
