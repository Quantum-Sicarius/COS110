#include <iostream>



#include "global_includes.h"
#include "student.h"
#include "staff.h"

#include "lecturer_phd.h"
#include "lecturer_msc.h"

using namespace std;



int main(int argc, char **argv){
								Person * phd1 = new LecturerPhD("Marde Helbig", Person::female);
								Person * phd2 = new LecturerPhD("Stephen Hawking", Person::male);

								Person * msc1 = new LecturerMsC("Oyelami Babajide", Person::male);
								Person * msc2 = new LecturerMsC("Jane Doe", Person::female);

								Person * student1 = new Student("Alice", Person::female);
								Person * student2 = new Student("John Doe", Person::male);



								cout << "1.) " << phd2->greet() << "'s proficiency : " << dynamic_cast<LearningMachine*>(phd2)->getProficiency() << endl;
								cout << "2.) " << msc2->greet() << "'s proficiency : " << dynamic_cast<LearningMachine*>(msc2)->getProficiency() << endl;
								cout << "3.) " << student2->greet()  << "'s proficiency : " << dynamic_cast<LearningMachine*>(student2)->getProficiency() << endl << endl;


								cout << "4.) " << dynamic_cast<LearningMachine*>(phd1)->teach(student1) << endl << endl;
								cout << "5.) " << dynamic_cast<LearningMachine*>(msc1)->teach(student2) << endl << endl;
								cout << "6.) " << dynamic_cast<LearningMachine*>(student2)->teach(msc1) << endl << endl;


								cout << "7.) " << dynamic_cast<LearningMachine*>(phd1)->teach(phd2) << endl << endl;
								cout << "8.) " << dynamic_cast<LearningMachine*>(msc1)->teach(phd2) << endl << endl;


								cout << "9.) " << dynamic_cast<LearningMachine*>(phd1)->teach(msc2) << endl << endl;
								cout << "10.) " << dynamic_cast<LearningMachine*>(msc1)->teach(msc2) << endl << endl;

								cout << "11.) " << dynamic_cast<LearningMachine*>(student1)->teach(student2) << endl << endl;
								cout << "12.) " << dynamic_cast<LearningMachine*>(student1)->teach(student2) << endl << endl;
								cout << "13.) " << dynamic_cast<LearningMachine*>(student2)->teach(student1) << endl << endl;

								return 0;
}

/*expected output
   1.) Dr Stephen Hawking's proficiency : 80
   2.) Ms Jane Doe's proficiency : 70
   3.) young John Doe's proficiency : 0

   4.) Good day, I am Dr Marde Helbig and you are? Hi Dr Marde Helbig, Alice's the name. Starting the lesson now (LecturerPhD teaches). innocent Alice's Proficiency went from 0 to 8.8.

   5.) Good day, I am Mr Oyelami Babajide and you are? Hi Mr Oyelami Babajide, John Doe's the name. Great, let's start the lesson (LecturerMsC teaches). young John Doe's Proficiency went from 0 to 3.85.

   6.) Hey dude, Mr Oyelami Babajide nice to see you again. Hello young John Doe we meet again. Um, let's start *cough*  (Student teaches). Mr Oyelami Babajide's Proficiency went from 70 to 65.7801. Maybe I shouldn't teach :(

   7.) Good day, I am Dr Marde Helbig and you are? I am Dr Stephen Hawking, nice to meet you Dr Marde Helbig. Starting the lesson now (LecturerPhD teaches). Dr Stephen Hawking's Proficiency went from 80 to 92.

   8.) Good day, I am Mr Oyelami Babajide and you are? I am Dr Stephen Hawking, nice to meet you Mr Oyelami Babajide. Great, let's start the lesson (LecturerMsC teaches). Dr Stephen Hawking's Proficiency went from 92 to 96.9335.

   9.) Good day, I am Dr Marde Helbig and you are? I am Ms Jane Doe, nice to meet you Dr Marde Helbig. Starting the lesson now (LecturerPhD teaches). Ms Jane Doe's Proficiency went from 70 to 80.

   10.) Good day, I am Mr Oyelami Babajide and you are? I am Ms Jane Doe, nice to meet you Mr Oyelami Babajide. Great, let's start the lesson (LecturerMsC teaches). Ms Jane Doe's Proficiency went from 80 to 84.1113.

   11.) Hey dude, name's innocent Alice what's yours? Hi innocent Alice, John Doe's the name. Um, let's start *cough*  (Student teaches). young John Doe's Proficiency went from 3.85 to 1.07676. Maybe I shouldn't teach :(

   12.) Hey dude, young John Doe nice to see you again. Hey dude, nice to see you again innocent Alice. Um, let's start *cough*  (Student teaches). young John Doe's Proficiency went from 1.07676 to 0. Maybe I shouldn't teach :(

   13.) Hey dude, innocent Alice nice to see you again. Hey dude, nice to see you again young John Doe. Um, let's start *cough*  (Student teaches). innocent Alice's Proficiency went from 8.8 to 0. Maybe I shouldn't teach :(

 */
