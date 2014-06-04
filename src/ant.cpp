#include "ant.hpp"

Ant::Ant(Graph *graph, double alpha, double beta, double gamma, unsigned max_solution_length)
: graph(graph)
, alpha(alpha)
, beta(beta)
, gamma(gamma)
, max_solution_length(max_solution_length)
, generator()
{}


void Ant::traverse_graph() {
  bool term_condition = true;
  set_beginning_position();

  // create solution
  while(term_condition) {
    term_condition = term_condition && move();
  }
}



void Ant::set_beginning_position() {
  //this->current_node = ...
  vector<Node*> nodes = graph->get_nodes();
  vector<double> distribution;
  for(unsigned i = 0; i < nodes.size(); i++) {
    distribution.push_back(graph->rate_node_as_first(nodes[i]));
  }
  for (unsigned i = 1; i < nodes.size(); ++i) {
    distribution[i] += distribution[i - 1];
  }

  int choice = generator.roulette(distribution);
  this->current_node =  nodes[choice];
}

bool Ant::move() {
  Edge *chosen_edge = choose_edge();
  if (chosen_edge == NULL) return false;

  step(chosen_edge);
  return true;
}

void Ant::step(Edge *edge) {
  this->current_node = solution->add_edge(edge);

}

double Ant::heuristic_attrictiveness(Edge *choice) {
  unsigned no_visits = solution->get_no_visits(current_node);
  return max(0.0, 1 + choice->get_weight() - gamma * no_visits);
}

double Ant::probability_of_choice(Edge *choice) {
  return pow(choice->get_pheromones(), alpha) * pow(heuristic_attrictiveness(choice), beta);
}

bool Ant::can_choose_edge(Edge *edge) {
  return (solution->get_cummulated_length(edge) <= this->max_solution_length);
}

void Ant::filter_choices(vector<Edge *> &potential_choices) {
  unsigned i = this->current_node->get_index();
  for (unsigned j = 0, len = graph->get_size(); j < len; ++j) {
    Edge *edge = graph->get_edge(i, j);
    if (can_choose_edge(edge)) {
      potential_choices.push_back(edge);
    }
  }
}

Edge* Ant::choose_edge() {
  vector<Edge *> potential_choices;
  filter_choices(potential_choices);

  unsigned size = potential_choices.size();

  vector<double> distribution;
  distribution.reserve(size);
  for (unsigned i = 0; i < size; ++i) {
    distribution.push_back(probability_of_choice(potential_choices[i]));
  }

  for (unsigned i = 1; i < size; ++i) {
    distribution[i] += distribution[i - 1];
  }

  int choice = generator.roulette(distribution);
  if (choice < 0) return NULL;
  return potential_choices[choice];
}
