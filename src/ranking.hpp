#ifndef _INCLUDE_RANKING_HPP
#define _INCLUDE_RANKING_HPP

#include "common.hpp"
#include "aco_parameters.hpp"
#include "ant.hpp"

class Ranking {
private:
  ACOParameters *params;
  vector<Ant *> ants;
  unsigned no_ranking_ants;

  Solution *best_solution;

  void prepare_pheromones_for_one_ant(Ant *ant, unsigned ranking_position);
public:
  Ranking(ACOParameters *params, vector<Ant *> &ants);

  double calculate_additional_pheromones(Solution *solution, unsigned ranking_position);
  void prepare_pheromones();
  void update();

  Solution *get_best_solution() { return best_solution; }

  static bool ants_comparator(Ant *a1, Ant *a2);
  static bool solutions_comparator(Solution *s1, Solution *s2);
  void free_memory();
};

#endif
