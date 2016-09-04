#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include "book.h"
#include <iostream>

using namespace std;

class Library {
  friend class Librarian;

private:
  string name;
  Book** books;
  int librarySize;
  int numBooks;
  Library operator+=(Book* b);
  Library operator-=(Book* b);
  Library& operator=(const Library &l);
  Library& operator++(int);
  Library& operator--();

public:
  Library(){
    name = "";
    librarySize = 5;
    numBooks = 0;
    books = new Book*[5];
  }
  Library(Library& lib, const string &name);
  Library(string n): name(n), books(0), librarySize(5), numBooks(0) {
    books = new Book*[5];
  }
  Library(const Library&);
  ~Library();

  Book* getBook(string);
  bool isFull();
  void print();
  string getName();
  void setName(string s);
};

#endif
