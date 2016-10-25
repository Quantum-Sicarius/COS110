#ifndef NODE_H
#define NODE_H

/*
The Node class for the linked lists.
*/
template<class T>
class Node
{
	public:
		Node(T val, Node<T>* n = 0)
		{
			data = val;
			next = n;
		}
		
		~Node()
		{
			next = 0;
		}
		
		//The data stored in the node
		T data;
		//The next node in the list
		Node<T>* next;
};

#endif
