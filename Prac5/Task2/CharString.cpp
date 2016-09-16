#include "CharString.h"

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
        this->reallocateArray(size);

        for (int i = 0; i < this->length(); i++) {
                this->characters[i] = c[i];
        }
}

/* Copy constructor */
CharString::CharString(const CharString &s) {
        this->numChars = 0;
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

        int totalSize = cs->length() + s.length();

        // Make an array big enough for both char arrays.
        cs->reallocateArray(totalSize);

        // Remember the -1.
        // TODO: Check deep copy?
        for (int i = cs->length() - 1; i < totalSize; i++) {
                cs->characters[i] = s[i];
        }

        return *cs;
}

void CharString::operator+= (const CharString &s) {
        *this + s;
}

/* Subtraction operators */
CharString CharString::operator- (const char &c) {
        if (this->length() == 0) {
                throw Exception("The string is empty!");
        }

        // New temporary instance.
        CharString* cs = new CharString(*this);

        // Size holder.
        int currentSize = cs->length();

        // New CharString.
        char* newCharacters = new char[cs->length()];

        // Temp counter.
        int newCharactersCounter = 0;

        // Check if we even found the character.
        bool found = false;

        for (int i = 0; i < cs->length(); i++) {
                if (cs->characters[i] == c) {
                        found = true;
                        --currentSize;
                        cs->characters[i] = 0;
                } else {
                        newCharacters[newCharactersCounter] = cs->characters[i];
                        ++newCharactersCounter;
                }
        }

        // If we didn't find the character we must throw an exception.
        if (!found) {
                std::string exceptionS = "No character ’";
                exceptionS += c;
                exceptionS += "’ found!";
                throw Exception(exceptionS);
        }

        // Clean up array.
        cs->reallocateArray(newCharactersCounter);

        // Check if empty string.
        if (cs->length() == 0) {
                throw Exception("The result is an empty string!");
        }

        return *cs;

}

void CharString::operator-= (const char &s) {
        *this - s;
}

/* Multiplication operators */
CharString CharString::operator* (const CharString &s) {
        if (this->length() != s.length()) {
                throw Exception("Strings are unequal lengths!");
        }

        // New temporary instance.
        CharString* cs = new CharString(*this);

        for (int i = 0; i < this->length(); i++) {
                // Every second one.
                if ((i % 2) == 0) {
                        cs->characters[i] = s[i];
                } else {
                        cs->characters[i] = this->characters[i];
                }
        }

        return *cs;
}

void CharString::operator*= (const CharString &s) {
        *this * s;
}

/* Division operators */
CharString CharString::operator/ (const CharString &s) {
        if (this->length() == 0 || s.length() == 0) {
                throw Exception("The string is empty!");
        }

        // New temporary instance.
        CharString* cs = new CharString(*this);

        // Size holder.
        int currentSize = cs->length();

        // New CharString.
        char* newCharacters = new char[cs->length()];

        // Temp counter.
        int newCharactersCounter = 0;

        // Check if we even found the character.
        bool found = false;

        for (int i = 0; i < cs->length(); i++) {
                for (int j = 0; j < s.length(); j++) {
                        if (cs->characters[i] == s[j]) {
                                found = true;
                                --currentSize;
                                cs->characters[i] = 0;
                        }
                }
        }

        // If we didn't find the character we must throw an exception.
        if (!found) {
                throw Exception("No character found!");
        }

        // Clean up array.
        cs->reallocateArray(newCharactersCounter);

        // Check if empty string.
        if (cs->length() == 0) {
                throw Exception("The result is an empty string!");
        }

        return *cs;
}

void CharString::operator/= (const CharString &s) {
        *this / s;
}

/* Equivalence operator */
bool CharString::operator == (const CharString &s) {

}

/* Element access operators */
char CharString::&operator[](int i) const {

}

int CharString::length() const {
        return this->numChars;
}
