#ifndef STUDENT_H
#define STUDENT_H

/*IMPORTANT NO COUT STATEMENTS SHOULD BE IN YOUR SOURCE CODE, AND NO NEW LINES IN ANY RETURNED STRING*/
/*IMPORTANT NO COUT STATEMENTS SHOULD BE IN YOUR SOURCE CODE, AND NO NEW LINES IN ANY RETURNED STRING*/
/*IMPORTANT NO COUT STATEMENTS SHOULD BE IN YOUR SOURCE CODE, AND NO NEW LINES IN ANY RETURNED STRING*/

#include"person.h"

class Student: public Person
{
	public:
	Student(std::string name_, Gender gender_);
	
	/**
	* @return a a string of the form: <title><space><name>
		e.g. "innocent Jane Doe"
	*/
	std::string greet();
	
	
	/**
	* NOTE: 'other' refers  to the parameter Person *other
	* this method returns three possible strings 
	* AND PERFORMS THE STEPS defined as follow
	* 1.) if other is null:
	*   do: *nothing
	*   return: "I don’t greet null people!"
	* 2.) if this person does NOT recognize other:
	*   do: *grow colleagues with one
	*       *save other in the new open element of colleagues (i.e. the last element)
	*   return: "Hey dude, name's <greet> what's yours? <other-reply>"
	*     where <greet> is the string return from the method greet()
	*     where <other-reply> is the string returned from the other person's reply"
	* 3.) if this person DOES recognize other:
	*   do: nothing
	*   return: "Hey dude, <other-greet> nice to see you again. <other-reply>"
	*     where <other-greet> is the string return from the method greet()
	*     where <other-reply> is the string returned from the other person's reply" 
	*/
	std::string greet(Person *other);
	
	/**
	* @ return a string of the form "<name> is <parent work> into the Student Portal to do some work.";
	*    where <parent work> is a string of the from "logging in with employee number <Employee number>"
	*      where <employee number> is a 8-digit number that is zero padded,
	*      e.g the value 1 will be displayed as 00000001
	*/
	std::string work();
	
	/**
	* @return the person's title based on the gender. "young" for male, and "innocent" for female.
	*/
	std::string getTitle();
	
	protected:
	
	
	/**
	* NOTE: 'other' refers  to the parameter Person *other
	* this method returns three possible strings 
	* AND PERFORMS THE STEPS defined as follow
	* 1.) if other is null:
	*   do: *nothing
	*   return: "I don’t greet null people!"
	* 2.) if this person does NOT recognize other:
	*   do: *grow colleagues with one
	*       *save other in the new open element of colleagues (i.e. the last element)
	*   return: "Hi <other-greet>, <name>'s the name."
	*     where <name> is the name of this person
	*     where <other-greet> is the string returned from the other person's greet()"
	* 3.) if this person DOES recognize other:
	*   do: *nothing
	*   return: "Hey dude, nice to see you again <other-greet>"
	*     where <other-greet> is the string return from the other person's greet() method
	*/
	std::string reply(Person *other);
};




#endif