#ifndef PERSON_H
#define PERSON_H

/*IMPORTANT NO COUT STATEMENTS SHOULD BE IN YOUR SOURCE CODE, AND NO NEW LINES IN ANY RETURNED STRING*/

class Person
{
public:
	enum Gender{male, female};
	
	
	Person(std::string name_, Gender gender_);
	~Person();
	
	
	size_t getNumColleagues();
	Gender getGender();
	virtual std::string getTitle() = 0;


	virtual std::string greet() = 0;
	virtual std::string greet(Person *other) = 0;
	virtual std::string reply(Person *other) = 0;

	virtual std::string work() = 0;

	Person & operator[] (size_t i);

protected:
	void growAcquaintances();
	bool recognize(Person *);
	
	size_t numColleagues;
	Person ** colleagues;


private:
	static size_t empNoCounter;
	
	std::string name;
	Gender gender;
	size_t empNo;
};



#endif
