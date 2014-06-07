#ifndef _INCLUDE_ANT_THREAD_HPP
#define _INCLUDE_ANT_THREAD_HPP

#include "common.hpp"
#include "notifiable.hpp"
#include "ant.hpp"
#include "worker.hpp"

class AntThread : public Worker {
private:
  Notifiable *listener;
  Ant *ant;
  bool ready;
  thread th;

  void routine();
  void wait_until_start();
public:
  AntThread(Notifiable *listener, Ant *ant);
  void start();
  void join();

  bool is_ready() { return ready; }
  void unready() { ready = false; }
};

#endif
