#include "graph.hpp"

using namespace std;

Graph::Graph(string filename) {
	// open file
  ofstream file;
  file.open(filename, ios:in);

  // load nodes
  string s;
  while(file >> s) {
    nodes.push_back(new Node(s));
  }

  //  matrix
  for (int i=0; i<nodes.size(); i++) {
    for (int j=0; j<nodes.size(); j++) {

    }
  }

  // close file
  file.close();
}

Graph::~Graph() {
  // deallocate nodes
  // deallocate edges
  // deallocate matrix
}
