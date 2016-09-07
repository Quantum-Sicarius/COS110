#ifndef LEARNING_MACHINE
#define LEARNING_MACHINE

/*IMPORTANT NO COUT STATEMENTS SHOULD BE IN YOUR SOURCE CODE, AND NO NEW LINES IN ANY RETURNED STRING*/

class Person;
class LearningMachine
{
public:
	LearningMachine(double proficiency_);
	
	/**no implementation*/
	virtual std::string teach(Person * student) = 0;
	/**no implementation*/
	virtual std::string learn(Person * student) = 0;
	/**no implementation*/
	virtual double getSomeProficiency() = 0;
	
	/**
	* set proficiency to be in the range 0-100 inclusive
	* @return the new set proficiency
	*/
	double normalizeProficiency();

	/**@return the proficiency*/
	double getProficiency();
protected:
	double proficiency;
};




#endif