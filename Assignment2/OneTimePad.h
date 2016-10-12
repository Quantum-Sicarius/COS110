#include "Caesar.h"

class OneTimePad : public Caesar {
protected:
  long int seed;
public:
  OneTimePad(long int);
  void setSeed(long int);
  char encodeChar(char);
  char decodeChar(char);
  std::string encode(std::string);
  std::string decode(std::string);
};
