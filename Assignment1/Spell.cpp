/*
 * Copyright (c) 2016, Thomas Scholtz
 * All rights reserved.
*/
#include "Spell.h"
#include <iomanip>      // std::setw

Spell::Spell(string name, int difficultyLevel, int skillLevel) {
        this->name = name;
        this->difficultyLevel = difficultyLevel;
        this->skillLevel = skillLevel;
}

Spell::Spell(const Spell& sp) {
        this->name = sp.getName();
        this->difficultyLevel = sp.getDifficultyLevel();
        this->skillLevel = sp.getSkillLevel();
}

Spell::~Spell() {

}

void Spell::setName(string n) {
        this->name = n;
}

string Spell::getName() const {
        return this->name;
}

void Spell::setDifficultyLevel(int d) {
        this->difficultyLevel = d;
}

int Spell::getDifficultyLevel() const {
        return this->difficultyLevel;
}

void Spell::setSkillLevel(int s) {
        if (s >= 0) {
                this->skillLevel = s;
        }
}

int Spell::getSkillLevel() const {
        return this->skillLevel;
}

Spell& Spell::operator=(const Spell& sp) {
        this->name = sp.getName();
        this->difficultyLevel = sp.getDifficultyLevel();
        this->skillLevel = sp.getSkillLevel();

        return *this;
}

// Preincrement.
Spell& Spell::operator++() {
        ++this->skillLevel;
        return *this;
}
// Postincrement.
Spell Spell::operator++(int) {
        // Save original value;
        Spell s(*this);

        // Increment this.
        ++this->skillLevel;

        // Return original.
        return s;
}

Spell Spell::operator--() {
        this->setSkillLevel(this->getSkillLevel() - 1);
        return *this;
}

// Post decrement.
Spell Spell::operator--(int) {
        Spell s(*this);
        this->setSkillLevel(this->getSkillLevel() - 1);
        return s;
}

Spell Spell::operator-=(int x) {
        this->setSkillLevel(this->getSkillLevel() - x);
        return *this;
}

ostream& operator<<(ostream& os, const Spell s) {
        os << right << setw(30) << s.getName() << setw(5) << right << s.getDifficultyLevel() << setw(5) << right << s.getSkillLevel();
        return os;
}
