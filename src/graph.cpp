#include "graph.hpp"

extern int debug;

Graph::Graph(string filename) {
	// open file
  ifstream file;
  file.open((char*)filename.c_str());

  // load nodes
  string s;
  for(unsigned index = 0; file >> s; index++) {
    if(debug >= 4) cout << "adding " << s << endl;
    nodes.push_back(new Node(s, index));
  }

  size = nodes.size();
  //  matrix
  matrix = new Edge**[size];
  for (unsigned i = 0; i < size; i++) {
    matrix[i] = new Edge*[size];
    for (unsigned j = 0; j < size; j++) {
      matrix[i][j] = new Edge(nodes[i], nodes[j]);
    }
  }
  // close file
  file.close();
}

Graph::~Graph() {

  for (unsigned i=0; i < nodes.size(); i++) {
    delete nodes[i];
  }
  nodes.clear();

  for (unsigned i = 0; i < size; i++) {
    for (unsigned j = 0; j < size; j++) {
        delete matrix[i][j];
      }
      delete matrix[i];
    }
    delete matrix;
}

Edge* Graph::get_edge(int i, int j) {
  return matrix[i][j];
}

unsigned Graph::get_node_size() {
  Node *node = nodes.front();
  if (!node) { return 0; }
  return node->get_length();
}

void Graph::iterate(double ro, double max_pheromones) {
  double sum_ph = 0;
  for (unsigned i = 0; i < size; i++) {
    for (unsigned j = 0; j < size; j++) {
      matrix[i][j]->iterate(ro, max_pheromones);
      if (debug >= 2) { sum_ph += matrix[i][j]->get_pheromones(); }
    }
  }
  if (debug >= 2) { cout << "Sum of pheromonoes: " << sum_ph << endl; }
}

double Graph::rate_node_as_first(Node *node) {
  unsigned in_sum = 0;
  unsigned out_sum = 0;
  for(unsigned i = 0; i < size; i++) {
    out_sum += matrix[node->get_index()][i]->get_weight();
    in_sum += matrix[i][node->get_index()]->get_weight();
  }
  return out_sum - in_sum;
}

ostream& operator<<(ostream& os, const Graph& g) {
  os << "Graph[size="<<g.get_size()<<"]";
  os << " (";
  for (unsigned i=0; i < g.get_size(); i++) {
    os << g.get_nodes()[i]->get_value();
    if(i != g.get_size()-1)  os << ", ";
  }
  os << ")\n";

  for (unsigned i=0; i < g.get_size(); i++) {
    os << g.get_nodes()[i]->get_value() << " -> ";
      for (unsigned j = 0; j < g.get_size(); j++) {
        Edge* e = g.get_matrix()[i][j];
        if (e->get_weight() > 0)
          os << g.get_nodes()[j]->get_value() << "("<<e->get_weight()<<"), ";
      }
      os << endl;
  }
  return os;
}
