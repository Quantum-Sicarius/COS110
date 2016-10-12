#ifndef CipherPipeline_H
#define CipherPipeline_H

#include "Cipher.h"
#include <vector>

std::vector<Cipher*> operator+(Cipher &lhs, Cipher &rhs);

class CipherPipeline {
private:
  std::vector<Cipher*> pipeline;
public:
  std::string encode(std::string);
  std::string decode(std::string);

  CipherPipeline& operator+=(Cipher*);
  CipherPipeline& operator+=(std::vector<Cipher*>);
  CipherPipeline& operator=(std::vector<Cipher*>);
};

#endif
