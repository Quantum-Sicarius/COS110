#include "CharString.h"
#include <sstream>      // std::stringstream

void CharString::reallocateArray(int newSize) {
        //  Create new array.
        char* newCharacters = new char[newSize];

        // Copy over.
        for (int i = 0; i < this->length(); i++) {
                newCharacters[i] = this->characters[i];
        }

        this->numChars = newSize;

        // Delete our old array.
        delete [] this->characters;
        // Assign new array.
        this->characters = newCharacters;
}

CharString::CharString() {
        this->numChars = 0;
        this->characters = 0;
}

CharString::CharString(const char* c, int size) {
        this->numChars = 0;
        this->characters = 0;

        this->reallocateArray(size);

        for (int i = 0; i < this->length(); i++) {
                this->characters[i] = c[i];
        }
}

/* Copy constructor */
CharString::CharString(const CharString &s) {
        this->numChars = 0;
        this->characters = 0;

        this->reallocateArray(s.length());

        // TODO: Deep copy.
        for (int i = 0; i < this->length(); i++) {
                this->characters[i] = s[i];
        }
}

/* Destructor */
CharString::~CharString() {
        delete [] this->characters;
}

const CharString CharString::operator= (const CharString &s) {
        this->numChars = 0;
        this->reallocateArray(s.length());

        // TODO: Deep copy.
        for (int i = 0; i < this->length(); i++) {
                this->characters[i] = s[i];
        }

        return *this;
}

/*
   This operator should return a CharString where the characters from the right hand
   side are appended onto the string on the left hand side.
   If the right hand string is empty, an exception should be thrown with the text "The string
   is empty!".
 */
CharString CharString::operator+ (const CharString &s) {
        if (s.length() == 0) {
                throw Exception("The string is empty!");
        }

        // New temporary instance.
        CharString* cs = new CharString(*this);

        int previousSize = cs->length();
        int totalSize = cs->length() + s.length();

        // Make an array big enough for both char arrays.
        cs->reallocateArray(totalSize);

        // Remember the -1.
        // TODO: Check deep copy?
        for (int i = 0; i < s.length(); i++) {
                cs->characters[(i + previousSize)] = s[i];
        }

        return *cs;
}

void CharString::operator+= (const CharString &s) {
        *this = *this + s;
}

/* Subtraction operators */
CharString CharString::operator- (const char &c) {
        if (this->length() == 0) {
                throw Exception("The string is empty!");
        }

        // New CharString.
        char* newCharacters = new char[this->length()];

        // Temp counter.
        int newCharactersCounter = 0;

        // Check if we even found the character.
        bool found = false;

        for (int i = 0; i < this->length(); i++) {
                if (this->characters[i] == c) {
                        found = true;
                } else {
                        newCharacters[newCharactersCounter] = this->characters[i];
                        ++newCharactersCounter;
                }
        }

        // If we didn't find the character we must throw an exception.
        if (!found) {
                std::string exceptionS = "No character '";
                exceptionS += c;
                exceptionS += "' found!";
                throw Exception(exceptionS);
        }


        // New temporary instance.
        CharString* cs = new CharString(newCharacters, newCharactersCounter);


        // Check if empty string.
        if (cs->length() == 0) {
                throw Exception("The result is an empty string!");
        }

        return *cs;

}

void CharString::operator-= (const char &s) {
        *this = *this - s;
}

/* Multiplication operators */
CharString CharString::operator* (const CharString &s) {
        if (this->length() != s.length()) {
                throw Exception("Strings are unequal lengths!");
        }

        // New temporary instance.
        CharString* cs = new CharString(*this);
        int totalSize = cs->length() + s.length();

        cs->reallocateArray(totalSize);

        int firstSize = 0;
        int secondSize = 0;

        for (int i = 0; i < cs->length(); i++) {
                // Every second one.
                if ((i % 2) == 0) {
                        cs->characters[i] = this->characters[firstSize];
                        ++firstSize;
                } else {
                        cs->characters[i] = s[secondSize];
                        ++secondSize;
                }
        }

        return *cs;
}

void CharString::operator*= (const CharString &s) {
        *this = *this * s;
}

/* Division operators */
CharString CharString::operator/ (const CharString &s) {
        if (this->length() == 0 || s.length() == 0) {
                throw Exception("The string is empty!");
        }

        // New CharString.
        char* newCharacters = new char[this->length()];

        // Temp counter.
        int newCharactersCounter = 0;

        // Check if we even found the character.
        bool found = false;
        bool localizedFound = false;

        for (int i = 0; i < this->length(); i++) {
                localizedFound = false;

                for (int j = 0; j < s.length(); j++) {
                        if (this->characters[i] == s[j]) {
                                localizedFound = true;
                                found = true;
                        }
                }

                if (!localizedFound) {
                        newCharacters[newCharactersCounter] = this->characters[i];
                        ++newCharactersCounter;
                }
        }

        // If we didn't find the character we must throw an exception.
        if (!found) {
                throw Exception("No character found!");
        }

        // New temporary instance.
        CharString* csTemp = new CharString(newCharacters,newCharactersCounter);


        // Check if empty string.
        if (csTemp->length() == 0) {
                throw Exception("The result is an empty string!");
        }

        return *csTemp;
}

void CharString::operator/= (const CharString &s) {
        *this = *this / s;
}

/* Equivalence operator */
bool CharString::operator == (const CharString &s) {
        if (this->length() != s.length()) {
                return false;
        }


        for (int i = 0; i < this->length(); i++) {
                if (this->characters[i] != s[i]) {
                        return false;
                }
        }

        return true;
}

/* Element access operators */
char &CharString::operator[](int i) const {
        if (i < 0 || i >= this->length()) {
                throw Exception("Index out of bounds!");
        }

        return this->characters[i];
}

ostream &operator << (ostream &os, const CharString &s) {
        for (int i = 0; i < s.length(); i++) {
                os << s[i];
        }

        return os;
}


const int CharString::length() const {
        return this->numChars;
}
