#ifndef OutOfBoundsException_H
#define OutOfBoundsException_H

#include "Exception.h"

class OutOfBoundsException : public Exception {
public:
  OutOfBoundsException() : Exception("Index out of bounds!") {}
};

#endif
