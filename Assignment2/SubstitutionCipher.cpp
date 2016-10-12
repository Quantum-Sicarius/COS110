#include "SubstitutionCipher.h"
#include <sstream>

std::string SubstitutionCipher::encode(std::string s) {
  std::stringstream result;
  result.str("");

  for (size_t i = 0; i < s.length(); i++) {
    result << encodeChar(s[i]);
  }

  return result.str();
}
std::string SubstitutionCipher::decode(std::string s) {
  std::stringstream result;
  result.str("");

  for (size_t i = 0; i < s.length(); i++) {
    result << decodeChar(s[i]);
  }

  return result.str();
}
