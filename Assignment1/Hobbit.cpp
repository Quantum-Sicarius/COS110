#include "Hobbit.h"

Hobbit::Hobbit() {

}

Hobbit::~Hobbit() {

}

void Hobbit::setName(string n) {
        this->name = n;
}

string Hobbit::getName() const {
        return this->name;
}
