/* 
 * Class Wizard
 */

#ifndef WIZARD_H
#define	WIZARD_H

#include "Spell.h"

class Wizard{
    
private:
    Spell* spells;
    int numberOfSpells;
    int maxNumberOfSpells;
    bool hasBeenSummoned;
    int age;
    int numberOfLossedSpells;
    bool hasCompletedTraining;
public:
    Wizard();
    Wizard(const Wizard& w);
    ~Wizard();
    void addSpell(const Spell& s);
    void deleteSpell(string name);
    int getNumberOfSpells() const;
    void setMaxNumberOfSpells(int m);
    int getMaxNumberOfSpells() const;
    void setAge(int a); 
    int getAge() const;
    int getNumberOfLossedSpells() const;
    Spell& getSpell(int index) const;
};

#endif	/* WIZARD_H */

