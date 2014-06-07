#ifndef _INCLUDE_NOTIFIABLE_HPP
#define _INCLUDE_NOTIFIABLE_HPP

#include "worker.hpp"

class Notifiable {
public:
  virtual void notify() = 0;
  virtual void wait_until_start(Worker *worker) = 0;
  virtual bool is_working() = 0;
};

#endif
