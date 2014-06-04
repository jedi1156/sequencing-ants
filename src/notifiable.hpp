#ifndef _INCLUDE_NOTIFIABLE_HPP
#define _INCLUDE_NOTIFIABLE_HPP

class Notifiable {
public:
  virtual void notify() = 0;
  virtual void wait_until_start() = 0;
};

#endif
