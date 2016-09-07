#ifndef STUDENT_H
#define STUDENT_H

#include "learning_machine.h"
#include "person.h"

/*IMPORTANT NO COUT STATEMENTS SHOULD BE IN YOUR SOURCE CODE, AND NO NEW LINES IN ANY RETURNED STRING*/

/*Extra public LearningMachine Inheritance */
class Student: public Person, public LearningMachine
{
	public:

/*BEGIN: Extra from LearningMachine*/
	/**
	* Initialize LearningMachine with zero
	*/
	Student(std::string name_, Gender gender_);

	/**
	* @return "<greet-student> Um, let's start *cough*  (Student teaches). <learned> Maybe I shouldn't teach :(";
	*  where <greet-student> is the string returned by greeting the student (i.e. Person parameter) i.e. passing Person * parameter to greet
	*  where <learned> is the string returned after the student (i.e. Person parameter) hase called learn
	*/
	std::string teach(Person * student);
	
	
	/**
	* increment proficiency with 1.1 times teacher's getSomeProficiency()
	* @return "<greet>'s Proficiency went from <oldP> to <new-normalize-Proficiency>.";
	*  where <greet> is the string returned after calling greet()
	*  where <oldP> is the value BEFOR the increment
	*  where <new-normalize-Proficiency> is the value AFTER the increment, this value must be normalized
	*/
	std::string learn(Person * teacher);
	
	
	/**
	* @return -10.0 / (sqrt(proficiency) + 1) 
	*/
	double getSomeProficiency();
/*END: Extra from LearningMachine*/

	
	std::string greet();
	std::string greet(Person *other);
	std::string work();
	
	std::string getTitle();
	
	protected:
	std::string reply(Person *other);
};




#endif