/*
 * Copyright (c) 2016, Thomas Scholtz
 * All rights reserved.
*/
#include "library.h"

void redoArray(Book** &books, int oldS, int newS, bool enlarge) {

        // DEBUG
        //cout << "OLDSIZE: " << oldS << " NEW SIZE:" << newS << endl;

        Book** newBooks = new Book*[newS];

        if (enlarge) {
                for (int i = 0; i < oldS; i++) {
                        if (books[i]) {
                                newBooks[i] = books[i];
                        } else {
                                newBooks[i] = 0;
                        }
                }
        } else {
                for (int i = 0; i < newS; i++) {
                        //cout << "BOOK: " << i << endl;
                        if (books[i]) {
                                newBooks[i] = books[i];
                        } else {
                                newBooks[i] = 0;
                        }
                }
        }

        delete [] books;
        books = newBooks;
}

Library::Library(const Library &l) {
        this->name = l.name;
        this->librarySize = l.librarySize;
        this->numBooks = l.numBooks;

        // DEBUG.
        //cout << this->librarySize << endl;
        //cout << this->numBooks << endl;

        //delete [] this->books;
        this->books = new Book*[this->librarySize];

        // Copy all books.
        for (int i = 0; i < this->librarySize; i++) {
                //cout << "BOOK: " << i << endl;

                if (l.books[i]) {
                        this->books[i] = new Book((l.books[i])->getTitle(), (l.books[i])->getAuthor(), (l.books[i])->getISBN());
                } else {
                        this->books[i] = 0;
                }

        }
}

Library::~Library() {
        for (int i = 0; i < this->numBooks; i++) {
                //delete this->books[i];
                this->books[i] = 0;
        }

        delete [] this->books;
}

string Library::getName() {
        return this->name;
}

void Library::setName(string s) {
        this->name = s;
}

Library Library::operator+=(Book* b) {
        if (this->isFull()) {
                cout << "Library is full!" << endl;
                return *this;
        }
        this->books[this->numBooks] = b;
        this->numBooks++;
        return *this;
}
Library Library::operator-=(Book* b) {
        for (int i = 0; i < this->numBooks; i++) {
                if (this->books[i] == b) {
                        this->books[i] = 0;
                        this->numBooks--;
                        return *this;
                }
        }

        return *this;
}
Library& Library::operator=(const Library &l) {
        this->name = l.name;
        this->librarySize = l.librarySize;
        this->numBooks = l.numBooks;

        // DEBUG.
        //cout << this->librarySize << endl;

        delete [] this->books;
        this->books = new Book*[this->librarySize];

        // Copy all books.
        for (int i = 0; i < this->librarySize; i++) {
                //cout << "BOOK: " << i << endl;

                if (l.books[i]) {
                        this->books[i] = l.books[i];
                } else {
                        this->books[i] = 0;
                }

        }
        return *this;
}
Library& Library::operator++(int) {
        // DEBUG
        //cout << "OPERATOR++ CALLED" << endl;
        this->librarySize++;
        redoArray(this->books, (this->librarySize) - 1, this->librarySize, true);
        return *this;
}
Library& Library::operator--() {
        this->librarySize--;
        if (this->numBooks > this->librarySize) {
                this->numBooks = this->librarySize;
        }
        // Check on this.
        redoArray(this->books, (this->librarySize) + 1, this->librarySize, false);
        return *this;
}

Book* Library::getBook(string s) {
        for (int i = 0; i < this->librarySize; i++) {
                if (this->books[i]) {
                        Book* currentBook = (this->books[i]);
                        if (currentBook->getTitle() == s) {
                                return currentBook;
                        }
                }

        }

        return NULL;
}
bool Library::isFull() {
        if (this->numBooks == this->librarySize) {
                return true;
        }

        return false;
}
void Library::print() {
        cout << "Inventory of " << this->name << ":"<< endl;
        cout << "===================================" << endl;
        if (this->numBooks == 0) {
                cout << "EMPTY" << endl;
        } else {
                for (int i = 0; i < this->librarySize; i++) {
                        if (this->books[i]) {
                                cout << (i + 1) << ". " << *(this->books[i]) << endl;
                        } else {
                                cout << (i + 1) << ". " << "[EMPTY SPACE]" << endl;
                        }

                }
        }

        cout << "==================================" << endl;
}
