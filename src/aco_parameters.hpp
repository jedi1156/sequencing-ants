#ifndef _INCLUDE_ACO_PARAMETERS_HPP
#define _INCLUDE_ACO_PARAMETERS_HPP

#include "common.hpp"

class ACOParameters {
protected:
  double alpha;       // importance of pheromones
  double beta;        // importance of local heuristic
  double gamma;       // punishment quantifier for node repetitions
  unsigned number_of_ants;
  unsigned max_solution_length;
  double q;           // new pheromones quantifier
  double r;           // best part of ants that has impact on pheromones [0..1]
  double ro;          // pheromone evaporation parameter

public:
  ACOParameters(double alpha, double beta, double gamma,
    unsigned number_of_ants, unsigned max_solution_length,
    double q, double r, double ro)
  : alpha(alpha)
  , beta(beta)
  , gamma(gamma)
  , number_of_ants(number_of_ants)
  , max_solution_length(max_solution_length)
  , q(q)
  , r(r)
  , ro(ro)
  {}

  virtual ~ACOParameters() {}

  double get_alpha() { return alpha; }
  double get_beta()  { return beta; }
  double get_gamma() { return gamma; }
  unsigned get_number_of_ants() { return number_of_ants; }
  unsigned get_max_solution_length() { return max_solution_length; }
  double get_q() { return q; }
  unsigned get_no_ranking_ants() { return round(max(0.0, min(r, 1.0)) * number_of_ants); }
  double get_ro() { return q; }
};

#endif
