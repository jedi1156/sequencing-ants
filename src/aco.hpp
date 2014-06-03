#ifndef _INCLUDE_ACO_HPP
#define _INCLUDE_ACO_HPP

#include "common.hpp"
#include "ant.hpp"
#include "graph.hpp"
#include "ranking.hpp"

class ACO {
private:
  vector<Ant*> ants;
  Graph *graph;
  Ranking *ranking;

  bool parallel;
  vector<thread> threads;

  void update_pheromones();
  void iteration();
  void one_ant_iteration(Ant *ant);
  void finish_iteration();
public:
  ACO(Graph *graph, unsigned number_of_ants);
  ~ACO();
  void optimize();
};

#endif
