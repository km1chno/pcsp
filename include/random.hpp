#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_01.hpp>

class Random {
private:
  static boost::random::mt19937 gen;
  static boost::random::uniform_01<boost::random::mt19937> uniform_01_dist;

public:
  /**
   * Returns uniform random double from range [0, 1).
   *
   * @complexity O(1).
   * @return uniform random double from range [0, 1).
   */
  static double random01();

  /**
   * Return random unsigned 32 bit integer.
   *
   * @complexity O(1)
   * @param p Probability with which each bit is 1.
   * @return random u32 bit integer.
   */
  static uint32_t random32(double p = 0.5);
};
