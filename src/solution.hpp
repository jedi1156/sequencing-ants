#ifndef _INCLUDE_SOLUTION_HPP
#define _INCLUDE_SOLUTION_HPP

#include "common.hpp"
#include "node.hpp"
#include "edge.hpp"

class Solution {
private:
  vector<Edge*> edges;
  vector<Node*> nodes;
  unsigned no_nodes_in_graph;
  unsigned no_unique_nodes;
  map<Node*, unsigned> no_visits;
  unsigned length;

  Node* get_last_node();
  void visit(Node *node);

public:
  Solution(unsigned no_nodes_in_graph, Node *node);
  Node* add_edge(Edge *edge);
  unsigned get_no_visits(Node *node) { return no_visits[node]; }
  unsigned get_no_nodes_in_graph() const { return no_nodes_in_graph; }
  unsigned get_cummulated_length(Edge *edge) const;
  double get_quality() const;

  unsigned get_length() const { return length; }

  vector<Edge*> &get_edges() { return edges; }
  vector<Node*> get_nodes() const { return nodes; }

  string print_header() const;
  friend ostream& operator<<(ostream& os, const Solution& solution);
};

#endif
