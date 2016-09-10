#include "learning_machine.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

double fRand(double fMin, double fMax)
{
        double f = (double)rand() / RAND_MAX;
        return fMin + f * (fMax - fMin);
}

double LearningMachine::normalizeProficiency() {
        /* initialize random seed: */
        srand (time(NULL));

        this->proficiency = fRand(0,100);

        return this->proficiency;
}

double LearningMachine::getProficiency() {
        return this->proficiency;
}
