#ifndef _INCLUDE_ANT_HPP
#define _INCLUDE_ANT_HPP

#include "common.hpp"
#include "solution.hpp"
#include "graph.hpp"
#include "random_number_generator.hpp"

class Ant {
private:
  double alpha;
  double beta;
  double gamma;
  Graph *graph;
  unsigned current_node;
  Solution *solution;
  RandomNumberGenerator generator;

public:
  Ant(Graph *graph, double alpha, double beta, double gamma);

  // builds solution
  void traverse_graph();
};

#endif
