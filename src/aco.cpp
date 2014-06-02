#include "aco.hpp"

ACO::ACO(Graph *graph, unsigned number_of_ants)
: graph(graph) {
  // create ants
  // create ranking(ants)
}

ACO::~ACO() {
  // destroy ants
  // destroy ranking
}

void ACO::optimize() {
  for ( iterations, term conditions ) {
    iteration();
    finish_iteration();
  }
}

void ACO::iteration() {
  if (parallel) {
    for ( t = threads[i] in threads ) {
      t = thread(one_ant_iteration, ants[i])
    }
    for ( t in threads ) {
      t.join()
    }
  } else {
    for ( a in ants ) {
      one_ant_iteration(a);
    }
  }
}

void ACO::one_ant_iteration(Ant *ant) {
  ant->traverse_graph()
}

void ACO::finish_iteration() {
  // update ranking
  // update graph - pheromones
}
