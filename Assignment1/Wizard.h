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
    void setNumberOfLossedSpells(int);


    Spell& getSpell(int index) const;

    bool operator<(const Wizard& rhs) const;
    bool operator>(const Wizard& lhs) const;
    Wizard operator+(const Spell& s);
    Wizard operator-(const string s);

    bool getHasCompletedTraining() const;
    bool getHasBeenSummoned() const;
    void setHasCompletedTraining(bool);
    void setHasBeenSummoned(bool);
};

#endif	/* WIZARD_H */
