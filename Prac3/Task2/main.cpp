#include "library.h"
#include "../Task1/book.h"
#include <assert.h>     /* assert */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
        Library *lib = new Library("UP");
        Book *b = new Book("Starting Out with C++","Tony Gaddis","987646725348");

        *lib += *b;

        lib->print();

        // Test copy.

        Library *lib2 = new Library(*lib);

        lib2->print();

        cout << "Testing increase size..." << endl;
        lib2++;

        lib2->print();

        return 0;
}
