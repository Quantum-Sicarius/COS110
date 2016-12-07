/*
 * Copyright (c) 2016, Thomas Scholtz
 * All rights reserved.
*/
#include "RowsColumns.h"
#include <sstream>

std::string RowsColumns::encode(std::string s) {
  int size = this->calculateSide(s.length());
  char **arr = this->createMatrix(size);
  this->fillMatrix(arr, size, s);

  std::stringstream result;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      result << arr[j][i];
    }
  }
  this->deleteMatrix(arr, size);
  return result.str();
}
std::string RowsColumns::decode(std::string s) {
  try {
    int size = this->calculateSide(s.length());

    unsigned long totalSize = size * size;

    if (s.length() < totalSize) {
      throw "Incompatible text length";
    }

    char **arr = this->createMatrix(size);
    this->fillMatrix(arr, size, s);

    std::stringstream result;

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        result << arr[j][i];
      }
    }
    this->deleteMatrix(arr, size);
    return result.str();
  } catch (char const *err) {
    return err;
  }
}
