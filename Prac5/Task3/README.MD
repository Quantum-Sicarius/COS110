# Task 3: Exception Inheritance [10]

Inheritance and polymorphism can be used to simplify exception throwing. In this task, you will be required to extend the Exception class from Task 1 to make it simpler to throw exceptions in Task 2.

Rather than initializing the exception with a value, classes for each class of exception should be created:

- EmptyExcepion Initialized with the string "The string is empty!".
- OutOfBoundsExcepion Initialized with the string "Index out of bounds!".
- UnequalSizeExcepion Initialized with the string "Strings are not the same size!".
- EmptyResultExcepion Initialized with the string "The result is an empty string!".
- CharacterNotFoundExcepion It should be possible to use this exception in two ways:
- If a character is passed into the constructor, the exception should contain the string _"No character 'x' found!"_ , where'x' is the character that was not found.

- If no character is passed in, then the exception should contain the string _"No character 'x' found!"_.

  Example usage:

  ```c++
  try {
    throw EmptyException;
  } catch (Exception e) {
    cout << e.what() << endl;
  }
  ```

  Output: `The String is empty!</character>`

Modify your files from Task 2 to use these Exception classes, rather than passing in strings. There should be no output statements in your code, and no newline characters in any strings.

**Note: Implementations should be done in the header files**.

On completion, create a tarball containing the **CharString.cpp**, **EmptyException.h**, **OutOfBoundsException.h**, **UnequalSizeException.h** and **CharacterNotFoundException.h**. Upload it using the active fitchfork assignment called **Practical 5 - Exception Inheritance**.
