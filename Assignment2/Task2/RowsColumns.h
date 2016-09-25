#ifndef RowsColumns_H
#define RowsColumns_H

#include "TranspositionCipher.h"

class RowsColumns : public TranspositionCipher {
public:
  std::string encode(std::string);
  std::string decode(std::string);
};

#endif
