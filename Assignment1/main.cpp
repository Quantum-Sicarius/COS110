/*
 * main function to test code
 */

#include <cstdlib>
#include <iostream>
#include "Wizard.h"
#include "Spell.h"
using namespace std;

void printWizard(const Wizard w) {
        cout << "=========================================================" << endl;
        cout << "Wizard is: " << w.getAge() << " years old." << endl;
        cout << "Wizard has: " << w.getNumberOfSpells() << " number of spells." << endl;
        cout << "Wizard has: " << w.getMaxNumberOfSpells() << " max number of spells." << endl;
        cout << "Wizard has: " << w.getNumberOfLossedSpells() << " lost spells." << endl;
        cout << "Wizard's spells:" << endl;
        cout << "--------------------------------" << endl;
        cout << "SpellName\tSkillL\tDifficultyL" << endl;
        for (int i = 0; i < w.getMaxNumberOfSpells(); i++) {
                Spell currentSpell = w.getSpell(i);
                cout << currentSpell.getName() << "\t" << currentSpell.getSkillLevel() << "\t" << currentSpell.getDifficultyLevel() << endl;
        }
        cout << "--------------------------------" << endl;
        cout << "=========================================================" << endl;
}

int main() {
        Wizard wiz;
        Spell s1("vanishing",3,1);
        Spell s2("resurect",4,2);
        Spell s3("shock",2,1);
        //wiz.addSpell(s1);
        wiz + s1;
        wiz + s2;

        printWizard(wiz);

        cout << "Test remove operator:" << endl;
        wiz - "vanishing";
        cout << "Result: " << endl;
        printWizard(wiz);

        cout << "Test copy constructor: " << endl;
        Wizard wiz2(wiz);

        cout << "Result: " << endl;
        printWizard(wiz2);

        cout << "Testing < operator: " << endl;
        cout << "Result: ";
        cout << (wiz < wiz2) << endl << endl;

        cout << "Testing > operator: " << endl;
        cout << "Result: ";
        cout << (wiz > wiz2) << endl << endl;


        cout << "Adding spells to Wizard1" << endl << endl;
        wiz + s3;
        wiz + s1;

        cout << "Testing < operator: " << endl;
        cout << "Result: ";
        cout << (wiz < wiz2) << endl << endl;

        cout << "Testing > operator: " << endl;
        cout << "Result: ";
        cout << (wiz > wiz2) << endl << endl;

        cout << "Testing removal of non existant spell" << endl;
        wiz - "non";
        cout << "Done." << endl;

        return 0;
}
