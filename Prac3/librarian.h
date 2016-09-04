#ifndef LIBRARIAN_H
#define LIBRARIAN_H
#include "library.h"
#include <string>
class Librarian {

private:
  Library &lib;
  const string name;
public:
  Librarian(Library &l, string n): lib(l), name(n) {}
  Book* lendBook(string name);
  void returnBook(Book* book);
};

#endif
