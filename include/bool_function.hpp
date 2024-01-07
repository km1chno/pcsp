#pragma once

#include <boost/dynamic_bitset.hpp>
#include <functional>
#include <stdint.h>

class bool_function {
private:
  std::function<bool(boost::dynamic_bitset<>)> f;

public:
  uint32_t arity;

  bool_function(std::function<bool(boost::dynamic_bitset<>)> _f,
                uint32_t _arity);

  bool_function(std::function<bool(uint32_t)> _f, uint32_t _arity);

  bool operator()(uint32_t x) const;

  bool operator()(const boost::dynamic_bitset<> &x) const;
};
