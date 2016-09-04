#include "book.h"
#include "iostream"

int main(int argc, char const *argv[]) {

        Book *b = new Book("Starting Out with C++","Tony Gaddis","987646725348");

        cout << "BOOK: " << *b << endl;

        return 0;
}
