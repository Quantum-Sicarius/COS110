#include "TranspositionCipher.h"
#include <math.h>
/*
   This function creates a square (width == height) matrix of
   characters. The int parameter specifies the matrix side (width, height).
   Since matrix is a
   2D structure, a 2D array of char type is dynamically allocated and returned.
   Characters
   are not initialized – this function simply creates an empty structure and
   returns it.
 */
char **TranspositionCipher::createMatrix(int size) {
  char **c = new char *[size];
  for (int i = 0; i < size; i++) {
    c[i] = new char[size];
  }
  return c;
}

void TranspositionCipher::deleteMatrix(char **arr, int size) {
  for (int i = 0; i < size; i++) {
    delete[] arr[i];
  }

  delete[] arr;
}

void TranspositionCipher::fillMatrix(char **arr, int size, std::string s) {
  size_t length = 0;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (length != s.length()) {
        arr[i][j] = s[length];
        ++length;
      } else {
        arr[i][j] = ' ';
      }
    }
  }
}

int TranspositionCipher::calculateSide(int stringLength) {
  return (ceil(sqrt(stringLength)));
}
