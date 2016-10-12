#ifndef CipherPipeline_H
#define CipherPipeline_H

#include "Cipher.h"
#include <vector>

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
