#include "exception.h"
#include <iostream>

using namespace std;

int main() {
        try {
                throw Exception ("Test Exception");
        } catch (Exception e) {
                cout << e.what() << endl;
        }
        return 0;
}