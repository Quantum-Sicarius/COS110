#ifndef TranspositionCipher_H
#define TranspositionCipher_H

#include "Cipher.h"

class TranspositionCipher : public Cipher {
protected:
  char ** createMatrix(int);
  void deleteMatrix(char **, int);
  void fillMatrix(char **, int, std::string);
  int calculateSide(int);
};

#endif
