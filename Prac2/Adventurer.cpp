#include "Adventurer.h"
#include <iostream>
//Implement or define your class here
Adventurer::Adventurer() {
        this->items = 0;
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

        copy->items = a.items;
}  //copy constructor
Adventurer::~Adventurer() {
        //delete &health;
        //delete &maxCarryWeight;
        //delete &maxNumberOfItems;
        //delete &currentCarryWeight;
        //delete &currentNumberOfItems;
        //delete &name;

        for (size_t i = 0; i < this->getCurrentNumberOfItems(); i++) {
                delete [] this->items[i];
        }
}

void resizeArr(int oldSize, int newSize, string*** &arr) {

        //cout << "Redo Array" << endl;

        string ***newArr = new string**[newSize];

        //cout << "LOOP" << endl;
        //cout << oldSize << endl;
        //cout << newSize << endl;
        for (int i = 0; i < oldSize; i++) {
                newArr[i] = arr[i];
        }
        //cout << "DEL" << endl;
        delete [] arr;
        //cout << "REASSIGN" << endl;
        arr = newArr;
}

bool deleteItem(int index, int size, string*** &arr) {
        delete [] arr[index];
        // HEIGHT, ROWS, COLUMNS(pointers to strings)
        string ***newArr = new string**[size - 1];

        for (size_t i = 0; i < size; i++) {
                if (arr[i] != 0) {
                        newArr[i] = arr[i];
                }
        }

        delete [] arr;

        arr = newArr;

        return true;
}


bool Adventurer::pickUpItem(string it, double weight) {
        // Check if the player can carry more items.
        if ((currentCarryWeight + weight) > maxCarryWeight || (currentNumberOfItems + 1) > (maxNumberOfItems)) {
                return false;
        } else {
                // Resize the Array.

                resizeArr(this->getCurrentNumberOfItems(), (this->getCurrentNumberOfItems() + 1), (this->items));
                this->setCurrentNumberOfItems(this->getCurrentNumberOfItems() + 1);

                //cout << "SET ITEMS" << endl;
                //cout << this->getCurrentNumberOfItems() << endl;
                //cout << (this->items)[0] << endl;

                //cout << "ASSIGNED1" << endl;
                //cout << *(this->items) << endl;
                //cout << **(this->items) << endl;
                //cout << ***(this->items) << endl;
                //*(this->items)[this->getCurrentNumberOfItems() - 1] = new string[2];
                //cout << "ASSIGENd2" << endl;
                (this->items)[this->getCurrentNumberOfItems() - 1] = new string*[2];
                //cout << (this->items)[0] << endl;


                //cout << "ASSIGNED2" << endl;
                //cout << (this->items[0][0]);
                //cout << "TEST" << endl;
                (this->items)[this->getCurrentNumberOfItems() - 1][0] = new string(it);
                //(this->items)[this->getCurrentNumberOfItems() - 1][0] = &it;

                string str_weight = to_string(weight);
                //cout << str_weight << endl;
                //std::strcpy(str_weight,to_string(weight));
                (this->items)[this->getCurrentNumberOfItems() - 1][1] = new string(str_weight);
                //(this->items)[this->getCurrentNumberOfItems() - 1][1] = &str_weight;



                return true;
        }
}
bool Adventurer::dropItem(string it) {
        for (size_t i = 0; i < this->getCurrentNumberOfItems(); i++) {
                if (it.compare(*this->items[i][0])) {
                        if(deleteItem(i,this->getCurrentNumberOfItems(), this->items)) {
                                this->setCurrentNumberOfItems(this->getCurrentNumberOfItems() - 1);
                                return true;
                        }
                }
        }
        return false;
}
bool Adventurer::dropItem(int index) {
        if(this->items[index]) {
                if(deleteItem(index,this->getCurrentNumberOfItems(), this->items)) {
                        this->setCurrentNumberOfItems(this->getCurrentNumberOfItems() - 1);
                        return true;
                }
        }
        return false;
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
        return (this->items)[index];
}

// Copy.
Adventurer& Adventurer::operator = (const Adventurer& a) {
}
