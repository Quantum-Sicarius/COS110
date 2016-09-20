# Last try:

```
Compile WARNING => Possible compile warnings and/or errors follow, try to get rid of them.
In file included from CharString.h:4:0,
                 from CharString.cpp:1:
CharacterNotFoundException.h: In constructor 'CharacterNotFoundException::CharacterNotFoundException(char)':
CharacterNotFoundException.h:9:38: error: no matching function for call to 'Exception::Exception()'
   CharacterNotFoundException(char c) {
                                      ^
In file included from OutOfBoundsException.h:4:0,
                 from CharString.h:2,
                 from CharString.cpp:1:
Exception.h:9:2: note: candidate: Exception::Exception(std::__cxx11::string)
  Exception(std::string what) {
  ^
Exception.h:9:2: note:   candidate expects 1 argument, 0 provided
Exception.h:4:7: note: candidate: Exception::Exception(const Exception&)
 class Exception
       ^
Exception.h:4:7: note:   candidate expects 1 argument, 0 provided
Exception.h:4:7: note: candidate: Exception::Exception(Exception&&)
Exception.h:4:7: note:   candidate expects 1 argument, 0 provided
makefile:5: recipe for target 'CharString' failed
make: *** [CharString] Error 1

Compile FAILURE
Execute FAILED
Test case '1' => Produced 101 bytes of output, exit code 2

make: ./main: Command not found
makefile:8: recipe for target 'run' failed
make: *** [run] Error 127

FAIL Test 1: Error in empty string exception.
FAIL Test 2: Error in char not found exception.
FAIL Test 3: Error in empty result exception.
FAIL Test 4: Error in unequal size exception.
FAIL Test 5: Error in char not found exception.
FAIL Test 6: Error in empty string exception.
FAIL Test 7: Error in empty string exception.
FAIL Test 8: Error in empty result exception.
FAIL Test 9: Error in out of bounds exception.
FAIL Test 10: Error in out of bounds exception.
```

# Second last try:

```
Compile WARNING => Possible compile warnings and/or errors follow, try to get rid of them.
In file included from CharString.h:2:0,
                 from main.cpp:7:
OutOfBoundsException.h:3:7: error: redefinition of 'class OutOfBoundsException'
 class OutOfBoundsException : public Exception {
       ^
In file included from main.cpp:3:0:
OutOfBoundsException.h:3:7: error: previous definition of 'class OutOfBoundsException'
 class OutOfBoundsException : public Exception {
       ^
In file included from CharString.h:3:0,
                 from main.cpp:7:
UnequalSizeException.h:3:7: error: redefinition of 'class UnequalSizeException'
 class UnequalSizeException : public Exception {
       ^
In file included from main.cpp:6:0:
UnequalSizeException.h:3:7: error: previous definition of 'class UnequalSizeException'
 class UnequalSizeException : public Exception {
       ^
In file included from CharString.h:4:0,
                 from main.cpp:7:
CharacterNotFoundException.h:3:7: error: redefinition of 'class CharacterNotFoundException'
 class CharacterNotFoundException : public Exception {
       ^
In file included from main.cpp:4:0:
CharacterNotFoundException.h:3:7: error: previous definition of 'class CharacterNotFoundException'
 class CharacterNotFoundException : public Exception {
       ^
In file included from CharString.h:5:0,
                 from main.cpp:7:
EmptyResultException.h:3:7: error: redefinition of 'class EmptyResultException'
 class EmptyResultException: public Exception {
       ^
In file included from main.cpp:5:0:
EmptyResultException.h:3:7: error: previous definition of 'class EmptyResultException'
 class EmptyResultException: public Exception {
       ^
In file included from CharString.h:6:0,
                 from main.cpp:7:
EmptyException.h:3:7: error: redefinition of 'class EmptyException'
 class EmptyException: public Exception {
       ^
In file included from main.cpp:2:0:
EmptyException.h:3:7: error: previous definition of 'class EmptyException'
 class EmptyException: public Exception {
       ^
makefile:2: recipe for target 'main' failed
make: *** [main] Error 1

Compile FAILURE
Execute FAILED
Test case '1' => Produced 101 bytes of output, exit code 2

make: ./main: Command not found
makefile:8: recipe for target 'run' failed
make: *** [run] Error 127

FAIL Test 1: Error in empty string exception.
FAIL Test 2: Error in char not found exception.
FAIL Test 3: Error in empty result exception.
FAIL Test 4: Error in unequal size exception.
FAIL Test 5: Error in char not found exception.
FAIL Test 6: Error in empty string exception.
FAIL Test 7: Error in empty string exception.
FAIL Test 8: Error in empty result exception.
FAIL Test 9: Error in out of bounds exception.
FAIL Test 10: Error in out of bounds exception.
```

# Third last try:

```
Compile WARNING => Possible compile warnings and/or errors follow, try to get rid of them.
In file included from CharString.cpp:1:0:
CharString.h:5:34: fatal error: EmptyResultException.h: No such file or directory
compilation terminated.
makefile:5: recipe for target 'CharString' failed
make: *** [CharString] Error 1

Compile FAILURE
Execute FAILED
Test case '1' => Produced 101 bytes of output, exit code 2

make: ./main: Command not found
makefile:8: recipe for target 'run' failed
make: *** [run] Error 127

FAIL Test 1: Error in empty string exception.
FAIL Test 2: Error in char not found exception.
FAIL Test 3: Error in empty result exception.
FAIL Test 4: Error in unequal size exception.
FAIL Test 5: Error in char not found exception.
FAIL Test 6: Error in empty string exception.
FAIL Test 7: Error in empty string exception.
FAIL Test 8: Error in empty result exception.
FAIL Test 9: Error in out of bounds exception.
FAIL Test 10: Error in out of bounds exception.
```

# Forth last try:

```
Compile WARNING => Possible compile warnings and/or errors follow, try to get rid of them.
make: *** No rule to make target 'CharacterNotFoundException.h', needed by 'main'.  Stop.

Compile FAILURE
Execute FAILED
Test case '1' => Produced 101 bytes of output, exit code 2

make: ./main: Command not found
makefile:8: recipe for target 'run' failed
make: *** [run] Error 127

FAIL Test 1: Error in empty string exception.
FAIL Test 2: Error in char not found exception.
FAIL Test 3: Error in empty result exception.
FAIL Test 4: Error in unequal size exception.
FAIL Test 5: Error in char not found exception.
FAIL Test 6: Error in empty string exception.
FAIL Test 7: Error in empty string exception.
FAIL Test 8: Error in empty result exception.
FAIL Test 9: Error in out of bounds exception.
FAIL Test 10: Error in out of bounds exception.
```
