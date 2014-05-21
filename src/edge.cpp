#include "edge.hpp"

Edge::Edge(Node* n1, Node* n2) {
  this->n1 = n1;
  this->n2 = n2;
  weight = calculate_overlay(n1->get_value(), n2->get_value());
  if(D) if(weight > 0) cout << "adding edge " << n1->get_value() << "->"<< n2->get_value() << "("<<weight<<")"<<endl;
}

Node* Edge::other_node(Node* node) {
  if(node->get_index() == n1->get_index()) return n2;
  return n1;
}

unsigned Edge::calculate_overlay(string s1, string s2) {
  unsigned max = 0;
  for (unsigned i = 1; i < s1.length(); i++) {
    if(s1.substr(s1.length() - i, s1.length()) == s2.substr(0, i))
      max = i;
  }
  return max;
}
