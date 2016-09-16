# Task 1: Exception Class [5]

An exception is a response to an event that happens during a program's execution. In this task, you are required to create a basic exception class that will be used in the following tasks. This class, Exception, will have the following:

- A member variable storing the reason for the exception as a string.
- A public function, what() , that returns the reason for the exception.
- A public constructor that takes in a string describing the reason for the exception and initialises the member variable.

Example usage:

```c++
 try {
   throw Exception ("Test Exception");
 } catch (Exception e) {
    cout << e.what() << endl; 
}
```

Output: `Test Exception`

There should be no output statement in your code, and no newline characters in the strings returned by _what()_. On completion, create a tarball containing **Exception.h** and **Exception.cpp**. Upload it using the active fitchfork assignment called **Practical 5 - Exception Class**.
