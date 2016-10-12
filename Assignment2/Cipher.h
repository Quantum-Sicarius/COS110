#ifndef CIPHER_H
#define CIPHER_H

#include <string>
#include <vector>

class Cipher {
public:
  virtual std::string encode(std::string s) = 0;
  virtual std::string decode(std::string s) = 0;

  std::vector<Cipher *> operator+(Cipher &right) {
    std::vector<Cipher *> *result = new std::vector<Cipher *>();
    result->clear();
    result->push_back(&right);
    result->push_back(this);
    return *result;
  }
};

#endif
