#include "ranking.hpp"

Ranking::Ranking(ACOParameters *params, vector<Ant *> &ants)
: params(params)
, ants(ants)     // copy constructor
{
  no_ranking_ants = params->get_no_ranking_ants();
}

// TODO
void Ranking::update() {
  // sort ants by solution value
  // update best-so-far solution (solutions?)
}

void Ranking::prepare_pheromones() {
  for (unsigned i = 0; i < no_ranking_ants; i++) {
    prepare_pheromones_for_one_ant(ants[i], i);
  }
}

double Ranking::calculate_additional_pheromones(Solution *solution, unsigned ranking_position) {
  return params->get_q() * (ants.size() - ranking_position) * solution->get_quality();
}

void Ranking::prepare_pheromones_for_one_ant(Ant *ant, unsigned ranking_position) {
  Solution *solution = ant->get_solution();
  double additional_pheromones = calculate_additional_pheromones(solution, ranking_position);

  vector<Edge*> edges = solution->get_edges();
  for (unsigned i = 0, len = edges.size(); i < len; ++i) {
    edges[i]->add_pheromones(additional_pheromones);
  }
}
