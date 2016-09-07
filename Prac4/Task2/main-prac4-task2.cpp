
#include "global_includes.h"
#include"student.h"
#include"staff.h"

using namespace std;

int main(int argc, char **argv){
	Person * student1 = new Student("John Doe", Person::male);
	Person * student2 = new Student("Alice", Person::female);
	Person * staff1 = new Staff("Jane Doe", Person::female);
	Person * staff2 = new Staff("Peter File", Person::male);

	cout << "1.)" << "Greeting " << student1->greet() << endl;
	cout << "2.)" << "Greeting " << student2->greet() << endl;
	cout << "3.)" << "Greeting " << staff1->greet() << endl;
	cout << "4.)" << "Greeting " << staff2->greet() << endl;
    
	cout << endl;
    
	cout << "5.)" << student1->greet(staff1) << endl;
	cout << "6.)" << staff1->greet(student1) << endl;
    
	cout << "7.)" << staff1->work() << endl;
	cout << "8.)" << student1->work() << endl;
    
	cout << endl;
    
	cout << "9.)" << staff2->greet(student2) << endl;
	cout << "10.)" << student2->greet(staff2) << endl;
    
	cout << "11.)" << student2->work() << endl;
	cout << "12.)" << staff2->work() << endl;
	
	cout << endl;
	
	Person & subject = *staff2;
	for(size_t i = 0; i < subject.getNumColleagues(); i++){
		cout << "loop-1.)" << subject.greet() << " has met " << subject[i].greet() << endl;
	}
	cout << "13.)" << subject.greet(staff1) << endl;
	cout << "14.)" << subject.greet(student1) << endl;
	for(size_t i = 0; i < subject.getNumColleagues(); i++){
		cout << "loop-2.)" << subject.greet() << " has met " << subject[i].greet() << endl;
	}

	
	delete student1;
	delete student2;
	delete staff1;
    delete staff2;
	return 0;
}
/*Expected output
1.)Greeting young John Doe
2.)Greeting innocent Alice
3.)Greeting Ms Jane Doe
4.)Greeting Mr Peter File

5.)Hey dude, name's young John Doe what's yours? I am Ms Jane Doe, nice to meet you young John Doe.
6.)Hello young John Doe we meet again. Hey dude, nice to see you again Ms Jane Doe
7.)Jane Doe is logging in with employee number 12345680 into the Staff Portal to do some work.
8.)John Doe is logging in with employee number 12345678 into the Student Portal to do some work.

9.)Good day, I am Mr Peter File and you are? Hi Mr Peter File, Alice's the name.
10.)Hey dude, Mr Peter File nice to see you again. Hello innocent Alice we meet again.
11.)Alice is logging in with employee number 12345679 into the Student Portal to do some work.
12.)Peter File is logging in with employee number 12345681 into the Staff Portal to do some work.

loop-1.)Mr Peter File has met innocent Alice
13.)Good day, I am Mr Peter File and you are? I am Ms Jane Doe, nice to meet you Mr Peter File.
14.)Good day, I am Mr Peter File and you are? Hi Mr Peter File, John Doe's the name.
loop-2.)Mr Peter File has met innocent Alice
loop-2.)Mr Peter File has met Ms Jane Doe
loop-2.)Mr Peter File has met young John Doe
*/

















