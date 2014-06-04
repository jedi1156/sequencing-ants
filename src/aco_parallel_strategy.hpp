#ifndef _INCLUDE_ACO_PARALLEL_STRATEGY_HPP
#define _INCLUDE_ACO_PARALLEL_STRATEGY_HPP

#include "common.hpp"
#include "aco_strategy.hpp"
#include "ant_thread.hpp"

class ACOParallelStrategy : public ACOStrategy, public Notifiable {
private:
  vector<AntThread*> threads;

  bool start;
  condition_variable<mutex> start_condition;
  condition_variable<mutex> ready_condition;
  mutex start_mutex;
  mutex ready_mutex;

  void wake_up_threads();

protected:
  void setup_optimization();
  void iteration();

public:
  void finish_optimization();

  void notify();
  void wait_until_start();
};

#endif
