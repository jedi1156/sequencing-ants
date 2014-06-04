#ifndef _INCLUDE_ACO_PARAMETERS_HPP
#define _INCLUDE_ACO_PARAMETERS_HPP

class ACOParameters {
protected:
  double alpha;       // importance of pheromones
  double beta;        // importance of local heuristic
  double gamma;       // punishment quantifier for node repetitions
  unsigned number_of_ants;
  unsigned max_solution_length;

public:
  ACOParameters(double alpha, double beta, double gamma,
    unsigned number_of_ants, unsigned max_solution_length)
  : alpha(alpha)
  , beta(beta)
  , gamma(gamma)
  , number_of_ants(number_of_ants)
  , max_solution_length(max_solution_length)
  {}

  virtual ~ACOParameters();

  double get_alpha() { return alpha; }
  double get_beta()  { return beta; }
  double get_gamma() { return gamma; }
  unsigned get_number_of_ants() { return number_of_ants; }
  unsigned get_max_solution_length() { return max_solution_length; }
};

#endif
