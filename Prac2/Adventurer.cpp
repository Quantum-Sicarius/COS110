#include "Adventurer.h"
#include <iostream>
//Implement or define your class here
Adventurer::Adventurer() {
        //this->items;
        this->currentNumberOfItems = 0;
        this->currentCarryWeight = 0.0;
} //default constructor

Adventurer::Adventurer(const Adventurer &a) {
        Adventurer* copy = new Adventurer;
        copy->setName(a.getName());
        copy->setHealth(a.getHealth());
        copy->setMaxCarryWeight(a.getMaxCarryWeight());
        copy->setMaxNumberOfItems(a.getMaxNumberOfItems());
        copy->setCurrentCarryWeight(a.getCurrentCarryWeight());
        copy->setCurrentNumberOfItems(a.getCurrentNumberOfItems());
}  //copy constructor
Adventurer::~Adventurer() {
        //delete &health;
        //delete &maxCarryWeight;
        //delete &maxNumberOfItems;
        //delete &currentCarryWeight;
        //delete &currentNumberOfItems;
        //delete &name;
}

void resizeArr(int oldSize, int newSize, string*** &arr) {

        cout << "Redo Array" << endl;

        string ***newArr = new string**[newSize];

        cout << "LOOP" << endl;
        cout << oldSize << endl;
        for (int i = 0; i < oldSize; i++) {
                newArr[i] = arr[i];
        }
        cout << "DEL" << endl;
        delete [] arr;
        cout << "REASSIGN" << endl;
        arr = newArr;
}


bool Adventurer::pickUpItem(string it, double weight) {
        // Check if the player can carry more items.
        if ((currentCarryWeight + weight) > maxCarryWeight || (currentNumberOfItems + 1) > (maxNumberOfItems)) {
                return false;
        } else {
                // Resize the Array.

                resizeArr(this->getCurrentNumberOfItems(), this->getCurrentNumberOfItems() + 1, this->items);
                this->setCurrentNumberOfItems(this->getCurrentNumberOfItems() + 1);

                cout << "SET ITEMS" << endl;
                cout << this->getCurrentNumberOfItems() << endl;
                cout << this->items[0] << endl;

                *this->items[this->getCurrentNumberOfItems() - 1] = new string[2];
                cout << *this->items[this->getCurrentNumberOfItems() - 1];

                *this->items[this->getCurrentNumberOfItems() - 1][0] = it;
                *this->items[this->getCurrentNumberOfItems() - 1][1] = to_string(weight);



                return true;
        }
}
bool Adventurer::dropItem(string it) {
        // TODO
        return true;
}
bool Adventurer::dropItem(int index) {
        // TODO
        return true;
}
void Adventurer::setName(string n) {
        this->name = n;
}
string Adventurer::getName() const {
        return this->name;
}
void Adventurer::setMaxCarryWeight(double w) {
        this->maxCarryWeight = w;
}
double Adventurer::getMaxCarryWeight() const {
        return this->maxCarryWeight;
}
void Adventurer::setCurrentCarryWeight(double w) {
        this->currentCarryWeight = w;
}
double Adventurer::getCurrentCarryWeight() const {
        return this->currentCarryWeight;
}
void Adventurer::setMaxNumberOfItems(int n) {
        this->maxNumberOfItems = n;
}
int Adventurer::getMaxNumberOfItems() const {
        return this->maxNumberOfItems;
}
void Adventurer::setCurrentNumberOfItems(int n) {
        this->currentNumberOfItems = n;
}
int Adventurer::getCurrentNumberOfItems() const {
        return this->currentNumberOfItems;
}
int Adventurer::getNumberOfAdventurers() const {
        // TODO
        return 0;
}
void Adventurer::setHealth(double h) {
        this->health = h;
}
double Adventurer::getHealth() const {
        return this->health;
}
string** Adventurer::getItem(int index) const {
        return this->items[index];
}

// Copy.
Adventurer& Adventurer::operator = (const Adventurer& a) {
}
