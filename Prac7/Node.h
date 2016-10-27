
//NOTE!
// Do not change any code in this file

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

using namespace std;

class Node{

private:
	struct node{
		string name;
		struct node *next;
	};
	node *head;

public:

	~Node();
	Node();
	Node(int length, string* n);
	void display();

//Implement this function in Node.cpp
	void reverse();

};
#endif

//NOTE!
// Do not change any code in this file
