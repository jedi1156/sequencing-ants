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

  string get_value() const { return value; }
  unsigned get_length() const { return value.size(); }
  unsigned get_index() const { return index; }
};

#endif
