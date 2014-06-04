#ifndef _INCLUDE_ACO_STRATEGY_HPP
#define _INCLUDE_ACO_STRATEGY_HPP

#include "common.hpp"
#include "ants.hpp"
#include "metaheuristic.hpp"

class Graph;

class ACOStrategy {
protected:
  Metaheuristic *colony;
  unsigned no_iteration;
  ACOParameters *params;
  vector<Ant*> ants;

public:
  ACOStrategy(ACOParameters *params)
  : iteration(0)
  , params(params)
  {}

  virtual ~ACOStrategy();

  void set_colony(Metaheuristic *colony) { this->colony = colony; }
  bool is_working() { colony->is_working(); }

  virtual vector<Ant *> &create_ants(Graph *graph) {
    for (unsigned i = 0, len = params->get_number_of_ants; i < len; ++i) {
      ants.push_back(
        new Ant(graph, params->get_alpha(), params->get_beta(),
          params->get_gamma(), params->get_max_solution_length()
      );
    }
    return ants;
  }

  virtual void setup_optimization() = 0;
  void before_optimization() {
    no_iteration = 0;
    setup_optimization();
  }

  virtual void finish_optimization() = 0;

  void perform_iteration() {
    no_iteration += 1;
    iteration();
  }
  virtual void iteration() = 0;

  unsigned get_no_iteration() { return no_iteration; }
};

#endif
