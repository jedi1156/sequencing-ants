#include "aco_sequential_strategy.hpp"

void ACOSequentialStrategy::setup_optimization() {
}

void ACOSequentialStrategy::iteration() {
  for (unsigned i = 0, len = ants.size(); i < len; ++i) {
    ants[i]->traverse_graph();
  }
}

void ACOSequentialStrategy::finish_optimization() {
}
