#include "aco_parameters.hpp"

ostream& operator<<(ostream& os, const ACOParameters &params) {

  os << "PARAMETERS" << endl;
  os << "==========" << endl;
  os << endl;
  os << "alpha:               " << params.get_alpha() << endl;
  os << "beta:                " << params.get_beta() << endl;
  os << "gamma:               " << params.get_gamma() << endl;
  os << "N/O ants:            " << params.get_number_of_ants() << endl;
  os << "N/0 ranking ants:    " << params.get_no_ranking_ants() << endl;
  os << "Max solution length: " << params.get_max_solution_length() << endl;
  os << "Q (enforcement):     " << params.get_q() << endl;
  os << "ro (evaporation):    " << params.get_ro() << endl;
  os << "Max pheromones:      " << params.get_max_pheromones() << endl;

  return os;
}
