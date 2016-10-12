#ifndef ZigZag_H
#define ZigZag_H

#include "TranspositionCipher.h"

class ZigZag : public TranspositionCipher {
public:
  std::string encode(std::string);
  std::string decode(std::string);
};

#endif
