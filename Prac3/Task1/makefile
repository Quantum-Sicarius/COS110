main: book.o  main.cpp
	g++ --std=c++14 -static book.o  main.cpp -o main


book.o: book.cpp
	g++ --std=c++14 -c book.cpp

run: main
	./main
