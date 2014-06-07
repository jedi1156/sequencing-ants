#ifndef _INCLUDE_ACO_PARALLEL_STRATEGY_HPP
#define _INCLUDE_ACO_PARALLEL_STRATEGY_HPP

#include "common.hpp"
#include "aco_strategy.hpp"
#include "ant_thread.hpp"
#include "worker.hpp"

class ACOParallelStrategy : public ACOStrategy, public Notifiable {
private:
  vector<AntThread*> threads;

  mutex ready_mutex;
  condition_variable start_condition;
  condition_variable ready_condition;

  void wake_up_threads();
  void wait_for_all();

protected:
  void setup_optimization();
  void iteration();

public:
  ACOParallelStrategy(ACOParameters *params);

  void finish_optimization();

  void notify();
  void wait_until_start(Worker *worker);

  bool is_working() { return ACOStrategy::is_working(); }
};

#endif
