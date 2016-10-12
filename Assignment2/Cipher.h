#ifndef CIPHER_H
#define CIPHER_H

#include <string>
#include <vector>

class Cipher {
public:
  virtual std::string encode(std::string s) = 0;
  virtual std::string decode(std::string s) = 0;
};

#endif
