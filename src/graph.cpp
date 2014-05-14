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
  for (unsigned i=0; i<nodes.size(); i++) {
    for (unsigned j=0; j<nodes.size(); j++) {

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
