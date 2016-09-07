#ifndef PERSON_H
#define PERSON_H

/*IMPORTANT NO COUT STATEMENTS SHOULD BE IN YOUR SOURCE CODE, AND NO NEW LINES IN ANY RETURNED STRING*/
/*IMPORTANT NO COUT STATEMENTS SHOULD BE IN YOUR SOURCE CODE, AND NO NEW LINES IN ANY RETURNED STRING*/
/*IMPORTANT NO COUT STATEMENTS SHOULD BE IN YOUR SOURCE CODE, AND NO NEW LINES IN ANY RETURNED STRING*/

class Person
{
public:
	enum Gender{male, female};
	/**
	* set this->numColleagues to 0
	* set this->colleagues to 0
	* set this->empNo to static member empNoCounter++
	*/
	Person(std::string name_, Gender gender_);
	
	
	/**
	* Prevents memory-leaking
	* See main-file to deduce the workings, HINT: Persons are deleted in main
	*/
	~Person();
	
	/**
	* @return the number of current colleagues, i.e this->numColleagues
	*/
	size_t getNumColleagues();
	
	/**
	* Pure Virtual function with implementation
	* NOTE!! the implementation
	* @return the name of the person, i.e this->name
	*/
	virtual std::string greet() = 0;
	
	
	/**Pure Virtual function that greets another person (has no implementation)*/
	virtual std::string greet(Person *other) = 0;
	/**Pure Virtual function that reply's to a greet (has no implementation)*/
	virtual std::string reply(Person *other) = 0;
	
	
	/** Pure Virtual function with implementation
	* NOTE!! the implementation
	* @return a string "logging in with employee number <Employee number>"
	*    where <employee number> is a 8-digit number that is zero padded,
	*    e.g the value 1 will be displayed as 00000001
	*/
	virtual std::string work() = 0;

	/**
	* you may assume that this method will not be tested, such that it fails.
	* @return a reference to the Person at index i, in this->colleagues array
	*/
	Person & operator[] (size_t i);

protected:
	/**Grow the dynamic array this->colleagues by one*/
	void growAcquaintances();
	
	/**
	* Test the value of parameter other, to all elements in this->colleagues
	* @param other is a pointer to the person that is to be tested
	* @return true if parameter other was found, else false
	*/
	bool recognize(Person * other);
	
	/**@return this->gender*/
	Gender getGender();
	
	/**number of colleague elements in dynamic this->array colleagues*/
	size_t numColleagues;
	/**dynamic array of type Person pointer*/
	Person ** colleagues;
private:
	/**Pure Virtual function return the title of this person (has no implementation)*/
	virtual std::string getTitle() = 0;

	/**sttic counter that should be initiated to the value of 12345678*/
	static size_t empNoCounter;
	
	
	std::string name;
	Gender gender;
	/**Employee number*/
	size_t empNo;
};



#endif
