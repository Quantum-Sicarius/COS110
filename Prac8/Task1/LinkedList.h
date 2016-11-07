#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>

using namespace std;

class LinkedList{

private:
	struct node{
		string name;
		struct node *next;
	};
	node *head;
	int length;

public:

	~LinkedList();
	LinkedList();
	LinkedList(int length, string* n);
	void display();

	LinkedList* combine(LinkedList* two);

};
#endif