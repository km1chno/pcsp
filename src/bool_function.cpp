#include "bool_function.hpp"
#include <boost/dynamic_bitset.hpp>
#include <boost/dynamic_bitset/dynamic_bitset.hpp>

bool_function::bool_function(std::function<bool(boost::dynamic_bitset<>)> _f,
                             uint32_t _arity)
    : f(_f), arity(_arity) {}

bool_function::bool_function(std::function<bool(uint32_t)> _fu32,
                             uint32_t _arity)
    : arity(_arity) {
  f = [=](const boost::dynamic_bitset<> &x) -> bool {
    return _fu32(x.to_ulong());
  };
}

bool bool_function::operator()(uint32_t x) const {
  return f(boost::dynamic_bitset<>(32, x));
}

bool bool_function::operator()(const boost::dynamic_bitset<> &x) const {
  return f(x);
}
