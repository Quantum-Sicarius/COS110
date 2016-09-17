#include "Exception.h"

class EmptyException: public Exception {
public:
  EmptyException() : Exception("The string is empty!") {}
};
