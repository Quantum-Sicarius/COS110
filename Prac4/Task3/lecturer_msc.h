#ifndef LECTURER_MSC_H
#define LECTURER_MSC_H

#include "staff.h"

/*IMPORTANT NO COUT STATEMENTS SHOULD BE IN YOUR SOURCE CODE, AND NO NEW LINES IN ANY RETURNED STRING*/

class LecturerMsC: public Staff
{
public:
	/**
	* Initialize LearningMachine with 70
	*/
	LecturerMsC(std::string name_, Gender gender_);
	
	/**
	* @return "<greet-student> Great, let's start the lesson (LecturerMsC teaches). <learned>";
	*  where <greet-student> is the string returned by greeting the student (i.e. Person parameter) i.e. passing Person * parameter to greet
	*  where <learned> is the string returned after the student (i.e. Person parameter) hase called learn
	*/
	std::string teach(Person * student);
	
	/**
	* increment proficiency with 1.25 times teacher's getSomeProficiency()
	* @return "<greet>'s Proficiency went from <oldP> to <new-normalize-Proficiency>.";
	*  where <greet> is the string returned after calling greet()
	*  where <oldP> is the value BEFOR the increment
	*  where <new-normalize-Proficiency> is the value AFTER the increment, this value must be normalized
	*/
	std::string learn(Person * student);
	
	/**
	* @return proficiency * 0.05
	*/
	double getSomeProficiency();
};



#endif