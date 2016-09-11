#include "Spell.h"

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
