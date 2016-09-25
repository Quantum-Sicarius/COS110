#include "ZigZag.h"

std::string ZigZag::encode(std::string s) {
        int size = this->calculateSide(s.length());
        char** arr = this->createMatrix(size);
        this->fillMatrix(arr, size, s);

        std::string result;

        for (int i = 0; i < size; i++) {
                bool flip = false;

                if (flip) {
                        for (int j = 0; j < size; j++) {
                                result += arr[j][i];
                        }
                        flip = false;
                } else {
                        for (int j = size - 1; j >= 0; j--) {
                                result += arr[i][j];
                        }
                        flip = true;
                }

        }
        this->deleteMatrix(arr, size);
        return result;

}
std::string ZigZag::decode(std::string s) {
        int size = this->calculateSide(s.length());
        char** arr = this->createMatrix(size);
        this->fillMatrix(arr, size, s);

        std::string result;

        for (int i = 0; i < size; i++) {
                bool flip = false;

                if (flip) {
                        for (int j = 0; j < size; j++) {
                                result += arr[j][i];
                        }
                        flip = false;
                } else {
                        for (int j = size - 1; j >= 0; j--) {
                                result += arr[j][i];
                        }
                        flip = true;
                }
        }
        this->deleteMatrix(arr, size);
        return result;
}
