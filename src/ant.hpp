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

  void set_beginning_position();
  bool move();
  void step(Edge *edge);
  double heuristic_attrictiveness(Edge *choice);
  double probability_of_choice(Edge *choice);
  bool can_choose_edge(Edge *edge);
  void filter_choices(vector<Edge *> &potential_choices);
  Edge* choose_edge();
public:
  Ant(Graph *graph, double alpha, double beta, double gamma, unsigned max_solution_length);

  // builds solution
  void traverse_graph();
};

#endif
