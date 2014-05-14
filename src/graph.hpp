#ifndef _INCLUDE_GRAPH_HPP
#define _INCLUDE_GRAPH_HPP

#include "common.hpp"
#include "node.hpp"
#include "edge.hpp"

class Graph {
private:
  unsigned size;
  Edge** matrix;
  vector<Node*> nodes;

public:
  Graph(string filename);
  ~Graph();
};

#endif
