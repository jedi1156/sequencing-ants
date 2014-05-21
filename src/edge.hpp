#ifndef _INCLUDE_EDGE_HPP
#define _INCLUDE_EDGE_HPP

#include "common.hpp"
#include "node.hpp"

class Edge {
private:
  Node* v1;
  Node* v2;
  int value;
  int calculate_overlay(string s1, string s2);
public:
  Edge(Node* v1, Node* v2);

  int get_value() {return value;}
};

#endif
