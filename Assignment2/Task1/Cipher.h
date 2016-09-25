#ifndef CIPHER_H
#define CIPHER_H

#include <string>

class Cipher {
public:
  std::string encode(std::string s);
  std::string decode(std::string s);
};

#endif
