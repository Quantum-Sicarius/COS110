#include "OneTimePad.h"
#include <stdlib.h> /* srand, rand */

OneTimePad::OneTimePad(long int i) {
  this->seed = i;
  srand(this->seed);
}

void OneTimePad::setSeed(long int i) {
  this->seed = i;
  srand(this->seed);
}

char OneTimePad::encodeChar(char c) {
  this->setShift(rand() % 94 + 1);

  int val = int(c);
  val += this->shift;

  if (val > 126) {
    return ((val - 126) + 31);
  }
  return val;
}

char OneTimePad::decodeChar(char c) {
  this->setShift(rand() % 94 + 1);

  int val = int(c);
  val -= this->shift;

  if (val < 32) {
    return (127 + (val - 32));
  }

  return val;
}

std::string OneTimePad::encode(std::string s) {
  srand(this->seed);
  return SubstitutionCipher::encode(s);
}

std::string OneTimePad::decode(std::string s) {
  srand(this->seed);
  return SubstitutionCipher::decode(s);
}
