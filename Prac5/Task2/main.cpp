#include "CharString.h"
#include <iostream>

int main() {

        std::string str = "bananna";
        char *cstr = &str[0u];

        CharString first(cstr, 7);

        cout << "Testing -operator: " << endl;
        cout << "Result: " << (first-'a') << endl;

        return 0;
}
