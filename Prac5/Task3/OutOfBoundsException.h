#include "Exception.h"

class OutOfBoundsException : public Exception {
public:
  OutOfBoundsException() : Exception("Index out of bounds!") {}
};
