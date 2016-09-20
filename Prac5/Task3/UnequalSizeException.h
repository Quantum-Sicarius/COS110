#ifndef UnequalSizeException_H
#define UnequalSizeException_H

#include "Exception.h"

class UnequalSizeException : public Exception {
public:
  UnequalSizeException() : Exception("Strings are not the same size!") {}
};

#endif
