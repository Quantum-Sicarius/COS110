#include "lecturer_phd.h"
#include <string>

LecturerPhD::LecturerPhD(std::string name_, Gender gender_) : Staff(name_, gender_, 80) {

}

/**
 * @return "<greet-student> Starting the lesson now (LecturerPhD teaches). <learned>";
 *  where <greet-student> is the string returned by greeting the student (i.e. Person parameter) i.e. passing Person * parameter to greet
 *  where <learned> is the string returned after the student (i.e. Person parameter) hase called learn
 */
std::string LecturerPhD::teach(Person * student) {
        return this->greet(student) + " Starting the lesson now (LecturerPhD teaches). " + dynamic_cast<LearningMachine*>(student)->learn(student);
}

/**
 * increment proficiency with 1.5 times teacher's getSomeProficiency()
 * @return "<greet>'s Proficiency went from <oldP> to <new-normalize-Proficiency>.";
 *  where <greet> is the string returned after calling greet()
 *  where <oldP> is the value BEFOR the increment
 *  where <new-normalize-Proficiency> is the value AFTER the increment, this value must be normalized
 */
std::string LecturerPhD::learn(Person * teacher) {
        double oldProf = this->getProficiency();
        double newProf = this->getProficiency() + dynamic_cast<LearningMachine*>(teacher)->getProficiency() * 1.5;
        this->normalizeProficiency();
        return this->greet() + "'s Proficiency went from " + std::to_string(oldProf) + " to " + std::to_string(newProf) + ".";
}

double LecturerPhD::getSomeProficiency() {
        return this->proficiency * 0.1;
}

std::string LecturerPhD::getTitle() {
        return "Dr";
}
