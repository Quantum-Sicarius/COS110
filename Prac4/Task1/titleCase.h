#ifndef TITLECASE_H
#define TITLECASE_H
#include "filter.h"

class titleCase: public filter {
public:
  std::string print(std::string s);
};

#endif
