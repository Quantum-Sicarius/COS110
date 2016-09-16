# Task 2: CharString Class [20]

In this task you will be required to implement your own string class, where you will use the Exception class created in Task 2 to indicate errors in various operator functions. This class, **CharString**, needs to have the following operators overloaded:

- **The + operator** : This operator should return a CharString where the characters from the right hand side are appended onto the string on the left hand side. If the right hand string is empty, an exception should be thrown with the text "The string is empty!". Example: "aaa" + "bbb" should return "aaabbb"

- **The - operator** : This operator should return a CharString where every instance of the character on the right hand side is removed from the string on the left hand side. 2If there are no instances of the character in the string, then an exception should be thrown with the text "No character 'x' found!" , where 'x' is the character on the right hand side. If the left hand string is empty, an exception should be thrown with the text "The string is empty!". If the result is an empty string, an exception should be thrown with the text "The result is an empty string!". Example: "banana" - "a" should return "bnn"

- **The * operator**: This operator should return a CharString which consist of the left hand and right hand side interleaved. In other words, after every n-th character from the left hand string the n-th from the right string should follow. If the strings are not the same length, an exception should be thrown with the text "Strings are unequal lengths!". Example: "aaa"_ "bbb" should become "ababab".

- **The / operator**: This operator should return a CharString where every instance of every character from the right hand string should be removed from the left hand side. If there are no instances of any characters from the right hand side, then an exception should be thrown with the text "No character found!". If either string is an empty string, an exception should be thrown with the text "The string is empty!". If the result is an empty string, an exception should be thrown with the text "The result is an empty string!". Example: "bananas" / "and" should become "bs".

- **The == operator**: Should return true if every character from the left hand string is equal to the corre- sponding character from the right hand string. Otherwise, return false. If the strings are diffferent lengths, return false.

- **The [] operator**: The operator should return the character at index i of the string. If the index is out of bounds, an exception should be thrown with the text "Index out of bounds!".

- **The ofstream operator**, which should return (not output) the array in string representation.

- **The assignment operator**, which should make a deep copy of the string.

Additionally, each mathematical operator should have its corresponding assignment oper- ator overloaded (**operator +=, operator -=, operator *= and operator /=**). These operators should modify the left hand parameter rather than returning the string hence the functions return type is void. For cases where the string increases in size (such as the + operator ) the size of the string should be dynamically increased.

**CharString** should also contain the following public methods:

- A copy constructor.
- A constructor which takes in a character array and a size, and initialises the CharString with the array.
- int length() , which returns the number of characters in the string. A header file, CharString.h, is provided. Do not edit any functions in this file. You may add helper functions if you want.

It is advised that you create a main file to test your implementation, and experiment with how to catch the exceptions. There should be no output statements in your code, and no newline characters in any ex- ception messages. On completion, create a tarball containing **CharString.cpp** and **CharString.h**. Upload it us- ing the active fitchfork assignment called **Practical 5 - CharString Class**.
