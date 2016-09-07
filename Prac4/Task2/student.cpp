#include "student.h"
#include <sstream>

#include <iostream>

Student::Student(std::string name_, Person::Gender gender_) : Person(name_, gender_) {

}

std::string Student::greet() {
        std::stringstream buffer;
        buffer << this->getTitle() << " " << this->getName();

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
        return this->getName() + " is " + Person::work() + " into the Student Portal to do some work.";
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

                std::string s = "Hi "+ other->greet() + ", " + this->getName() + "'s the name.";
                return s;
        }
}
