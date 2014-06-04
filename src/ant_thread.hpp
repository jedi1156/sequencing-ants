#ifndef _INCLUDE_ANT_THREAD_HPP
#define _INCLUDE_ANT_THREAD_HPP

#include "common.hpp"
#include "notifiable.hpp"
#include "ant.hpp"

class AntThread {
private:
  Notifiable *listener;
  Ant *ant;
  bool ready;
  thread th;

  void routine();
  void wait_until_start();
public:
  AntThread(Notifiable *listener, Ant *ant);
  bool is_ready() { return ready; }
  void join();

  void unready() { ready = false; }
};

#endif
