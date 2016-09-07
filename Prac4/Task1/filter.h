#ifndef FILTER_H
#define FILTER_H

#include <string>

class filter {
public:
  virtual std::string print(std::string s) = 0;
};

#endif
