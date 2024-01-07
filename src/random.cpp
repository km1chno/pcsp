#include "random.hpp"
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_01.hpp>
#include <ctime>

boost::random::mt19937 Random::gen{static_cast<uint32_t>(std::time(0))};

boost::random::uniform_01<boost::random::mt19937> Random::uniform_01_dist(gen);

/**
 * Returns uniform random double from range [0, 1).
 *
 * @complexity O(1).
 * @return uniform random double from range [0, 1).
 */
double Random::random01() { return uniform_01_dist(); }

/**
 * Return random unsigned 32 bit integer.
 *
 * @complexity O(1)
 * @param p Probability with which each bit is 1.
 * @return random u32 bit integer.
 */
uint32_t Random::random32(double p) {
  uint32_t x = 0;
  for (int i = 0; i < 32; i++)
    if (random01() <= p)
      x |= (1 << i);
  return x;
}
