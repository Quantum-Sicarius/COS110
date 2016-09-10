#include "student.h"
#include <sstream>

#include <iostream>
#include <math.h>

Student::Student(std::string name_, Person::Gender gender_) : Person(name_, gender_), LearningMachine(0) {

}
/**
 * @return "<greet-student> Um, let's start *cough*  (Student teaches). <learned> Maybe I shouldn't teach :(";
 *  where <greet-student> is the string returned by greeting the student (i.e. Person parameter) i.e. passing Person * parameter to greet
 *  where <learned> is the string returned after the student (i.e. Person parameter) hase called learn
 */
std::string Student::teach(Person * student) {
        return student->greet() + " Um, let's start *cough*  (Student teaches). " + dynamic_cast<LearningMachine*>(student)->learn(this) + " Maybe I shouldn't teach :(";
}

std::string Student::learn(Person * teacher) {
        double oldProf = this->getProficiency();
        double newProf = this->getProficiency() + dynamic_cast<LearningMachine*>(teacher)->getProficiency() * 1.1;
        this->normalizeProficiency();
        return this->greet() + "'s Proficiency went from " + std::to_string(oldProf) + " to " + std::to_string(newProf) +".";
}

double Student::getSomeProficiency() {
        return (-10.0 / (sqrt(this->proficiency) + 1));
}

std::string Student::greet() {
        std::stringstream buffer;
        buffer << this->getTitle() << " " << Person::greet();

        return buffer.str();
}

std::string Student::greet(Person *other) {
        if (other == NULL) {
                return "I don't greet null people!";
        }

        if(this->recognize(other)) {
                std::string s = "Hey dude, " + other->greet() + " nice to see you again. " + other->reply(this);
                return s;
        } else{
                // Grow colleagues.
                this->growAcquaintances();
                //std::cout << this->numColleagues << std::endl;
                this->colleagues[this->numColleagues - 1] = other;

                std::string s = "Hey dude, name's " + this->greet() + " what's yours? " + other->reply(this);
                return s;
        }
}

std::string Student::work() {
        return Person::greet() + " is " + Person::work() + " into the Student Portal to do some work.";
}

std::string Student::getTitle() {
        if (this->getGender() == male) {
                return "young";
        }
        return "innocent";
}

std::string Student::reply(Person *other) {
        if (other == NULL) {
                return "I don't greet null people!";
        }

        if(this->recognize(other)) {
                std::string s = "Hey dude, nice to see you again " + other->greet();
                return s;
        } else{
                // Grow colleagues.
                this->growAcquaintances();
                this->colleagues[this->numColleagues - 1] = other;

                std::string s = "Hi "+ other->greet() + ", " + Person::greet() + "'s the name.";
                return s;
        }
}
