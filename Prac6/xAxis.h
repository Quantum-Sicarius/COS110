//There are three very nasty errors in here. Fix them before you continue

#ifndef XAXIS_H
#define XAXIS_H

#include <i0stream>
#include <string>

using namespace sfd;

class xAxis{

private:
	struct node{
		double value;
		string label;
		struct node *next;

	};
	node *head;

public:



	~xAxis();
	xAxis();
	/* constructor: length is the length of the x-axis
					n is an array of labels to describe the values in the x-axis
					v is an array of values for each label
If the value is negative then store it as 0.	*/
	xAxis(int length, string* n, double* v);

	/*appends one node to the linked list with the value v and the label n
If the value is negative then store it as 0.*/																																									
	void extend(double v,string n);

	/*removes the last node from the linked list*/
	void shorten();
	/*removes the node with the label n from the linked list*/
	void deleteNode(string n);
	/*increases the value of the node with label n by val*/																																																																																	.
	void increaseValueBy(string n,double val);
	/*decreases the value of the node with label n by val
If the value becomes negative then store it as 0.*/
	void decreaseValueBy(string n,double val);
	/*the node which has the label o must be changed so that it has the label n*/
	void changeLabel(string o,string n);
	/*displays all the nodes in a " label    value " newline  format.

	ie:
	one   1.97
	two   2.8076
	three   3.21
	*/
	void display();

};
#endif