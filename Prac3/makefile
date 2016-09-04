main: book.o library.o main.cpp
	g++ --std=c++14 book.o library.o main.cpp -o main

book.o:
	g++ --std=c++14 -c book.cpp

library.o: library.cpp
	g++ --std=c++14 -c library.cpp

run: main
	./main

clean:
	rm *.o
