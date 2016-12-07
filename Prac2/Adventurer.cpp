/*
 * Copyright (c) 2016, Thomas Scholtz
 * All rights reserved.
 */
#include "Adventurer.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

// Implement or define your class here
Adventurer::Adventurer() {
  Adventurer::numberOfAdventurers++;
  this->items = 0;
  this->currentNumberOfItems = 0;
  this->currentCarryWeight = 0.0;
  this->maxCarryWeight = 0;
  this->maxNumberOfItems = 0;
  this->health = 0;
  this->name = "";
} // default constructor

Adventurer::Adventurer(const Adventurer &a) {
  Adventurer::numberOfAdventurers++;

  this->items = 0;

  this->setName(a.getName());
  this->setHealth(a.getHealth());
  this->setMaxCarryWeight(a.getMaxCarryWeight());
  this->setMaxNumberOfItems(a.getMaxNumberOfItems());
  this->setCurrentCarryWeight(a.getCurrentCarryWeight());
  this->setCurrentNumberOfItems(a.getCurrentNumberOfItems());
  // this->items = a.items;
  // Copy all items
  cout << "Copying items" << endl;
  memcpy(this->items, *a.items, a.getMaxNumberOfItems() * sizeof(string));

  //
} // copy constructor

Adventurer::~Adventurer() {
  cout << "DESTRUCT" << endl;
  for (int i = 0; i < this->getCurrentNumberOfItems(); i++) {
    delete[] this->items[i];
    // delete this->items[i][1];
  }

  this->items = 0;

  Adventurer::numberOfAdventurers--;
}

void resizeArr(int oldSize, int newSize, string ***&arr) {

  cout << "Redo Array" << endl;

  string ***newArr = new string **[newSize];

  // cout << "LOOP" << endl;
  // cout << oldSize << endl;
  // cout << newSize << endl;
  for (int i = 0; i < oldSize; i++) {
    newArr[i] = arr[i];
  }
  // cout << "DEL" << endl;
  delete[] arr;
  // cout << "REASSIGN" << endl;
  arr = newArr;

  cout << "redo done" << endl;
}

bool deleteItem(int index, int size, string ***&arr) {
  delete[] arr[index];
  // HEIGHT, ROWS, COLUMNS(pointers to strings)
  string ***newArr = new string **[size - 1];

  for (size_t i = 0; i < size; i++) {
    if (arr[i] != 0) {
      newArr[i] = arr[i];
    }
  }

  delete[] arr;

  arr = newArr;

  return true;
}

bool Adventurer::pickUpItem(string it, double weight) {
  // Check if the player can carry more items.
  if ((currentCarryWeight + weight) > maxCarryWeight ||
      (currentNumberOfItems + 1) > (maxNumberOfItems)) {
    return false;
  } else {
    // Resize the Array.

    // resizeArr(this->getCurrentNumberOfItems(),
    // (this->getCurrentNumberOfItems() + 1), (this->items));
    this->setCurrentNumberOfItems(this->getCurrentNumberOfItems() + 1);

    (this->items)[this->getCurrentNumberOfItems() - 1] = new string *[2];

    (this->items)[this->getCurrentNumberOfItems() - 1][0] = new string(it);

    string str_weight = to_string(weight);

    (this->items)[this->getCurrentNumberOfItems() - 1][1] =
        new string(str_weight);
    return true;
  }
}
bool Adventurer::dropItem(string it) {
  for (size_t i = 0; i < this->getCurrentNumberOfItems(); i++) {
    if (it.compare(*this->items[i][0])) {
      if (deleteItem(i, this->getCurrentNumberOfItems(), this->items)) {
        this->setCurrentNumberOfItems(this->getCurrentNumberOfItems() - 1);
        return true;
      }
    }
  }
  return false;
}
bool Adventurer::dropItem(int index) {
  if (this->items[index]) {
    if (deleteItem(index, this->getCurrentNumberOfItems(), this->items)) {
      this->setCurrentNumberOfItems(this->getCurrentNumberOfItems() - 1);
      return true;
    }
  }
  return false;
}
void Adventurer::setName(string n) { this->name = n; }
string Adventurer::getName() const { return this->name; }
void Adventurer::setMaxCarryWeight(double w) { this->maxCarryWeight = w; }
double Adventurer::getMaxCarryWeight() const { return this->maxCarryWeight; }
void Adventurer::setCurrentCarryWeight(double w) {
  this->currentCarryWeight = w;
}
double Adventurer::getCurrentCarryWeight() const {
  return this->currentCarryWeight;
}
void Adventurer::setMaxNumberOfItems(int n) {
  resizeArr(this->maxNumberOfItems, n, this->items);

  this->maxNumberOfItems = n;
}
int Adventurer::getMaxNumberOfItems() const { return this->maxNumberOfItems; }
void Adventurer::setCurrentNumberOfItems(int n) {
  this->currentNumberOfItems = n;
}
int Adventurer::getCurrentNumberOfItems() const {
  return this->currentNumberOfItems;
}
int Adventurer::getNumberOfAdventurers() const { return numberOfAdventurers; }
void Adventurer::setHealth(double h) { this->health = h; }
double Adventurer::getHealth() const { return this->health; }
string **Adventurer::getItem(int index) const { return (this->items)[index]; }

// Copy.
Adventurer &Adventurer::operator=(const Adventurer &a) {

  cout << "CALLED operator" << endl;

  Adventurer::numberOfAdventurers++;

  this->items = 0;

  this->setName(a.getName());
  this->setHealth(a.getHealth());
  this->setMaxCarryWeight(a.getMaxCarryWeight());
  this->setMaxNumberOfItems(a.getMaxNumberOfItems());
  this->setCurrentCarryWeight(a.getCurrentCarryWeight());
  this->setCurrentNumberOfItems(a.getCurrentNumberOfItems());

  memcpy(this->items, *a.items, a.getMaxNumberOfItems() * sizeof(string));
}
