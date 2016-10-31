main.o: linkedList.h circularList.h ccListTest.o
	clang++ ccListTest.o -o main.o

ccListTest.o: ccListTest.cpp
	clang++ -c ccListTest.cpp

clean:
	rm *.o main

run: main.o
	./main.o
