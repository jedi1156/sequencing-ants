#ifndef _INCLUDE_EDGE_HPP
#define _INCLUDE_EDGE_HPP

#include "common.hpp"
#include "node.hpp"

class Edge {
private:
  Node* n1;
  Node* n2;
  unsigned weight;
  unsigned calculate_overlay(string s1, string s2);

  double pheromones;
  double next_iteration_pheromones;

public:
  Edge(Node* n1, Node* n2);
  unsigned get_weight() const { return weight; }
  double get_normalized_weight() const;
  Node* get_n1() const { return n1; }
  Node* get_n2() const { return n2; }

  double get_pheromones() const { return pheromones; }
  void add_pheromones(double ph);
  void iterate(double ro, double maximum);

  friend ostream& operator<<(ostream& os, const Edge& edge);
};

#endif
