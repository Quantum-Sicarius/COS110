#include <iostream>
#include "Adventurer.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include <string>
/*
 * Add comments here
 */

using namespace std;

int adventurers = 0;

string items[][2] = {
{"SWORD", "21.2"},
{"AXE", "30.1"},
{"MACE","12.1"},
{"BROADSWORD", "15"},
{"DAGGER", "5.1"}
};

string* getRandomItem() {
        int random_num;
        // Generate random number between 1 and 5.
        random_num = rand() % 5;

        //cout << ran

        //cout << "RANDOM: " << random_num << endl;
        //cout << items[0][0];
        return items[random_num];
}

int randomNumber() {

        // Random.
        // Initialize random seed.

        int random_num;
        // Generate random number between 1 and 100.
        random_num = rand() % 100 + 1;

        //cout << "RANDOM: " << random_num << endl;
        return random_num;
}

void testAttributes(Adventurer *ad) {

        adventurers++;
        //cout << adventurers;

        // Set name.
        ad->setName (("adventurer" + to_string(adventurers)));
        cout << "Adventurer name: " << ad->getName() << endl;

        // Set carry weight.
        ad->setMaxCarryWeight(randomNumber());
        cout << "Adventurer: " << ad->getName() << "\tmax carry weight: " << ad->getMaxCarryWeight() << endl;

        // Set max items;
        ad->setMaxNumberOfItems(randomNumber());
        cout << "Adventurer: " << ad->getName() << "\tmax number of items: " << ad->getMaxNumberOfItems() << endl;

        // Set health;
        ad->setHealth(randomNumber());
        cout << "Adventurer: " << ad->getName() << "\thealth: " << ad->getHealth() << endl;

        // Pick up item.
        string *item = getRandomItem();

        //cout << item[0] << "\t" << item[1] << endl;

        cout << "Adventurer: " << ad->getName() << " is picking up: " << item[0] << " of weight: " << item[1]
             << "\tSuccess? " << ad->pickUpItem(item[0],stod(item[1])) << endl;

        // Test items.
        cout << "Adventurer: " << ad->getName() << " has: " << ad->getCurrentNumberOfItems() << " number of items." << endl;

        if (ad->getCurrentNumberOfItems() > 0) {
                // Get item.
                cout << "Adventurer: " << ad->getName() << " has items" << endl;

                for (size_t i = 0; i < ad->getCurrentNumberOfItems(); i++) {
                        cout << *(ad->getItem(i))[0] << "\t" << *(ad->getItem(i))[1]  << endl;
                }

                string *item = getRandomItem();

                cout << "Adventurer: " << ad->getName() << " is picking up: " << item[0] << " of weight: " << item[1]
                     << "\tSuccess? " << ad->pickUpItem(item[0],stod(item[1])) << endl;

                // Test items.
                cout << "Adventurer: " << ad->getName() << " has: " << ad->getCurrentNumberOfItems() << " number of items." << endl;

                cout << "Drop Item: " << ad->dropItem(0) << endl;
                cout << "Adventurer: " << ad->getName() << " has: " << ad->getCurrentNumberOfItems() << " number of items." << endl;

                //cout << "Drop item: " << item[0] << ad->dropItem(item[0]) << endl;

                cout << "Adventurer: " << ad->getName() << " has: " << ad->getCurrentNumberOfItems() << " number of items." << endl;

        }

}

void printAttributes(Adventurer *ad) {

        cout << "Adventurer name: " << ad->getName() << endl;

        cout << "Adventurer: " << ad->getName() << "\tmax carry weight: " << ad->getMaxCarryWeight() << endl;

        cout << "Adventurer: " << ad->getName() << "\tmax number of items: " << ad->getMaxNumberOfItems() << endl;

        cout << "Adventurer: " << ad->getName() << "\thealth: " << ad->getHealth() << endl;
}

int main() {
        //add code here to test your class
        cout << "Start..." << endl;

        srand (time(NULL));

        //cout << getRandomItem() << endl;

        // Create new Adventurer.
        Adventurer *ad1 = new Adventurer();
        testAttributes(ad1);

        Adventurer *ad2 = new Adventurer();
        testAttributes(ad2);

        Adventurer *ad3 = ad2;
        printAttributes(ad3);

        cout << "Deleting AD2" << endl;
        delete ad2;

        cout << "Testing AD3" << endl;
        printAttributes(ad3);

        return 0;
}
