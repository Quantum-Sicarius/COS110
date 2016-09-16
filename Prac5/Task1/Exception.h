#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>

class Exception {
public:
  Exception();
  Exception(std::string s);
  ~Exception() {}
  std::string what();
private:
  std::string exception;
};
#endif
