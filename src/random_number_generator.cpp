#include "random_number_generator.hpp"
#include <cstdlib>
#include <sys/time.h>

#define MAX_CALLS_BETWEEN_SRANDS 20

RandomNumberGenerator::RandomNumberGenerator()
: calls_left(0) {
}

void RandomNumberGenerator::seed_init() {
  struct timeval t;
  gettimeofday(&t, NULL);
  srand(t.tv_sec + t.tv_usec);
}

void RandomNumberGenerator::decrement_calls() {
  if (calls_left == 0) {
    seed_init();
    calls_left = rand() % MAX_CALLS_BETWEEN_SRANDS;
  } else {
    calls_left -= 1;
  }
}

int RandomNumberGenerator::random_int() {
  decrement_calls();
  return rand();
}

double RandomNumberGenerator::norm_random_double() {
  return (double)random_int() / RAND_MAX;
}

double RandomNumberGenerator::random(double from, double to) {
  return norm_random_double() * (to - from) + from;
}

int RandomNumberGenerator::roulette(vector<double> &distribution) {
  unsigned = distribution.size();
  if (size == 0) return -1;

  double choice = random(0, disteibution[size - 1]);

  for (unsigned i = 0; i < size; ++i) {
    if (choice < distribution[i]) return i;
  }

  return size - 1;
}
