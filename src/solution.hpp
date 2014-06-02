#ifndef _INCLUDE_SOLUTION_HPP
#define _INCLUDE_SOLUTION_HPP

#include "common.hpp"
#include "node.hpp"

class Solution {
private:
  vector<Node*> nodes;
  unsigned no_unique_nodes;
  vector<unsigned> no_visits;
  unsigned length;

  Node* get_last_node();

public:
  Solution();

  void add_node(Node *node);

  void visit(unsigned i) { no_visits[i] += 1; }
  unsigned get_no_visits(unsigned i) { return no_visits[i]; }
  unsigned get_cummulated_length(Edge *);
};

#endif
