#include <iostream>
#include <vector>
#include "animals.h"

using namespace std;

int main(int argc, char **argv){
	vector<Animal*> animals;

	animals.push_back(new Dog("Dog"));
	animals.push_back(new Cat("Cat"));
	animals.push_back(new Bird("Bird"));
	
	cout << "detections:" << endl;
	for(auto animal : animals)
		animal->detectHuman();

	cout << endl << "actions:" << endl;
	for(auto animal : animals)
		cout << animal->action() << endl;

}

//expected output:
/*
detections:
Dog is looking for cuddles while wagging its tail
Cat is looking for cuddles while purring loudly
Bird detected a human and is flying away

actions:
wagging its tail
purring loudly
flying away
*/