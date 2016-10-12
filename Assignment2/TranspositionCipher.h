#ifndef TranspositionCipher_H
#define TranspositionCipher_H

#include "Cipher.h"

class TranspositionCipher : public Cipher {
protected:
  virtual char ** createMatrix(int);
  virtual void deleteMatrix(char **, int);
  virtual void fillMatrix(char **, int, std::string);
  virtual int calculateSide(int);
};

#endif
