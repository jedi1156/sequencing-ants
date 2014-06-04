#include "solution.hpp"

Solution::Solution(Node *node) {
  nodes.push_back(node);
  no_unique_nodes = 1;
}

Node* Solution::get_last_node() {
  return this->nodes[this->nodes.size() - 1];
}

unsigned Solution::get_cummulated_length(Edge *edge) {
  unsigned node_size = edge->other_node(get_last_node())->get_value().size()
  return this->length + node_size - edge->get_weight();
}

void Solution::visit(Node *node) {
  no_visits[node] += 1;
  if(no_visits[node] == 1) no_unique_nodes++;
}

Node* Solution::add_edge(Edge *edge) {
  Node *node = edge->get_n2();
  edges.push_back(edge);
  nodes.push_back(node);
  visit(node);
  return node;
}
