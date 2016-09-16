#include <iostream>
#include "Exception.h"
#ifndef CHARSTRING_H
#define CHARSTRING_H
using namespace std;

class CharString
{
private:
	char* characters;		// The array of chars that make up the string
	int numChars;			// The current size of the array
public:
	/* Constructors */
	CharString();
	CharString(const char*, int size);

	/* Copy constructor */
	CharString(const CharString& s);

	/* Destructor */
	~CharString();

	/* Assignment operator */
	const CharString operator= (const CharString &s);

	/* Addition operators */
	CharString operator+ (const CharString &s);
	void operator+= (const CharString &s);

	/* Subtraction operators */
	CharString operator- (const char &c);	
	void operator-= (const char &s);

	/* Multiplication operators */
	CharString operator* (const CharString &s);
	void operator*= (const CharString &s);

	/* Division operators */
	CharString operator/ (const CharString &s);	
	void operator/= (const CharString &s);

	/* Equivalence operator */
	bool operator == (const CharString &s);

	/* Element access operators */
	char &operator[](int i) const;

	/* ostream operator */
	friend ostream &operator << (ostream &os, const CharString &s);	

	/* Get the length of the array */
	const int length() const;

private:
	/* Allocate more space to the array */
	void reallocateArray(int newSize);

	/* Added operators */
	CharString operator+ (const char &c);
	CharString operator+= (const char &c);
};

#endif