#ifndef _INCLUDE_ACO_HPP
#define _INCLUDE_ACO_HPP

class ACO {
private:
  vector<Ant*> ants;
  Graph *graph;
  Ranking *ranking;

public:
  ACO(Graph *graph, unsigned number_of_ants);
  void optimize();
};

#endif
