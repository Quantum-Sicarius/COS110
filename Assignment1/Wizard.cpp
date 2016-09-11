#include "Wizard.h"

Wizard::Wizard() {
        this->hasCompletedTraining = false;
        this->numberOfLossedSpells = 0;
        this->age = 20;
        this->hasBeenSummoned = false;
        this->maxNumberOfSpells = 10;
        this->numberOfSpells = 0;
        this->spells = new Spell[this->maxNumberOfSpells];

        // Initialize all spells to empty spells.
        for (int i = 0; i < this->maxNumberOfSpells; i++) {
                this->spells[i] = Spell("");
        }
}
Wizard::Wizard(const Wizard &w) {
        this->age = w.getAge();
        this->numberOfSpells = w.getNumberOfSpells();
        this->maxNumberOfSpells = w.getMaxNumberOfSpells();

        // We use maxNumberOfSpells because we initialize empty spells with the name "".
        this->spells = new Spell[this->maxNumberOfSpells];

        for (int i = 0; i < this->maxNumberOfSpells; i++) {
                // Deep copy.
                this->spells[i] = Spell(w.getSpell(i));
        }
}

// TODO: Check deep delete.
Wizard::~Wizard() {
        delete [] this->spells;
}

void Wizard::addSpell(const Spell& s) {
        // Check if we can fit one more spell.
        if ((this->numberOfSpells + 1) > this->maxNumberOfSpells) {
                // Resize array.
                Spell* newspells = new Spell[this->maxNumberOfSpells + 1];
                this->maxNumberOfSpells++;

                for (int i = 0; i < this->maxNumberOfSpells; i++) {
                        // Check for not null. This means we are not at the end if everything works as planned.
                        if (i != this->maxNumberOfSpells) {
                                newspells[i] = this->spells[i];
                        } else {
                                // Add the brand new spell.
                                newspells[i] = s;
                                this->numberOfSpells++;
                        }

                }

                // Delete old array.
                delete [] this->spells;

                // Point to new array.
                this->spells = newspells;
        } else {
                // Go through array and check for first empty spell.
                for (int i = 0; i < this->maxNumberOfSpells; i++) {
                        if (this->spells[i].getName() == "") {
                                this->spells[i] = s;
                                this->numberOfSpells++;
                                return;
                        }
                }
        }
}

void Wizard::deleteSpell(string name) {
        for (int i = 0; i < this->numberOfSpells; i++) {
                if (this->spells[i].getName() == name) {
                        this->spells[i] = Spell("");
                        this->numberOfSpells--;
                        this->numberOfLossedSpells++;
                        return;
                }
        }
}
int Wizard::getNumberOfSpells() const {
        return this->numberOfSpells;
}
void Wizard::setMaxNumberOfSpells(int m) {
        this->maxNumberOfSpells = m;
}
int Wizard::getMaxNumberOfSpells() const {
        return this->maxNumberOfSpells;
}
void Wizard::setAge(int a) {
        this->age = a;
}
int Wizard::getAge() const {
        return this->age;
}
int Wizard::getNumberOfLossedSpells() const {
        return this->numberOfLossedSpells;
}
Spell& Wizard::getSpell(int index) const {
        return this->spells[index];
}
