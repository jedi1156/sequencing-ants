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
  unsigned get_size() const { return size; }
  Edge*** get_matrix() const { return matrix; }

  friend ostream& operator<<(ostream& os, const Graph& graph);
};

#endif
