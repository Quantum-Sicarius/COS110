#ifndef STAFF_H
#define STAFF_H

/*IMPORTANT NO COUT STATEMENTS SHOULD BE IN YOUR SOURCE CODE, AND NO NEW LINES IN ANY RETURNED STRING*/
/*IMPORTANT NO COUT STATEMENTS SHOULD BE IN YOUR SOURCE CODE, AND NO NEW LINES IN ANY RETURNED STRING*/
/*IMPORTANT NO COUT STATEMENTS SHOULD BE IN YOUR SOURCE CODE, AND NO NEW LINES IN ANY RETURNED STRING*/

#include "person.h"

class Staff: public Person
{
public:
	Staff(std::string name_, Gender gender_);
	
	/**
	* @return a a string of the form: <title><space><name>
		e.g. "Mr John Doe"
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
	*   return: "Good day, I am <greet> and you are? <other-reply>"
	*     where <greet> is the string return from the method greet()
	*     where <other-reply> is the string returned from the other person's reply"
	* 3.) if this person DOES recognize other:
	*   do: *nothing
	*   return: "Hello <other-greet> we meet again. <other-reply>"
	*     where <other-greet> is the string return from the other person's greet() method
	*     where <other-reply> is the string returned from the other person's reply"   
	*/
	std::string greet(Person *other);
	
	/**
	* @ return a string of the form "<name> is <parent work> into the Staff Portal to do some work.";
	*    where <parent work> is a string of the from "logging in with employee number <Employee number>"
	*      where <employee number> is a 8-digit number that is zero padded,
	*      e.g the value 1 will be displayed as 00000001
	*/
	std::string work();
	
	/**
	* @return the person's title based on the gender. "Mr" for male, and "Ms" for female.
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
	*   return: "I am <greet>, nice to meet you <other-greet>."
	*     where <greet> is the string return from the method greet()
	*     where <other-greet> is the string returned from the other person's greet()"
	* 3.) if this person DOES recognize other:
	*   do: *nothing
	*   return: "Hello <other-greet> we meet again."
	*     where <other-greet> is the string return from the other person's greet() method
	*/
	std::string reply(Person *other);
};




#endif