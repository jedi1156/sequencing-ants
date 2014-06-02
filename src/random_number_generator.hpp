#ifndef _INCLUDE_RANDOM_NUMBER_GENERATOR_HPP
#define _INCLUDE_RANDOM_NUMBER_GENERATOR_HPP

#include "common.hpp"

class RandomNumberGenerator {
private:
  unsigned calls_left;
  void seed_init();
  void decrement_calls();

public:
  RandomNumberGenerator();

  int random_int();
  double norm_random_double();
  double random(double from, double to);
  int roulette(vector<double> &distribution);
};


#endif
