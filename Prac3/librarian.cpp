/*
 * Copyright (c) 2016, Thomas Scholtz
 * All rights reserved.
*/
#include "librarian.h"
Book* Librarian::lendBook(string name) {
        if(this->lib.getBook(name)) {
                Book* book = this->lib.getBook(name);
                cout << this->name << ": Here is the " << name << ", we hope you enjoy it!" << endl;
                this->lib-= book;
                return book;
        } else {
                cout << this->name << ": Sorry, we don’t have that book!" << endl;
                return NULL;
        }
}
void Librarian::returnBook(Book* book) {
        cout << this->name << ": Thanks for returning " << book->getTitle() << "!" << endl;
        (this->lib) += book;
}
