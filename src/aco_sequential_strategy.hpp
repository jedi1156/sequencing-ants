#ifndef _INCLUDE_ACO_SEQUENTIAL_STRATEGY_HPP
#define _INCLUDE_ACO_SEQUENTIAL_STRATEGY_HPP

#include "common.hpp"
#include "aco_strategy.hpp"

class ACOSequentialStrategy : public ACOStrategy {
public:
  void setup_optimization();
  void finish_optimization();
  void iteration();
};

#endif
