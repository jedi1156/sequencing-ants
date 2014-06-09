#include "common.hpp"
#include "graph.hpp"
#include "aco_parameters.hpp"
#include "aco_parallel_strategy.hpp"
#include "aco_sequential_strategy.hpp"
#include "metaheuristic.hpp"
#include "aco.hpp"
#include "INI.hpp"

Metaheuristic *metaheuristic = NULL;
int debug = 0;

void terminte_work(int sig) {
  if (metaheuristic) { metaheuristic->terminate(); }
}

int main(int argc, char* argv[]) {
  signal(SIGINT, terminte_work);

  string instance_file;
  string config_file;

  if(argc == 2) { //default config
    config_file = "config.ini";
  } else if (argc == 3) { //given config
    config_file = argv[2];
    cout << "Config from " << config_file << endl;
  } else {
    cout << "Usage: \n\tsequencing-ants <input file> <config file>(optional)\n";
    return 0;
  }

  instance_file = argv[1];

  Graph *graph = new Graph(instance_file);
  if(graph->get_size() == 0) {
    cout << "Graph initialization failed\n";
    return 0;
  }

  if(D) cout << *graph << endl;

  ini_t ini(config_file, true);

  ini.select("global");
  bool parallel = ini.get<bool>("parallel",0);

  ini.select("ACOParameters");
  ACOParameters params( ini.get<int>("alpha",0),
                        ini.get<int>("beta",0),
                        ini.get<int>("gamma",0),
                        ini.get<int>("number_of_ants",0),
                        ini.get<int>("max_solution_length",0),
                        ini.get<int>("q_param",0),
                        ini.get<int>("r_param",0),
                        ini.get<int>("ro",0));

  ACOStrategy *strategy;
  if (parallel) {
    strategy = new ACOParallelStrategy(&params);
  } else {
    strategy = new ACOSequentialStrategy(&params);
  }

  metaheuristic = new ACO(graph, strategy, &params);
  metaheuristic->optimize();

  delete strategy;
  delete metaheuristic;
  delete graph;
  return 0;
}
