#include "Node.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	string array[]  = {"A","B","C","D"};
	Node *one = new Node(4,array);

	cout<<"Original List: "<<endl;
	one->display();

	one->reverse();

	cout<<"Reversed List: "<<endl;
	one->display();

	return 0;
}