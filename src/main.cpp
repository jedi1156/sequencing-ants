#include "common.hpp"
#include "graph.hpp"

int main() {
  Graph *g = new Graph("test/instances/1-random-neg/9.200-40");
  delete g;
  return 0;
}
