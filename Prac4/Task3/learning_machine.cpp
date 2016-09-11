#include "global_includes.h"
#include "learning_machine.h"

LearningMachine::LearningMachine(double proficiency_) {
        this->proficiency = proficiency_;
}

double LearningMachine::normalizeProficiency() {
        if (this->getProficiency() >= 100) {
                this->proficiency = 100;
        } else if(this->getProficiency() <= 0) {
                this->proficiency = 0;
        }

        return this->proficiency;
}

double LearningMachine::getProficiency() {
        return this->proficiency;
}
