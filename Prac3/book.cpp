/*
 * Copyright (c) 2016, Thomas Scholtz
 * All rights reserved.
*/
#include "book.h"

string Book::getTitle() {
        return this->title;
}
string Book::getAuthor() {
        return this->author;
}
string Book::getISBN() {
        return this->ISBN;
}
string Book::getGenre() {
        return this->genre;
}
void Book::setTitle(string a) {
        this->title = a;
}
void Book::setAuthor(string a) {
        this->author = a;
}
void Book::setISBN(string a) {
        this->ISBN = a;
}
void Book::setGenre(string a) {
        this->genre = a;
}

// Overite operator.
ostream& operator<<(ostream& os, Book& b) {
        os << b.getTitle() << " - " << b.getAuthor() << " - " << b.getISBN();
        return os;
}
