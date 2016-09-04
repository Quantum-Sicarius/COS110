main: book.o library.o main.cpp
	g++ --std=c++14 ../Task1/book.o library.o  main.cpp -o main

book.o:
	cd ../Task1; make

library.o: library.cpp
	g++ --std=c++14 -c library.cpp

run: main
	./main
