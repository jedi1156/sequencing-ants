#ifndef _INCLUDE_RANKING_HPP
#define _INCLUDE_RANKING_HPP

#include "ant.hpp"

class Ranking {
private:
  vector<Ant *> ants;

  void prepare_pheromones_for_one_ant(Ant *ant, unsigned ranking_position);
public:
  Ranking(vector<Ant *> &ants);

  void prepare_pheromones();
  void update();
};

#endif
