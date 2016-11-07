#include "LinkedList.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	string array1[]  = {"g","f","h","d","b","a"};
	LinkedList *one = new LinkedList(6,array1);

	string array2[]  = {"e","j","i","l","k","c"};
	LinkedList *two = new LinkedList(6,array2);

	LinkedList *answer;	


	answer = one->combine(two);

	if(answer)
		answer->display();

	return 0;
}

/* Expected output

a b c d e f g h i j k l 

*/