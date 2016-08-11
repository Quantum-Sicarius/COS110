#include <stdlib.h>
#include <sstream>
#include "arrayUtilities.h"
using namespace std;


// Implement functions defined in arrayUtilities.h in this file.
// Note: arrayUtilities.h will be overwritten by Fitchfork.

int numDaysInMonth(int year, int month) {
        switch (month) {
        case 1:
                return 31;
                break;
        case 2:
                // Check leap year
                if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
                        return 29;
                        break;
                }
                return 28;
                break;
        case 3:
                return 31;
                break;
        case 4:
                return 30;
                break;
        case 5:
                return 31;
                break;
        case 6:
                return 30;
                break;
        case 7:
                return 31;
                break;
        case 8:
                return 31;
                break;
        case 9:
                return 30;
                break;
        case 10:
                return 31;
                break;
        case 11:
                return 30;
                break;
        case 12:
                return 31;
                break;
        }

}

size_t* yearsMonthSize(int year) {
        size_t *yearmonthsize = new size_t[12];

        for (size_t i = 0; i < 12; i++) {
                yearmonthsize[i] = numDaysInMonth(year, i + 1);
        }

        return yearmonthsize;
}
/*
   void parseDateStamp(std::string stampString, int *stampArray[3]) {

        string delimiter = "/";

        int *year = new int;
   *year = stoi(stampString.substr(0, stampString.find(delimiter)));
        stampString.erase(0, stampString.find(delimiter) + delimiter.length());

        int *month = new int;
   *month = stoi(stampString.substr(0, stampString.find(delimiter)));
        stampString.erase(0, stampString.find(delimiter) + delimiter.length());

        stampString = (stampString.substr(0, stampString.find(delimiter)));

        int *day = new int;
   *day = stoi(stampString.substr(0, stampString.find("-")));

   *stampArray[0] = *year;
   *stampArray[1] = *month;
   *stampArray[2] = *day;


        cout << "SUCCESS" << endl;
        cout << *stampArray[0] << *stampArray[1] << *stampArray[2];
   }
   //*/
void parseDateStamp(std::string stampString, int *stampArray[3]){
        std::string word = "";
        std::istringstream buffer;

        size_t i;
        for(i = 0; stampString.at(i) != '/'; i++)
                word.push_back(stampString.at(i));


        i++;
        buffer.str(word);
        buffer >> (*stampArray)[0];


        buffer.clear();
        word.clear();

        for(i; stampString.at(i) != '/'; i++) {
                word.push_back(stampString.at(i));
        }


        i++;

        buffer.str(word);

        buffer >> (*stampArray)[1];
        buffer.clear();

        word.clear();

        for(i; stampString.length() > i; i++)
                word.push_back(stampString.at(i));

        i++;

        buffer.str(word);
        buffer >> (*stampArray)[2];
        buffer.clear();
        word.clear();

}

size_t parseDataFile(std::string const & filename, short ***&dataPtr, int &firstYear) {

        fstream file;
        file.open(filename);

        string date;
        string mill;

        int count = 0;

        // First date.
        file >> date >> mill;

        count++;
        reallocShort3d(dataPtr, 0, count);

        //cout << date << "\t" << mill << endl;

        int *parseArr = new int[3];
        parseDateStamp(date,&parseArr);

        firstYear = parseArr[0];

        // New 2d array
        size_t *days = yearsMonthSize(parseArr[0]-firstYear);
        dataPtr[parseArr[0]-firstYear] = newShort2d(12,days);

        dataPtr[parseArr[0]-firstYear][parseArr[1]-1][parseArr[2]-1] = stoi(mill);

        // Previous year
        int Previous_year = parseArr[0];
        // Year count
        int year_count = 1;

        while (file >> date >> mill) {
                // First date.
                file >> date >> mill;

                count++;

                // Read array
                int *parseArr = new int[3];
                parseDateStamp(date,&parseArr);

                if (Previous_year != parseArr[0]) {
                        Previous_year = parseArr[0];
                        year_count++;
                        reallocShort3d(dataPtr, year_count - 1, year_count);

                        //cout << "NEW MONTH!" << endl;
                        // New 2d array
                        size_t *days = yearsMonthSize(parseArr[0]-firstYear);
                        dataPtr[parseArr[0]-firstYear] = newShort2d(12,days);
                }

                dataPtr[parseArr[0]-firstYear][parseArr[1]-1][parseArr[2]-1] = stoi(mill);
                //cout << parseArr[0] << "\t" << parseArr[1] << "\t" << parseArr[2] << "\t" << mill << endl;
                //cout << dataPtr[parseArr[0]-firstYear][parseArr[1]-1][parseArr[2]-1] << endl;


        }
}

void reallocShort3d(short ***&ptr, size_t oldSize, size_t newSize) {
        //cout << "REALLOCATION 3D" << endl;
        //cout << "OLDSIZE: " << oldSize << endl;
        //cout << "NEWSIZE: " << newSize << endl;

        short ***newptr = new short **[newSize];

        for(size_t i = 0; i < oldSize; i++) {
                newptr[i] = ptr[i];
        }

        delete [] ptr;
        ptr = newptr;
}
short ** newShort2d(size_t numRow, size_t const *colSize) {
        //cout << "REALLOCATION" << endl;
        //cout << "numRow: " << numRow << endl;
        //cout << "colSize: " << colSize << endl;

        short **newshort = new short *[numRow];
        for (size_t i = 0; i < *colSize; i++) {
                newshort[i] = new short[*colSize];
        }
        return newshort;
}
void deleteShort2d(short **&ptr, size_t rowSize) {
}
