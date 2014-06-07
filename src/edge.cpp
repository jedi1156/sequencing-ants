#include "edge.hpp"

Edge::Edge(Node* n1, Node* n2) {
  this->n1 = n1;
  this->n2 = n2;
  weight = calculate_overlay(n1->get_value(), n2->get_value());
  if(D >= 4) if(weight > 0) cout << "adding edge " << n1->get_value() << "->"<< n2->get_value() << "("<<weight<<")"<<endl;
}

unsigned Edge::calculate_overlay(string s1, string s2) {
  unsigned max = 0;
  for (unsigned i = 1; i < s1.length(); i++) {
    if(s1.substr(s1.length() - i, s1.length()) == s2.substr(0, i))
      max = i;
  }
  return max;
}

ostream& operator<<(ostream& os, const Edge& e) {
  os << "Edge["<<e.get_n1()->get_value() << e.get_n2()->get_value()<<"]";
  return os;
}

void Edge::add_pheromones(double ph) {
  next_iteration_pheromones += ph;
}

void Edge::iterate(double ro) {
  pheromones = (1 - ro) * pheromones + next_iteration_pheromones;
  next_iteration_pheromones = 0;
}
