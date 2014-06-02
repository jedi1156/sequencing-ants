#include "common.hpp"
#include "graph.hpp"

int main(int argc, char* argv[]) {
  if(argc == 2) {
    Graph *g = new Graph(argv[1]);
    if (D) { cout << *g << endl; }

    ACO *colony = new ACO(g, NUMBER_OF_ANTS);
    colony->optimize();

    delete g;
    delete colony;
  }
  return 0;
}
