#include "aco.hpp"

extern int debug;

ACO::ACO(Graph *graph, ACOStrategy *strategy, ACOParameters *params)
: Metaheuristic()
, graph(graph)
, strategy(strategy)
, params(params) {
  strategy->set_colony(this);
  ants = strategy->create_ants(graph);
  ranking = new Ranking(params, ants);
}

ACO::~ACO() {
  delete strategy;
  if (get_best_solution()) { delete get_best_solution(); }
  delete ranking;
  for (unsigned i = 0, len = ants.size(); i < len; ++i) {
    delete ants[i];
  }
}

void ACO::optimize() {
  strategy->before_optimization();
  while (is_working()) {
    if (debug) {
      cout << "Iteration #" << strategy->get_no_iteration() << ":\tquality:\t";
      Solution *solution = get_best_solution();
      cout << (solution ? solution->get_quality() : 0.0) << endl;
    }
    strategy->perform_iteration();
    finish_iteration();
  }
  strategy->finish_optimization();
}

void ACO::finish_iteration() {
  ranking->update();
  update_pheromones();
  ranking->free_memory();
}

void ACO::update_pheromones() {
  ranking->prepare_pheromones();
  graph->iterate(params->get_ro());
}

