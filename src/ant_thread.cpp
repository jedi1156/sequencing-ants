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
  ready = true;
  listener->notify();
}

void AntThread::wait_until_start() {
  listener->wait_until_start(this);
}

void AntThread::start() {
  th = thread(&AntThread::routine, this);
}

void AntThread::join() {
  th.join();
}
