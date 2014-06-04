#include "ant_thread.hpp"

AntThread::AntThread(Notifiable *listener, Ant *ant)
: listener(listener)
, ant(ant)
, ready(false)
, th() {
}

void AntThread::routine() {
  wait_until_start();
  while (listener->is_working()) {
    ant->traverse_graph();
    ready = true;
    listener->notify();
    wait_until_start();
  }
}

void AntThread::wait_until_start() {
  listener->wait_until_start();
}

void AntThread::start() {
  th = thread(&AntThread::routine, this);
}

void AntThread::join() {
  th.join();
}
