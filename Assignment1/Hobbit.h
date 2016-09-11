/*
 * Class Hobbit
 */

#ifndef HOBBIT_H
#define	HOBBIT_H

#include "Wizard.h"
#include "string"
using namespace std;

class Hobbit{
private:
    string name;
public:
    Hobbit();
    ~Hobbit();
    void setName(string n);
    string getName() const;
    bool hasBeenSummoned(Wizard& w);
    bool hasCompletedTraining(Wizard& w);
    void dropWizardSpells(Wizard& w);
};

#endif	/* HOBBIT_H */
