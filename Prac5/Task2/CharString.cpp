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

        int totalSize = this->length() + s.length();

        // Make an array big enough for both char arrays.
        this->reallocateArray(totalSize);

        // Remember the -1.
        // TODO: Check deep copy?
        for (int i = this->length() - 1; i < totalSize; i++) {
                this->characters[i] = s[i];
        }

        return *this;
}

void CharString::operator+= (const CharString &s) {

}

/* Subtraction operators */
CharString CharString::operator- (const char &c) {

}

void CharString::operator-= (const char &s) {

}

/* Multiplication operators */
CharString CharString::operator* (const CharString &s) {

}

void CharString::operator*= (const CharString &s) {

}

/* Division operators */
CharString CharString::operator/ (const CharString &s) {

}

void CharString::operator/= (const CharString &s) {

}

/* Equivalence operator */
bool CharString::operator == (const CharString &s) {

}

/* Element access operators */
char CharString::&operator[](int i) const {

}

const int CharString::ength() const {
        return this->numChars;
}
