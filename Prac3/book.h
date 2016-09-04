/*
 * Book class.
 */

#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>

using namespace std;

class Book {
private:
string title, author, ISBN, genre;

public:
Book() {}
Book(string t, string a, string i): title(t), author(a), ISBN(i) {}

string getTitle();
string getAuthor();
string getISBN();
string getGenre();
void setTitle(string a);
void setAuthor(string a);
void setISBN(string a);
void setGenre(string a);

// Overite operator.
friend ostream& operator<<(ostream& os, Book& b);

};

#endif
