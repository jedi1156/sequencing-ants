#include "ranking.hpp"

// TODO
Ranking::Ranking(vector<Ant *> &ants)
: ants(ants) { // copy constructor
}

// TODO
void Ranking::update() {
  // sort ants by solution value
  // update best-so-far solution (solutions?)
}

// TODO
void Ranking::prepare_pheromones() {
  for ( ant in ants ) {
    prepare_pheromones_for_one_ant(ant, i);
  }
}

// TODO
void Ranking::prepare_pheromones_for_one_ant(Ant *ant, unsigned ranking position) {
  for ( edge in ant->solution ) {
    edge->add_pheromones( by ranking pos ); // wzór
  }
}
