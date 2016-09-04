#include <string>
#include "../Task1/book.h"

using namespace std;

class Library {
  string name;
  Book** books;
  int librarySize;
  int numBooks;

public:
  Library(string n): name(n), books(0), librarySize(5), numBooks(0) {
    books = new Book*[5];
  }
  Library(Library &l);
  ~Library();

  Library& operator+=(Book &b);
  Library& operator-=(Book &b);
  Library& operator=(Library l);
  Library& operator++(int);
  Library& operator--();

  Book* getBook(string);
  bool isFull();
  void print();
};
