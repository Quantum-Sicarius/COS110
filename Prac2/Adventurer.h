/* 
 * Adventurer class
 */

#ifndef ADVENTURER_H
#define	ADVENTURER_H
#include <string>
using namespace std;

class Adventurer{
private:
    string*** items;
    string name;
    double maxCarryWeight;
    double currentCarryWeight;
    int currentNumberOfItems;
    int maxNumberOfItems;
    double health;
    static int numberOfAdventurers;
    
    
public:
    Adventurer(); //default constructor
    Adventurer(const Adventurer& a);  //copy constructor
    ~Adventurer();
    bool pickUpItem(string it, double weight);
    bool dropItem(string it);
    bool dropItem(int index);
    void setName(string n);
    string getName() const;
    void setMaxCarryWeight(double w);
    double getMaxCarryWeight() const;
    void setCurrentCarryWeight(double w);
    double getCurrentCarryWeight() const;    
    void setMaxNumberOfItems(int n);
    int getMaxNumberOfItems() const;
    void setCurrentNumberOfItems(int n);
    int getCurrentNumberOfItems() const;
    int getNumberOfAdventurers() const;
    void setHealth(double h);
    double getHealth() const;
    string** getItem(int index) const;
    Adventurer& operator = (const Adventurer& a);
};


#endif	/* ADVENTURER_H */

