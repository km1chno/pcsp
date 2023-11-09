#include <iostream>
#include "../include/poly.hpp"
#include "../include/math.hpp"

int main() {
  preprocess();

  BinPol f(3, {
    { 0b000, 0 },
    { 0b001, 0 },
    { 0b010, 0 },
    { 0b011, 1 },
    { 0b100, 0 },
    { 0b101, 1 },
    { 0b110, 1 },
    { 0b111, 1 }});
  
  std::vector<double> phi = f.shapley();
  for (auto x : phi) std::cout << x << " ";
  std::cout << "\n";
}
