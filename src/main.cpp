#include "common.hpp"
#include "graph.hpp"

int main(int argc, char* argv[]) {
  if(argc == 2) {
    Graph *g = new Graph(argv[1]);
    cout << *g << endl;
    delete g;
  }
  return 0;
}
