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

  unsigned max_solution_length;
  {
    unsigned pos = instance_file.find(".");
    if (pos == string::npos) {
      cerr << "Bad filename format, use: *.<n>*" << endl;
      return 1;
    }
    sscanf(instance_file.substr(pos + 1).c_str(), "%u", &max_solution_length);
    if (max_solution_length == 0) {
      cerr << "n == 0, bad filename format, use: *.<n>*" << endl;
      return 1;
    }
  }

  ini_t ini(config_file, true);

  ini.select("global");
  bool parallel = ini.get<bool>("parallel", 0);
  debug = ini.get<int>("debug", 0);


  Graph *graph = new Graph(instance_file);
  if(graph->get_size() == 0) {
    cout << "Graph initialization failed\n";
    return 0;
  }

  max_solution_length += graph->get_node_size() - 1;

  if (debug >= 2) { cout << "n = " << max_solution_length << endl; }


  ini.select("ACOParameters");
  ACOParameters params( ini.get<double>("alpha", ALPHA),
                        ini.get<double>("beta", BETA),
                        ini.get<double>("gamma", GAMMA),
                        ini.get<unsigned>("number_of_ants", NUMBER_OF_ANTS),
                        max_solution_length,
                        ini.get<double>("q_param", Q_PARAM),
                        ini.get<double>("r_param", R_PARAM),
                        ini.get<double>("ro", RO),
                        ini.get<double>("max_pheromones_multiplier", MAX_PHEROMONES_MULTIPLIER),
                        ini.get<double>("amplify_best", AMPLIFY_BEST)
                        );
  if(debug) cout << params << endl;

  if(debug >= 4) cout << *graph << endl;


  ACOStrategy *strategy;
  if (parallel) {
    strategy = new ACOParallelStrategy(&params);
  } else {
    strategy = new ACOSequentialStrategy(&params);
  }

  metaheuristic = new ACO(graph, strategy, &params);
  metaheuristic->optimize();

  delete metaheuristic;
  delete graph;
  return 0;
}
