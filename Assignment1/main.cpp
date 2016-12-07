/*
 * Copyright (c) 2016, Thomas Scholtz
 * All rights reserved.
*/
/*
 * main function to test code
 */

#include <cstdlib>
#include <iostream>
#include "Wizard.h"
#include "Spell.h"
#include "Hobbit.h"
#include <iomanip>      // std::setw

using namespace std;

void printWizard(const Wizard w) {
        cout << "=========================================================" << endl;
        cout << "Wizard is: " << w.getAge() << " years old." << endl;
        cout << "Wizard has been summoned: " << w.getHasBeenSummoned() << endl;
        cout << "Wizard has been trained: " << w.getHasCompletedTraining() << endl;
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

void printSpell(Spell s) {
        cout << "++++++++++++++++++++++++++++++++++++" << endl;
        cout << right << setw(30) << "SpellName" << setw(5) << "SkillL" << setw(5) << "DifficultyL" << endl;
        cout << s << endl;
        cout << "++++++++++++++++++++++++++++++++++++" << endl;

}

int main() {
        Wizard wiz;
        Spell s1("vanishing",3,1);
        Spell s2("resurect",4,2);
        Spell s3("shock",2,1);
        Spell s4;
        Spell s12;
        Spell s5("hurrican", 1, 1);
        Spell s6("heal", 1, 1);
        Spell s7("blink", 0,1);
        Spell s8("eat", 0, 0);
        Spell s9("drink", 0, 0);
        Spell s10("sleep", 0, 0);
        Spell s11("meh", 0, 0);
        Spell s13("lol", 1,1);

        cout << "Testing spell operators: " << endl;
        printSpell(s1);
        cout << "operator++: " << s1.getSkillLevel() << endl;
        s1++;
        cout << "Result: " << s1.getSkillLevel() << endl << endl;

        cout << "++operator: " << s1.getSkillLevel() << endl;
        ++s1;
        cout << "Result: " << s1.getSkillLevel() << endl <<endl;

        cout << "operator-=: " << s1.getSkillLevel() << endl;
        s1-= 2;
        cout << "Result: " << s1.getSkillLevel() << endl <<endl;

        cout << "Testing spell assignment operator: " << endl;
        s4 = s12 = s1;
        cout << "Result: " << endl;
        printSpell(s4);
        printSpell(s12);

        cout << "Testing spell assignment with operator: " << endl;
        cout << "Before:" << endl;
        printSpell(s2);
        s2=(++s1);
        cout << "After: " << endl;
        printSpell(s2);


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

        Hobbit h;
        h.setName("Frodo");

        wiz + s5;
        wiz + s6;
        wiz + s7;
        wiz + s8;
        wiz + s9;
        wiz + s10;
        wiz + s11;
        wiz + s13;

        cout << "Test compare < operator: should return 0" << endl;
        cout << "Result: ";
        cout << (wiz < wiz2) << endl << endl;

        cout << "Test compare < operator: should return 1" << endl;
        cout << "Result: ";
        cout << (wiz2 < wiz) << endl << endl;

        cout << "Test compare > operator: should return 0" << endl;
        cout << "Result: ";
        cout << (wiz2 > wiz) << endl << endl;

        cout << "Test compare > operator: should return 1" << endl;
        cout << "Result: ";
        cout << (wiz > wiz2) << endl << endl;

        printWizard(wiz);
        h.dropWizardSpells(wiz);
        printWizard(wiz);

        return 0;
}
