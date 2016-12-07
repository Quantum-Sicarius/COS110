/*
 * Copyright (c) 2016, Thomas Scholtz
 * All rights reserved.
 */
#include "global_includes.h"
#include "staff.h"

Staff::Staff(std::string name_, Person::Gender gender_) : Person(name_, gender_)  {

}

std::string Staff::greet() {
        std::stringstream buffer;
        buffer << this->getTitle() << " " << Person::greet();

        return buffer.str();

}

std::string Staff::greet(Person *other) {
        if (other == NULL) {
                return "I don't greet null people!";
        }

        if(this->recognize(other)) {
                std::string s = "Hello " + other->greet() + " we meet again. " + other->reply(this);
                return s;
        } else{
                // Grow colleagues.
                this->growAcquaintances();
                this->colleagues[this->numColleagues - 1] = other;

                std::string s = "Good day, I am " + this->greet() + " and you are? " + other->reply(this);
                return s;
        }
}

std::string Staff::work() {
        return Person::greet() + " is " + Person::work() + " into the Staff Portal to do some work.";
}

std::string Staff::getTitle() {
        if (this->getGender() == male) {
                return "Mr";
        }
        return "Ms";
}

std::string Staff::reply(Person *other) {
        if (other == NULL) {
                return "I don't greet null people!";
        }

        if(this->recognize(other)) {
                std::string s = "Hello " + other->greet() + " we meet again. ";
                return s;
        } else{
                // Grow colleagues.
                this->growAcquaintances();
                this->colleagues[this->numColleagues - 1] = other;

                std::string s = "I am " + this->greet() + ", nice to meet you " + other->greet() + ".";
                return s;
        }
}
