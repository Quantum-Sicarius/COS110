#include "RowsColumns.h"

std::string RowsColumns::encode(std::string s) {
        int size = this->calculateSide(s.length());
        char** arr = this->createMatrix(size);
        this->fillMatrix(arr, size, s);

        std::string result;

        for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                        result += arr[j][i];
                }
        }
        this->deleteMatrix(arr, size);
        return result;

}
std::string RowsColumns::decode(std::string s) {
        int size = this->calculateSide(s.length());
        char** arr = this->createMatrix(size);
        this->fillMatrix(arr, size, s);

        std::string result;

        for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                        result += arr[j][i];

                }
        }
        this->deleteMatrix(arr, size);
        return result;
}
