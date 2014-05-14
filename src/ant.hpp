#ifndef _INCLUDE_ANT_HPP
#define _INCLUDE_ANT_HPP

#include "common.hpp"

class Ant {
private:
  Graph *graph;
  Solution *solution;

public:
  Ant(Graph *graph);

  // builds solution
  void traverse_graph();
};

#endif
