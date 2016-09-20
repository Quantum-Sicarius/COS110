#ifndef EmptyResultException_H
#define EmptyResultException_H

#include "Exception.h"

class EmptyResultException: public Exception {
public:
  EmptyResultException() : Exception("The result is an empty string!") {}
};

#endif
