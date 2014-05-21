#include "edge.hpp"

Edge::Edge(Node* v1, Node* v2) {
  this->v1 = v1;
  this->v2 = v2;
  value = calculate_overlay(v1->get_value(), v2->get_value());
  if(D) cout << "adding edge " << v1->get_value() << "->"<< v2->get_value() << "("<<value<<")"<<endl;
}

int Edge::calculate_overlay(string s1, string s2) {
  int max = 0;
  for (unsigned i = 1; i < s1.length(); i++) {
    if(s1.substr(s1.length() - i, s1.length()) == s2.substr(0, i))
      max = i;
  }
  return max;
}
