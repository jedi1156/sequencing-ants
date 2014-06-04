#include "aco_parallel_strategy.hpp"

ACOParallelStrategy::ACOParallelStrategy(ACOParameters *params)
: ACOStrategy(params)
{}

void ACOParallelStrategy::setup_optimization() {
  start = false;

  for (unsigned i = 0, len = ants.size(); i < len; ++i) {
    AntThread *ant_thread = new AntThread(this, ants[i]);
    threads.push_back(ant_thread);
    ant_thread->start();
  }
}

void ACOParallelStrategy::finish_optimization() {
  wake_up_threads();

  for (unsigned i = 0, len = threads.size(); i < len; ++i) {
    threads[i]->join();
  }
}

void ACOParallelStrategy::iteration() {
  wake_up_threads();

  unique_lock<mutex> lck(ready_mutex);
  for (unsigned i = 0, len = threads.size(); i < len; ++i) {
    while (!threads[i]->is_ready()) { ready_condition.wait(lck); }
  }
}

void ACOParallelStrategy::notify() {
  ready_condition.notify_one();
}

void ACOParallelStrategy::wake_up_threads() {
  for (unsigned i = 0, len = threads.size(); i < len; ++i) {
    threads[i]->unready();
  }
  start = true;
  start_condition.notify_all();
}

void ACOParallelStrategy::wait_until_start() {
  unique_lock<mutex> lck(start_mutex);
  while (!start) { start_condition.wait(lck); }
}
