#ifndef _INCLUDE_NODE_HPP
#define _INCLUDE_NODE_HPP

#include "common.hpp"

class Node {
private:
  string value;
  unsigned index;

public:
  Node(string value, unsigned index) :
    value(value), index(index) {
  }

  string get_value() { return value; }
  unsigned get_index() { return index; }
};

#endif
