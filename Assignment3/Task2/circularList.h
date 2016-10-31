#ifndef CIRCLELIST_H
#define CIRCLELIST_H

#include <iostream>
#include "linkedList.h"
#include "node.h"

using namespace std;

template<class T>
class CircularList;

template<class T>
ostream& operator<<(ostream&,CircularList<T>&);

template<class T>
class CircularList : public LinkedList<T>
{
	public:
		/*
		The overloaded stream operator.  This function should return a string representation of the list.  Elements should be comma separated and appear between square brackets.  If the list contains the elements x, y, and z, then the string returned should be [x,y,z] with no additional whitespace/new lines.
		*/
		friend ostream& operator<< <T>(ostream&,CircularList<T>&);
		
		/*
		The constructor initializes an empty list.
		*/
		CircularList();
		
		/*
		The copy constructor.
		*/
		CircularList(const CircularList<T>& other);
		
		/*
		The overloaded assignment operator.
		*/
		CircularList<T>& operator=(const CircularList<T>& other);

		/*
		Creates a dynamically allocated deep copy of the object and returns
		a pointer to it
		*/
		virtual CircularList<T>* clone();
		
		/*
		The destructor.
		*/
		virtual ~CircularList();
		
		/*The following holds for this function:
		
		1.) It is valid to insert at index 0 into an empty list
		
		2.) If the index supplied is the size of the list, then append the element to the back of the list.
		
		3.) Any index that is smaller than the size of the list, except for negative numbers, is valid.
		
		4.) For an invalid index, throw "invalid index" string. 
		*/
		virtual void insert(int index, T element);
		
		/*
		Removes and returns the element at the index passed in 
		as a parameter.    If a delete is attempted on a empty structure
		throw the string "empty structure". If a delete is attempted
		on an invalid index throw the string "invalid index".
		*/
		virtual T remove(int index);
		
		/*
		Returns the element at the index passed in as a parameter. The element
		is not removed from the data structure. If a get is attempted on a empty structure
		throw the string "empty structure". If a get is attempted
		on an invalid index throw the string "invalid index".
		*/
		virtual T get(int index) const;
		
		/*
		Returns true if the list is empty and false otherwise.
		*/
		virtual bool isEmpty();
		
		/*
		Removes all of the nodes from the list.  After this function has
		been called on a CircularList object, the list must be empty.
		*/
		virtual void clear();
		
		/*
		Returns a pointer to the first element, not the element at the front of the list.
		*/
		virtual Node<T>* getLeader() const;
		
		/*
		Appends a ccList.B to the end of another ccList.A and returns
		the resulting ccList.
		e.g ccListA = {1,2,3,4,5}, ccListB = {2,4,6,8};
		result = {1,2,3,4,5,2,4,6,8};
		hint: be careful of shallow copy and make sure the tail node is correctly linked
		*/
		virtual int size() const;
		CircularList<T>& operator+(const CircularList<T>& other);
		
	protected:
		ostream& print(ostream& os);
		
};

#include "circularList.cpp"

#endif
