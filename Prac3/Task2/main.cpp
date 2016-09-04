#include "library.h"
#include "../Task1/book.h"
#include <assert.h>     /* assert */
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
        Library *lib = new Library("UP");

        Book *b = new Book("Starting Out with C++","Tony Gaddis","987646725348");
        Book *b2 = new Book("BOOK2","JAN PIET","987646725348");
        Book *b3 = new Book("BOOK3","JOHN SMITH","987646725348");
        Book *b4 = new Book("BOOK4","RAY JOHNSON","987646725348");

        *lib += *b;

        lib->print();

        // Test copy.

        cout << "Testing copy constructor..." << endl;
        Library *lib2 = new Library(*lib);

        lib2->print();

        cout << "Testing increase size..." << endl;
        (*lib2)++;

        cout << "Result:" << endl;
        lib2->print();

        *lib2 += *b2;
        *lib2 += *b3;
        *lib2 += *b4;

        lib2->print();

        cout << "Test remove book..." << endl;

        *lib2 -= *b3;

        cout << "Result: " << endl;

        lib2->print();

        cout << "Testing decrease size..." << endl;

        --(*lib2);

        cout << "Result:" << endl;
        lib2->print();

        cout << "Testing decrease size 2..." << endl;

        --(*lib2);

        cout << "Result:" << endl;
        lib2->print();

        cout << "Testing decrease size 3..." << endl;

        --(*lib2);

        cout << "Result:" << endl;
        lib2->print();

        cout << "Testing decrease size 4..." << endl;

        --(*lib2);

        cout << "Result:" << endl;
        lib2->print();

        cout << "Testing add book with no space..." << endl;

        *lib2 += *b4;

        cout << "Result:" << endl;
        lib2->print();


        cout << "Testing assingment operator..." << endl;

        Library *lib3 = new Library("UP3");
        *lib3 = *lib2;

        cout << "Result: " << endl;

        lib3->print();


        return 0;
}
