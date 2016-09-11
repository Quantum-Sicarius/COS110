#include "Hobbit.h"

Hobbit::Hobbit() {
        this->name = "";
}

Hobbit::~Hobbit() {

}

void Hobbit::setName(string n) {
        this->name = n;
}

string Hobbit::getName() const {
        return this->name;
}

bool Hobbit::hasBeenSummoned(Wizard& w) {
        if (w.getNumberOfLossedSpells() >= 5) {
                w.setHasBeenSummoned(true);
        }

        return w.getHasBeenSummoned();
}

bool Hobbit::hasCompletedTraining(Wizard& w) {
        w.setNumberOfLossedSpells(0);
        w.setHasBeenSummoned(false);
        w.setHasCompletedTraining(true);

        return w.getHasCompletedTraining();
}

void Hobbit::dropWizardSpells(Wizard& w) {
        // Check for spells with skill level of 0.
        for (int i = 0; i < w.getMaxNumberOfSpells(); i++) {
                if (w.getSpell(i).getSkillLevel() == 0) {
                        w.deleteSpell(w.getSpell(i).getName());
                }
        }

        this->hasBeenSummoned(w);
}
