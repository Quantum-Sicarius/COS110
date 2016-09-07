#include "person.h"
#include <sstream>
#include <iomanip>

#include <iostream>

size_t Person::empNoCounter = 12345678;

Person::Person(std::string name_, Person::Gender gender_) {
        this->numColleagues = 0;
        this->colleagues = 0;
        this->empNo = empNoCounter++;
        this->name = name_;
        this->gender = gender_;
}

Person::~Person() {

}

size_t Person::getNumColleagues() {
        return this->numColleagues;
}

std::string Person::greet() {
        return this->name;
}

std::string Person::work() {
        std::stringstream buffer;

        buffer << "logging in with employee number " << std::setfill('0') << std::setw(8) << this->empNo;

        return buffer.str();
}

Person & Person::operator[] (size_t i) {
        return *this->colleagues[i];
}

void Person::growAcquaintances() {
        size_t sizeOfArray = this->numColleagues;
        this->numColleagues++;
        Person **newarr = new Person*[this->numColleagues];

        for (size_t i = 0; i < sizeOfArray; i++) {
                if (this->colleagues[i]) {
                        newarr[i] = this->colleagues[i];
                }
        }

        delete [] this->colleagues;
        this->colleagues = newarr;

        //std::cout << "DONE" << std::endl;
        //std::cout << "numColleagues: " << numColleagues << std::endl;
}

bool Person::recognize(Person * other) {
        for (size_t i = 0; i < this->numColleagues; i++) {
                if (other == this->colleagues[i]) {
                        return true;
                }
        }

        return false;
}

Person::Gender Person::getGender() {
        return this->gender;
}

std::string Person::getName() {
        return this->name;
}
