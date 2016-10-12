#ifndef SubstitutionCipher_H
#define SubstitutionCipher_H

#include "Cipher.h"

class SubstitutionCipher : public Cipher {
public:
  std::string encode(std::string s);
  std::string decode(std::string s);
  virtual char encodeChar(char c) = 0;
  virtual char decodeChar(char c) = 0;
};

#endif
