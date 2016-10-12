#include "Caesar.h"
#include <iostream>

Caesar::Caesar() { this->shift = 0; }

void Caesar::setShift(int i) {
  try {
    if (i <= 0) {
      throw "Please provide a positive shift value";
    } else if (i > 94) {
      throw "Maximum shift is 94 for ASCII, please try again";
    }
    this->shift = i;
  } catch (char const *err) {
    std::cout << err << std::endl;
    int input;
    std::cin >> input;
    this->setShift(input);
  }
}
/*
 * We will limit the available range of codes to [32,126].
 */
char Caesar::encodeChar(char c) {
  if (this->shift == 0) {
    this->setShift(this->shift);
  }

  int val = int(c);
  val += this->shift;

  if (val > 126) {
    return ((val - 126) + 31);
  }
  return val;
}
char Caesar::decodeChar(char c) {

  int val = int(c);
  val -= this->shift;

  if (val < 32) {
    return (127 + (val - 32));
  }

  return val;
}

std::string Caesar::encode(std::string s) {
  return SubstitutionCipher::encode(s);
}
std::string Caesar::decode(std::string s) {
  return SubstitutionCipher::decode(s);
}
