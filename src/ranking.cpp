#include "ranking.hpp"

extern int debug;

Ranking::Ranking(ACOParameters *params, vector<Ant *> &ants)
: params(params)
, ants(ants)     // copy constructor
, best_solution(NULL)
{
  no_ranking_ants = params->get_no_ranking_ants();
}


void Ranking::update() {
  sort(ants.begin(), ants.end(), Ranking::ants_comparator);

  if (debug >= 5) { cout << "Ranking> Setting best" << endl; }
  if ((best_solution == NULL) || (solutions_comparator(best_solution, ants.back()->get_solution()))) {
    best_solution = new Solution(*ants.back()->get_solution());
  }
  if(debug) {
    cout << "\t\t\t\t\t\t\t" << print(5) << endl;
  }
}

string Ranking::print(unsigned n) {
  string s("");
  for (unsigned i = 0; i < n; i++ ) {
    Ant *a = ants[ants.size() - 1 - i*(ants.size()/n)];
    if(a->get_solution() != NULL) {
      s += to_string(a->get_solution()->get_quality());
      s += " ";
    }
  }
  return s;
}

void Ranking::free_memory() {
  if (debug >= 5) { cout << "Ranking> freeing solutions" << endl; }
  for (unsigned i = 0; i < no_ranking_ants; ++i) {
    if (debug >= 6) { cout << "Ranking> freeing #" << i << endl; }
    ants[i]->free_solution();
    if (debug >= 6) { cout << "Ranking> freed #" << i << endl; }
  }
  if (debug >= 5) { cout << "Ranking> freed" << endl; }
}

void Ranking::prepare_pheromones() {
  for (unsigned i = 0; i < no_ranking_ants; ++i) {
    prepare_pheromones_for_one_solution(ants[i]->get_solution(), i);
  }
  if (params->get_amplify_best() > 0 && best_solution) {
    prepare_pheromones_for_one_solution(best_solution, (1.0 - params->get_amplify_best()) * ants.size());
  }
}

double Ranking::calculate_additional_pheromones(Solution *solution, unsigned ranking_position) {
  double position_multiplier = ((double)(ants.size() - ranking_position)) * 2 / (ants.size() * (ants.size() + 1));
  return params->get_q() * position_multiplier * solution->get_quality();
}

void Ranking::prepare_pheromones_for_one_solution(Solution *solution, unsigned ranking_position) {
  double additional_pheromones = calculate_additional_pheromones(solution, ranking_position);
  if (debug >= 4) { cout << "Ranking> additional pheromones for ant#" << ranking_position << ":\t" << additional_pheromones << endl; }

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
