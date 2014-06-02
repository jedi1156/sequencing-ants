#ifndef _INCLUDE_ACO_HPP
#define _INCLUDE_ACO_HPP

class ACO {
private:
  vector<Ant*> ants;
  Graph *graph;
  Ranking *ranking;

  bool parallel;
  vector<thread> threads;

  void iteration();
  void one_ant_iteration(Ant *ant);
  void finish_iteration();
public:
  ACO(Graph *graph, unsigned number_of_ants);
  void optimize();
};

#endif
