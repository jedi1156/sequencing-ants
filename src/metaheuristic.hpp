#ifndef _INCLUDE_METAHEURISTIC_HPP
#define _INCLUDE_METAHEURISTIC_HPP

class Metaheuristic {
private:
  bool working;

public:
  Metaheuristic() : working(true) {}
  virtual ~Metaheuristic() {}
  bool is_working() { return working; }
  void terminate() { working = false; }
  virtual void optimize() = 0;
};

#endif
