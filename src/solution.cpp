#include "solution.hpp"

Node* Solution::get_last_node() {
  return this->nodes[this->nodes.size() - 1];
}
unsigned Solution::get_cummulated_length(Edge *edge) {
  unsigned node_size = edge->other_node(get_last_node())->get_value().size()
  return this->length + node_size - edge->get_weight();
}
