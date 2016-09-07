#ifndef BACKWARDS_H
#define BACKWARDS_H
#include "filter.h"

class backwards: public filter {
public:
  std::string print(std::string s);
};
#endif
