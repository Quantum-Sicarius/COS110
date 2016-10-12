#include "ZigZag.h"
#include <sstream>

std::string ZigZag::encode(std::string s) {
  int size = this->calculateSide(s.length());
  char **arr = this->createMatrix(size);
  this->fillMatrix(arr, size, s);

  std::stringstream result;
  bool flip = true;

  for (int i = 0; i < size; i++) {
    if (flip) {
      for (int j = 0; j < size; j++) {
        result << arr[j][i];
      }
      flip = false;
    } else {
      for (int j = size - 1; j >= 0; j--) {
        result << arr[j][i];
      }
      flip = true;
    }
  }
  this->deleteMatrix(arr, size);
  return result.str();
}

void ZigZagDecode(std::string s, char **&arr, int size) {
  int counter = 0;
  bool flip = true;

  for (int i = 0; i < size; i++) {
    if (flip) {
      for (int j = 0; j < size; j++) {
        arr[j][i] = s[counter];
        ++counter;
      }
      flip = false;
    } else {
      for (int j = size - 1; j >= 0; j--) {
        arr[j][i] = s[counter];
        ++counter;
      }
      flip = true;
    }
  }
}

std::string ZigZag::decode(std::string s) {
  try {
    int size = this->calculateSide(s.length());

    unsigned long totalSize = size * size;

    if (s.length() < totalSize) {
      throw "Incompatible text length";
    }

    char **arr = this->createMatrix(size);
    ZigZagDecode(s, arr, size);

    std::stringstream result;

    // Read row wise.
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        result << arr[i][j];
      }
    }

    this->deleteMatrix(arr, size);
    return result.str();
  } catch (char const *err) {
    return err;
  }
}
