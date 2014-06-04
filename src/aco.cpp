#include "aco.hpp"

ACO::ACO(Graph *graph, ACOStrategy *strategy)
: Metaheuristic()
, graph(graph)
, strategy(strategy) {
  strategy->set_colony(this);
  ants = strategy->create_ants(graph);
  ranking = new Ranking(params, ants);
}

ACO::~ACO() {
  delete strategy;
  delete ranking;
  for (unsigned i = 0, len = ants.size(); i < len; ++i) {
    delete ants[i];
  }
}

void ACO::optimize() {
  strategy->before_optimization();
  while (is_working()) {
    strategy->perform_iteration();
    finish_iteration();
  }
  strategy->finish_optimization();
}

void ACO::finish_iteration() {
  ranking->update();
  update_pheromones();
}

void ACO::update_pheromones() {
  ranking->prepare_pheromones();
  graph->iterate();
}

