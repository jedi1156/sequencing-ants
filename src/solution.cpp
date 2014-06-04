#include "solution.hpp"

Node* Solution::get_last_node() {
  return this->nodes[this->nodes.size() - 1];
}

unsigned Solution::get_cummulated_length(Edge *edge) {
  unsigned node_size = edge->other_node(get_last_node())->get_value().size()
  return this->length + node_size - edge->get_weight();
}

Node* Solution::add_edge(Edge *edge) {
  edges.push_back(edge);
  if(!nodes.size()) {
    nodes.push_back(edge->get_n1());
  }
  nodes.push_back(edge->get_n2());
  return edge->get_n2();
}
