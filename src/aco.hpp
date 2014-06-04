#ifndef _INCLUDE_ACO_HPP
#define _INCLUDE_ACO_HPP

#include "common.hpp"
#include "ant.hpp"
#include "graph.hpp"
#include "ranking.hpp"
#include "aco_strategy.hpp"
#include "metaheuristic.hpp"

class ACO : public Metaheuristic {
private:
  vector<Ant*> ants;
  Graph *graph;
  ACOStrategy *strategy;
  ACOParameters *params;
  Ranking *ranking;

  void update_pheromones();
  void finish_iteration();
public:
  ACO(Graph *graph, ACOStrategy *strategy, ACOParameters *params);
  ~ACO();
  void optimize();

  void notify();
  void wait_until_start();
};

#endif
