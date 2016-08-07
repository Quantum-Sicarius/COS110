#include<sstream>
#include<ctype.h>
#include<iostream>
#include "arrayUtilities.h"

using namespace std;


int main(){
	short ***data = 0;
	int firstYear;
	string fname = "raindata.txt";
	
	int numYears = parseDataFile(fname, data, firstYear);
	int *stamp = new int[3];
	

	cout << "Enter exit any time to quit" << endl;
	bool loop = true;
	while(loop){
		string input;
		cout << "Enter the date in the form YYYY/MM/DD to display the rainfall on that day: ";
		cin >> input;
		if(input.compare("exit") == 0){
			loop = false;
		}else{
			stamp[0] = stamp[1] = stamp[2] = -1;
			parseDateStamp(input, &stamp);
			bool valid = stamp[0] != -1 && stamp[1] != -1 && stamp[2] != -1;

			int year = stamp[0] - firstYear;
			int month = stamp[1]  - 1;
			int day = stamp[2] - 1;

			if(year < 0 || year >= numYears)
				valid = false;
			if(month < 0 || month >= 12)
				valid = false;
			if(day < 0 || day >= numDaysInMonth(year, month) )
				valid = false;

			if(valid && data[ year ][ month ][ day ] == -1)
				valid = false;

			if(valid){
				cout << "It rained " << data[ year ][ month ][ day ] << "mm on " << input << endl;
			}else{
				cout << "No data found for input \"" << input << "\""<< endl;
			}
		}
		cout << "--------------------------------------------------------------------------------" << endl;
	}

	for(int yearOffset = 0; yearOffset < numYears; yearOffset++){
		deleteShort2d(data[yearOffset], 12);
	}

	delete stamp;
}