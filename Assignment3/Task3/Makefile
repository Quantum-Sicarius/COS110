main.o: linkedList.h doubleList.h dListTest.o
	clang++ -g dListTest.o -o main.o

dListTest.o: dListTest.cpp
	clang++ -g -c dListTest.cpp

clean:
	rm *.o main

run: main.o
	./main.o
