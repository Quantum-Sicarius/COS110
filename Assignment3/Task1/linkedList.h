#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include <iostream>
using namespace std;
template<class T>
class LinkedList;

template<class T>
ostream& operator<<(ostream&,LinkedList<T>&);

template<class T>
class LinkedList
{
	public:
		/*The overloaded stream operator for the List class.  If
		a List object is printed and contains the elements a,c,b and m, with
		element 'a' at index 0 and element 'm' at index 3 (first to last), the 
		output MUST be in the following format:
		[a,c,b,m]
		with no white space or new lines.
		
		NOTE: if the list is empty, output empty square brackets:
		[]
		*/
		friend ostream& operator<< <T>(ostream&,LinkedList<T>&);
		
		/*
		The constructor initializes all relevant member variables.
		*/
		LinkedList();
				
		/*
		The copy constructor.
		*/
		LinkedList(const LinkedList<T>& other);
		
		/*
		The overloaded assignment operator.
		*/
		LinkedList<T>& operator=(const LinkedList<T>& other);
		
		/*
		Creates a dynamically allocated deep copy of the object and returns
		a pointer to it
		*/
		LinkedList<T>* clone();
		
		/*
		The destructor.
		*/
		~LinkedList();
		
		/*
		Returns the element at the index passed in 
		as a parameter. The element is not removed from the data structure.
		If an invalid index is given, throw an appropriate string error.
		hint: different errors if invalid index or empty list
		*/
		T get(int index) const;
		
		/*
		overload the [] to make it return the value at the given index
		*/
		virtual T operator[](int index);
		
		/*
		Returns true if the list is empty, and false
		otherwise.
		*/
		virtual bool isEmpty();
		
		/*
		Returns the head, not the element at the head.
		*/
		virtual Node<T>* getLeader() const;
		
		/*
		Inserts an element at the given index.  The following holds 
		for this function:
		
		1.) It is valid to insert at index 0 of an empty list.
		
		2.) It is valid to insert at the index returned by size().  Simply
		    append the element to the back of the list.
		
		3.) Only indices between 0 and size() are valid. (0 <= index <= size())
		
		4.) For an invalid index, throw an exception message "invalid index"
		hint: inserting a value at a specified index causes all nodes after that index
		to shift backwards.
		e.g.: index  0 1 2 3
			  data  [1,2,3,5]
			  insert 4 at index 3
			  result: [1,2,3,4,5]
		*/
		virtual void insert(int index, T element);
		
		/*
		Removes and returns the element at the index passed in 
		as a parameter. If an invalid delete is attempted
		throw an appropriate string error.
		hint: different errors if invalid index or empty list
		*/
		virtual T remove(int index);	
		
		/*
		Removes all of the nodes from the list.  After this function has
		been called on a LinkedList object, the list must be empty.
		hint: becareful of memory leaks
		*/
		void clear();
		
		/*
		Appends a list.B to the end of another list.A and returns
		the resulting list.
		e.g listA = {1,2,3,4,5}, listB = {2,4,6,8};
		result = {1,2,3,4,5,2,4,6,8};
		hint: be careful of shallow copy
		*/
		virtual LinkedList<T>& operator+(const LinkedList<T>& other);
	protected:	
		ostream& print(ostream& os);

		//Returns the number of nodes in the list.
		virtual int size() const;
		
		//The first node in the list,
		Node<T>* head;
};

#include "linkedList.cpp"

#endif
