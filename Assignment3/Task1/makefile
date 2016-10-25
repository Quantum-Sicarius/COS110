main.o: linkedList.h linkTest.o
	clang++ linkTest.o -o main.o

linkTest.o: linkTest.cpp
	clang++ -c linkTest.cpp

clean:
	rm *.o main

run: main.o
	./main.o
