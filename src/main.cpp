#include "common.hpp"
#include "graph.hpp"
#include "aco_parallel_strategy.hpp"
#include "aco_sequential_strategy.hpp"
#include "metaheuristic.hpp"
#include "aco.hpp"

#define PARALLEL true

#define MAX_SOLUTION_LENGTH 100

Metaheuristic *metaheuristic = NULL;
void terminte_work(int sig) {
  if (metaheuristic) { metaheuristic->terminate(); }
}

int main(int argc, char* argv[]) {
  signal(SIGINT, terminte_work);

  if(argc == 2) {
    bool parallel = PARALLEL; // TODO: read from args

    Graph *graph = new Graph(argv[1]);
    if (D) { cout << *graph << endl; }

    ACOParameters params(ALPHA, BETA, GAMMA, NUMBER_OF_ANTS, MAX_SOLUTION_LENGTH);

    ACOStrategy *strategy;
    if (parallel) {
      strategy = new ACOParallelStrategy(params);
    } else {
      strategy = new ACOSequentialStrategy(params);
    }

    metaheuristic = new ACO(g, strategy);
    metaheuristic->optimize();

    delete metaheuristic;
    delete graph;
  }
  return 0;
}
