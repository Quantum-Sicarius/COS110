#include <iostream>
#include "circularList.h"
#include <string>

using namespace std;

int main()
{
  //Write code to test your implementation.
  
	int nums[9] = {34, 61, 22, 56, 8, 44, 83, 13, 98};
	int lCount = 0;
	CircularList<int> cclist1;
	char value = 'a';
	
	cout << "-----------insert------------" << endl;

	try{
		cclist1.insert(0,nums[lCount]);
		lCount++;
		cout << cclist1 << endl;
	}
	catch (const char * s){
		cout << "ERROR: " << s << endl;
	}
	
	try{
		cclist1.insert(0,nums[lCount]);
		lCount++;
		cout << cclist1 << endl;
	}
	catch (const char * s){
		cout << "ERROR: " << s << endl;
	}
	
	cout << "-----copy constructor---------------" << endl;
	CircularList<int>* cclist2 = new CircularList<int>(cclist1);
	cout << *cclist2 << endl;
	
	cout << "-----------get------------" << endl;
	try{
		cout << "index: 1" << cclist1.get(1) << cclist1 << endl;
		
	}
	catch (const char * s){
		cout << "ERROR: " << s << endl;
	}
	
	cout << "-----------operator[]------------" << endl;

	try{
		cout << "index: 2" << cclist1[2] << endl;
	}
	catch (const char * s){
		cout << "ERROR: " << s << endl;
	}
	
	cout << cclist1 << endl;
	
	cout << "-----------remove------------" << endl;
	try{
		
		cout << cclist1.remove(2) << " -> " << cclist1 << endl;
	}
	catch (const char * s){
		cout << "ERROR: " << s << endl;
	}
	
	try{
		
		cout << cclist1.remove(1) << " -> " << cclist1 << endl;
	}
	catch (const char * s){
		cout << "ERROR: " << s << endl;
	}
	
	try{
		
		cout << cclist1.remove(1) << " -> " << cclist1 << endl;
	}
	catch (const char * s){
		cout << "ERROR: " << s << endl;
	}

	cout << "-----------operator=------------" << endl;
	cclist1 = *cclist2;
	cout << cclist1 << endl;
	
	cout << "-----------operator+------------" << endl;
	CircularList<int> cclist3 = cclist1 + *cclist2;
	cout << cclist3 << endl;
	
	/**/
  return 0;
  /////////////////////////////////////////////////////////
}
