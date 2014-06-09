#include "aco_sequential_strategy.hpp"

extern int debug;

ACOSequentialStrategy::ACOSequentialStrategy(ACOParameters *params)
: ACOStrategy(params)
{}

void ACOSequentialStrategy::setup_optimization() {
}

void ACOSequentialStrategy::iteration() {
  for (unsigned i = 0, len = ants.size(); i < len; ++i) {
    if (debug >= 4) { cout << "Ant #" << i << " traversing graph" << endl; }
    ants[i]->traverse_graph();
  }
}

void ACOSequentialStrategy::finish_optimization() {
}
