#ifndef _INCLUDE_SOLUTION_HPP
#define _INCLUDE_SOLUTION_HPP

#include "common.hpp"

class Solution {
private:
  vector<Node*> nodes;
  unsigned no_unique_nodes;
  vector<unsigned> no_visits;

public:
  Solution();

  add_node(Node *node);
};

#endif
