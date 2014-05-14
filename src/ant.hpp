#ifndef _INCLUDE_ANT_HPP
#define _INCLUDE_ANT_HPP

#include "common.hpp"
#include "solution.hpp"
#include "graph.hpp"

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
