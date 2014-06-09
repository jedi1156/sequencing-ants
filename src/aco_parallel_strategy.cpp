#include "aco_parallel_strategy.hpp"

extern int debug;

ACOParallelStrategy::ACOParallelStrategy(ACOParameters *params)
: ACOStrategy(params)
, working(true)
, ready_mutex()
, start_condition()
, ready_condition()
{}

void ACOParallelStrategy::setup_optimization() {
  for (unsigned i = 0, len = ants.size(); i < len; ++i) {
    AntThread *ant_thread = new AntThread(this, ants[i]);
    threads.push_back(ant_thread);
    ant_thread->start();
  }
  working = ACOStrategy::is_working();
}

void ACOParallelStrategy::finish_optimization() {
  if (debug >= 3) { cout << "Parallel finishing optimization" << endl; }
  working = false;
  wake_up_threads();

  wait_for_all();
  for (unsigned i = 0, len = threads.size(); i < len; ++i) {
    threads[i]->join();
    if (debug >= 5) { cout << "Parallel joined #" << i << endl; }
  }
  if (debug >= 5) { cout << "Parallel joined all" << endl; }
}

void ACOParallelStrategy::iteration() {
  if (debug >= 5) { cout << "Parallel iteration> before waking up" << endl; }
  wake_up_threads();

  if (debug >= 5) { cout << "Parallel iteration> before locking" << endl; }
  wait_for_all();
}

void ACOParallelStrategy::wait_for_all() {
  unique_lock<mutex> lck(ready_mutex);
  for (unsigned i = 0, len = threads.size(); i < len; ++i) {
    if (debug >= 5) { cout << "Parallel iteration> checking ready #" << i << endl; }
    while (!threads[i]->is_ready()) { ready_condition.wait(lck); }
  }
}

void ACOParallelStrategy::notify() {
  ready_condition.notify_one();
}

void ACOParallelStrategy::wake_up_threads() {
  unique_lock<mutex> lck(ready_mutex);
  for (unsigned i = 0, len = threads.size(); i < len; ++i) {
    threads[i]->unready();
  }
  start_condition.notify_all();
}

void ACOParallelStrategy::wait_until_start(Worker *worker) {
  if (debug >= 5) { cout << "Parallel wait_until_start> before" << endl; }
  unique_lock<mutex> lck(ready_mutex);
  while (worker->is_ready()) { start_condition.wait(lck); }
  if (debug >= 5) { cout << "Parallel wait_until_start> woken up" << endl; }
}
