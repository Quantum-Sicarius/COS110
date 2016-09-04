#include "library.h"

void redoArray(Book** &books, int oldS, int newS) {
        Book** newBooks = new Book*[newS];

        for (int i = 0; i < oldS; i++) {
                newBooks[i] = books[i];
        }

        delete [] books;
        books = newBooks;
}

Library::Library(Library &l) {
        this->name = l.name;
        this->librarySize = l.librarySize;
        this->numBooks = l.numBooks;

        this->books = new Book*[librarySize];

        // Copy all books.
        for (int i = 0; i < this->numBooks; i++) {
                this->books[i] = l.books[i];
        }
}

Library& Library::operator+=(Book &b) {
        this->books[this->numBooks] = &b;
        this->numBooks++;
        return *this;
}
Library& Library::operator-=(Book &b) {
        for (int i = 0; i < this->numBooks; i++) {
                if (this->books[i] == &b) {
                        this->books[i] = 0;
                        this->numBooks--;
                        return *this;
                }
        }

        return *this;
}
Library& Library::operator=(Library l) {
        return *this;
}
Library& Library::operator++(int) {
        this->librarySize = this->librarySize + 1;
        redoArray(this->books, (this->librarySize - 1), this->librarySize);
        return *this;
}
Library& Library::operator--() {
        this->librarySize--;
        // Check on this.
        redoArray(this->books, (this->librarySize + 1), this->librarySize);
        return *this;
}

Book* Library::getBook(string s) {
        for (int i = 0; i < this->numBooks; i++) {
                Book* currentBook = this->books[i];
                if (currentBook->getTitle() == s) {
                        return currentBook;
                }
        }

        return 0;
}
bool Library::isFull() {
        if (this->numBooks == this->librarySize) {
                return true;
        }

        return false;
}
void Library::print() {
        cout << this->name << endl;
        cout << "===================================" << endl;
        if (this->numBooks == 0) {
                cout << "[EMPTY]" << endl;
        } else {
                for (int i = 0; i < this->librarySize; i++) {
                        if (this->books[i] != 0) {
                                cout << (i + 1) << ". " << *(this->books[i]) << endl;
                        } else {
                                cout << (i + 1) << ". " << "[EMPTY SPACE]" << endl;
                        }

                }
        }

        cout << "===================================" << endl;
}
