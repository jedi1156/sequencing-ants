#include "ranking.hpp"

Ranking::Ranking(ACOParameters *params, vector<Ant *> &ants)
: params(params)
, ants(ants)     // copy constructor
, best_solution(NULL)
{
  no_ranking_ants = params->get_no_ranking_ants();
}


// memory leak
void Ranking::update() {
  sort(ants.begin(), ants.end(), Ranking::ants_comparator);

  if ((best_solution == NULL) || (solutions_comparator(best_solution, ants.front()->get_solution()))) {
    best_solution = ants.front()->get_solution();
  }
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

bool Ranking::ants_comparator(Ant *a1, Ant *a2) {
  return solutions_comparator(a1->get_solution(), a2->get_solution());
}

bool Ranking::solutions_comparator(Solution *s1, Solution *s2) {
  return s1->get_quality() < s2->get_quality();
}
