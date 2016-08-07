#ifndef RAIN_GRAPH_UTILITIES_H
#define RAIN_GRAPH_UTILITIES_H


/**
* @brief	Calculate the number of days in the given month and year.
*
* A leap year can be calculated with the following set of rules
* if( (year mod 4 == 0) AND (year mod 100 != 0) OR (year mod 400 == 0))
*		set true
*	else set false
*
* @param year represents the year an integer value.
* @param month represents the month as an integer value, 
*     where a value of zero indicates January, 
*     a value of one February, and so forth.
*
* @return the calculated number of days
*/
int numDaysInMonth(int year, int month);


/**
* @brief	Calculate all the month's total number of days for the year.
*
* int numDaysInMonth(int year, int month) 
* may be used to calculate this information.
*
* @return an one dimensional array with 12 cells - one for each month. 
* Each cell should contain the amount of days of a specific month. 
* The first cell represents January's number of days, 
* the second cell repersents Februry'snumber of dats, etc.
*/
size_t* yearsMonthSize(int year);


/**
* @brief	convert the string in the form YYYY/MM/DD, to integer values.
*
* @param	stampString is the string to be converted.
* @param	stampArray contains the converted information, 
* 			index 0 represents the year, 1 the month, and 2 the day.
*
* NOTE: stampArray must store -1 at the indexes where the conversion failed.
*/
void parseDateStamp(std::string stampString, int *stampArray[3]);


/**
* @brief	Parse a file containing the rainfall data into a 3D array
*
* @details This function must parse the opened file 
* and read the values to dataPtr.
*
*	The data in the file is represented by a timestamp paired with a value. 
*	The value indicates the amount of rain for that day in millimetres.
*	The value is separated with a tab. 
*	Each timestamp value pair is on a new line. 
*
*	It is assumed that all timestamps will follow consecutively,
*	however, the apparatus taking these values may sometimes fail. 
*	The absence of an entry for a day indicates that the apparatus 
*	has failed on that specific day.  The value of -1 must be stored 
*	in dataPtr to indicate the absence of that data.
*	
*	dataPtr must be able to grow dynamically, with the help of the relevant
*	array functions. dataPtr may only grow with one extra year element 
*	at a time. This growth must be triggered if the function detects a new 
*	year in a timestamp.
*
*	The month-dimension's size will always be 12. The day-dimension's 
*	size must be adapted according to the number of days in the month.
*		
*	The use of the following functions are recommended:
*		void reallocShort3d(short ***&ptr, size_t oldSize, size_t newSize) 
*		short ** newShort2d(size_t numRow, size_t *colSize) 
*		size_t* yearsMonthSize(int year)
*
* @param filename is the file to be opened.
*
* @param dataPtr is the data-structure that will contain all read in values. 
* Note that dataPtr is a referance to a 3D array.
* The dimensions can be described as [year][month][day].
*
* @param firstYear will store the value of the first year read from the file.
*
* @return the number of years read in from the file. -1 on file open error.
*/
size_t parseDataFile(std::string const & filename, short ***&dataPtr, int &firstYear);


/**
* @brief reallocates/resizes a 3D array of shorts to fit into a new size. 
* Size here refers to the first dimension. i.e. ptr[size][row][col].
*
* @note after the function executed, the original data in the array must 
* not be altered in any way. That is to say, only the first dimension of 
* ptr may be altered.
*
* @NOTE! this function must work in general and not specifically 
*	in the way it is used in parseDataFile
*
* @param ptr is the pointer that refers to the 3D array to be resized.
* @param oldSize is the current total number of elements in the first 
*		dimension of ptr. e.g.   ptr[this amount here][row][col]
* @param newSize is the new size that ptr will have after the function 
* has been executed.   ptr[the new amount here][row][col]
*/
void reallocShort3d(short ***&ptr, size_t oldSize, size_t newSize);


/**
* @brief creates a new varied length 2D array of shorts. 
* To clarify, the amount of columns in each row may vary
*		e.g. row one might look like this {1, 3, 5, 6, END}, with a total 
*		of four columns, where row two might look like this {1, 5, END} 
*		with a total of 2 columns, and row three, {4, 5, 7, END}
*				|__COL__
*				R[1][3][5][6]
*				O[1][5]
*				W[4][5][7]
*|
* @NOTE! this function must work in general and not specifically 
*	in the way it is used in parseDataFile

* @param numRow is the number of rows that the created array will have. 
*	In the example above, it is 3
* @param colSize is a one dimensional array that indicates the number 
*	of columns for each of the rows. In the example above, 
*	the array would look like this: {4, 2, 3}
*
* @return will return the 2D pointer that was created.
*/
short ** newShort2d(size_t numRow, size_t const *colSize);


/**
* @brief This function will delete all the elements af a given 2D array.
*
* @param ptr is the pointer, pointing to the data that is to be deleted. 
*       this pointer must be set to zero after the deletion process
* @param rowSize is the total rows in the array, i.g. ptr[row][col]. 
*       The function must loop through every row to delete its columns.
*/
void deleteShort2d(short **&ptr, size_t rowSize);


#endif












