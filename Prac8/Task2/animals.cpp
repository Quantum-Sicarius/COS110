#include "animals.h"
#include "iostream"

Animal::Animal(char const *name_) { this->name = name_; }
void Animal::detectHuman() {
  std::cout << Animal::name << " detected a human and is " << action()
            << std::endl;
}

TameAnimal::TameAnimal(char const *name_) : Animal(name_) {}

Bird::Bird(char const *name_) : Animal(name_) {}
Dog::Dog(char const *name_) : TameAnimal(name_) {}
Cat::Cat(char const *name_) : TameAnimal(name_) {}

char const *Bird::action() { return "flying away"; }
char const *Dog::action() { return "wagging its tail"; }
char const *Cat::action() { return "purring loudly"; }

void TameAnimal::detectHuman() {
  std::cout << Animal::name << " is looking for cuddles while " << action()
            << std::endl;
}
