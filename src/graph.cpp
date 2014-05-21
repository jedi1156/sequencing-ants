#include "graph.hpp"

Graph::Graph(string filename) {
	// open file
  ifstream file;
  file.open((char*)filename.c_str());

  // load nodes
  string s;
  while(file >> s) {
    if(D) cout << "adding " << s << endl;
    nodes.push_back(new Node(s));
  }

  //  matrix
  matrix = new Edge**[nodes.size()];
  for (unsigned i = 0; i < nodes.size(); i++) {
    matrix[i] = new Edge*[nodes.size()];
    for (unsigned j = 0; j < nodes.size(); j++) {
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

  // deallocate edges
  // deallocate matrix
}
