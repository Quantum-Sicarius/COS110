#ifndef Caesar_H
#define Caesar_H

#include "SubstitutionCipher.h"

class Caesar : public SubstitutionCipher {
protected:
  int shift;
public:
  Caesar();
  void setShift(int);
  char encodeChar(char);
  char decodeChar(char);
  std::string encode(std::string s);
  std::string decode(std::string s);
};

#endif
