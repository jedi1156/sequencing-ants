#ifndef _INCLUDE_ACO_SEQUENTIAL_STRATEGY_HPP
#define _INCLUDE_ACO_SEQUENTIAL_STRATEGY_HPP

#include "common.hpp"
#include "aco_strategy.hpp"
#include "aco_parameters.hpp"

class ACOSequentialStrategy : public ACOStrategy {
protected:
  void setup_optimization();
  void iteration();
public:
  ACOSequentialStrategy(ACOParameters *params);
  void finish_optimization();
};

#endif
