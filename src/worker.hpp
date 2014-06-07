#ifndef _INCLUDE_WORKER_HPP
#define _INCLUDE_WORKER_HPP

class Worker {
public:
  virtual bool is_ready() = 0;
};

#endif
