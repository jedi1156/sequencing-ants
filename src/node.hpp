#ifndef _INCLUDE_NODE_HPP
#define _INCLUDE_NODE_HPP

#include "common.hpp"

class Node {
private:
  string value;

public:
  Node(string value) :
    value(value) {
  }

  string get_value() { return value; }
};

#endif
