#include "common_functions.hpp"
#include <boost/dynamic_bitset/dynamic_bitset.hpp>

/**
 * Returns n-ary projection to coordinate i defined as:
 *
 * proj(n, i)(x) = x_i.
 */
bool_function common_functions::proj(uint32_t n, uint32_t i) {
  return bool_function([=](const boost::dynamic_bitset<> &x) { return x[i]; },
                       n);
}

/**
 * Returns n-ary threshold for param t defined as:
 *
 * thr(n, t)(x) = 1 iff |x| >= t.
 */
bool_function common_functions::thr(uint32_t n, uint32_t t) {
  return bool_function(
      [=](const boost::dynamic_bitset<> &x) { return x.count() >= t; }, n);
}

/**
 * Returns n-ary (n must be odd!) majority, defined as:
 *
 * maj(n)(x) = 1 iff |x| >= \ceil{n/2}.
 */
bool_function common_functions::maj(uint32_t n) { return thr(n, (n + 1) / 2); }
