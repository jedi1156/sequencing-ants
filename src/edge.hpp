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

public:
  Edge(Node* n1, Node* n2);
  Node* other_node(Node* node);
  unsigned get_weight() {return weight;}
};

#endif
