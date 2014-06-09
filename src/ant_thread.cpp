#include "ant_thread.hpp"

extern int debug;

AntThread::AntThread(Notifiable *listener, Ant *ant)
: listener(listener)
, ant(ant)
, ready(false)
, th() {
}

void AntThread::routine() {
  wait_until_start();
  while (listener->is_working()) {
    if (debug >= 6) { cout << "Ant thread> still working" << endl; }
    ant->traverse_graph();
    if (debug >= 6) { cout << "Ant thread> traversed" << endl; }
    ready = true;
    if (debug >= 6) { cout << "Ant thread> before notify" << endl; }
    listener->notify();
    if (debug >= 6) { cout << "Ant thread> notified" << endl; }
    wait_until_start();
    if (debug >= 6) { cout << "Ant thread> before check" << endl; }
  }
  ready = true;
  listener->notify();
  if (debug >= 5) { cout << "Ant thread> finished routine" << endl; }
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
