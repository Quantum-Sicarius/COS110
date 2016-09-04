#include <string>
#include "book.h"
#include <iostream>

using namespace std;

class Library {
  string name;
  Book** books;
  int librarySize;
  int numBooks;

public:
  Library(){
    name = "";
    librarySize = 5;
    numBooks = 0;
    books = new Book*[5];
  }
  Library(string n): name(n), books(0), librarySize(5), numBooks(0) {
    books = new Book*[5];
  }
  Library(const Library&);
  ~Library();

  Library operator+=(Book* b);
  Library operator-=(Book* b);
  Library& operator=(const Library &l);
  Library& operator++(int);
  Library& operator--();

  Book* getBook(string);
  bool isFull();
  void print();
  string getName();
  void setName(string s);
};
