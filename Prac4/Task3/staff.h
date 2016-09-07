#ifndef STAFF_H
#define STAFF_H

#include"learning_machine.h"
#include"person.h"

/*IMPORTANT NO COUT STATEMENTS SHOULD BE IN YOUR SOURCE CODE, AND NO NEW LINES IN ANY RETURNED STRING*/

class Student;
/*Extra public LearningMachine Inheritance */
class Staff: public Person, public LearningMachine
{
	public:
	/*Extra double parameter*/
	Staff(std::string name_, Gender gender_, double proficiency_);
	
	std::string greet();
	std::string greet(Person *other);
	std::string work();

	std::string getTitle();


	protected:
	std::string reply(Person *other);
};




#endif