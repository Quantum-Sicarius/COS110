#ifndef CharacterNotFoundException_H
#define CharacterNotFoundException_H

#include "Exception.h"

class CharacterNotFoundException : public Exception {
public:
  CharacterNotFoundException(std::string s) : Exception("No character '" + s + "' found!") {}
  CharacterNotFoundException() : Exception("No character found!") {}
};

#endif
