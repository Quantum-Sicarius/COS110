# Task 1

```
Execute FAILED
Test case '1' => Produced 159 bytes of output, exit code 2

ERROR: invalid index
[a]
[a,b]
[a,c,b]
[a,c,d,b]
ERROR: invalid index
[a,c,d,b]
makefile:11: recipe for target 'run' failed
make: *** [run] Segmentation fault

Test 1 passed: Correct error thrown for insert(int, T).
Test 2 passed: Correct ostream output, and insert(int,T).
Test 3 passed: Correct ostream output, and insert(int,T).
Test 4 passed: Correct ostream output, and insert(int,T).
Test 5 passed: Correct ostream output, and insert(int,T).
Test 6 passed: Correct error thrown for insert(int,T).
Test passed: Correct ostream output, and Copy constructor.
Test 1 failed: Incorrect errors for get(int) or errors are not being thrown.
Test 2 failed: Incorrect value returned from get(int) and/or function is changing the list.
Test 3 failed: Incorrect value returned from get(int) and/or function is changing the list.
Test 1 failed: Incorrect errors for operator[] or errors are not being thrown.
Test 2 failed: Incorrect value returned from operator[].
Test 3 failed: Incorrect implementation for operator[]. The list should not have changed.
Test 1 failed: Incorrect errors for remove(int) or errors are not being thrown.
Test 2 failed: Incorrect ostream output and/or remove(int). Remember to return a value. Test removing from in between.
Test 3 failed: Incorrect ostream output and/or remove(int). Remember to return a value. Test removing from in between.
Test 4 failed: Incorrect ostream output and/or remove(int). Remember to return a value. Test removing from tail.
Test 5 failed: Incorrect ostream output and/or remove(int). Remember to return a value. Test removing from head.
Test 6 failed: Incorrect errors for remove(int) or errors are not being thrown.
Test failed: operator=(const LinkedList<T>&) does not replace the list correctly.
Test failed: operator+(int) does not return an appended list correctly.
```
