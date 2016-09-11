#include "global_includes.h"
#include "lecturer_msc.h"

LecturerMsC::LecturerMsC(std::string name_, Gender gender_) : Staff(name_, gender_, 70) {

}

/**
 * @return "<greet-student> Great, let's start the lesson (LecturerMsC teaches). <learned>";
 *  where <greet-student> is the string returned by greeting the student (i.e. Person parameter) i.e. passing Person * parameter to greet
 *  where <learned> is the string returned after the student (i.e. Person parameter) hase called learn
 */
// 5.) Good day, I am Mr Oyelami Babajide and you are? Hi Mr Oyelami Babajide, John Doe's the name.
// Great, let's start the lesson (LecturerMsC teaches). young John Doe's Proficiency went from 0 to 3.85.
std::string LecturerMsC::teach(Person * student) {
        return this->greet(student) + " Great, let's start the lesson (LecturerMsC teaches). " + dynamic_cast<LearningMachine*>(student)->learn(this);
}

std::string LecturerMsC::learn(Person * teacher) {
        double oldProf = this->getProficiency();
        double newProf = this->getProficiency() + (dynamic_cast<LearningMachine*>(teacher)->getSomeProficiency() * 1.25);

        this->proficiency = newProf;
        this->normalizeProficiency();


        std::stringstream buffer;
        buffer << this->greet() << "'s Proficiency went from " << oldProf << " to " << this->proficiency << ".";

        return buffer.str();
}

double LecturerMsC::getSomeProficiency() {
        return this->proficiency * 0.05;
}
