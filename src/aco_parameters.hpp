#ifndef _INCLUDE_ACO_PARAMETERS_HPP
#define _INCLUDE_ACO_PARAMETERS_HPP

#include "common.hpp"

#define ALPHA 2
#define BETA 15
#define GAMMA 3
#define NUMBER_OF_ANTS 10
#define Q_PARAM 1.0
#define R_PARAM 1.0
#define RO 0.6
#define MAX_PHEROMONES_MULTIPLIER 1
#define AMPLIFY_BEST 1.0

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
  double max_pheromones; // q * max_pheromones_multiplier = max_pheromones
  double amplify_best; // How strongly (in r-scale) should be the best found solution re-enforced

public:
  ACOParameters(double alpha, double beta, double gamma,
    unsigned number_of_ants, unsigned max_solution_length,
    double q, double r, double ro, double max_pheromones_multiplier,
    double amplify_best)
  : alpha(alpha)
  , beta(beta)
  , gamma(gamma)
  , number_of_ants(number_of_ants)
  , max_solution_length(max_solution_length)
  , q(q)
  , r(r)
  , ro(ro)
  , max_pheromones(max_pheromones_multiplier * q)
  , amplify_best(amplify_best)
  {}

  virtual ~ACOParameters() {}

  double get_alpha() const { return alpha; }
  double get_beta()  const { return beta; }
  double get_gamma() const { return gamma; }
  unsigned get_number_of_ants() const { return number_of_ants; }
  unsigned get_max_solution_length() const { return max_solution_length; }
  double get_q() const { return q; }
  unsigned get_no_ranking_ants() const { return round(max(0.0, min(r, 1.0)) * number_of_ants); }
  double get_ro() const { return ro; }
  double get_max_pheromones() const { return max_pheromones; }
  double get_amplify_best() const { return amplify_best; }

  friend ostream& operator<<(ostream& os, const ACOParameters &params);
};

#endif
