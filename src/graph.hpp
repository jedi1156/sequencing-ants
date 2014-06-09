#ifndef _INCLUDE_GRAPH_HPP
#define _INCLUDE_GRAPH_HPP

#include "common.hpp"
#include "node.hpp"
#include "edge.hpp"

class Graph {
private:
  unsigned size;
  Edge*** matrix;
  vector<Node*> nodes;

public:
  Graph(string filename);
  ~Graph();
  vector<Node*> get_nodes() const { return nodes; }
  unsigned get_node_size();
  unsigned get_size() const { return size; }
  Edge*** get_matrix() const { return matrix; }
  Edge* get_edge(int i, int j);
  double rate_node_as_first(Node *node);

  void iterate(double ro, double max_pheromones);

  friend ostream& operator<<(ostream& os, const Graph& graph);
};

#endif
