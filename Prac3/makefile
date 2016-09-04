main: book.o library.o librarian.o main.cpp
	g++ --std=c++14 book.o library.o librarian.o main.cpp -o main

book.o: book.cpp
	g++ --std=c++14 -c book.cpp

library.o: library.cpp
	g++ --std=c++14 -c library.cpp

librarian.o: librarian.cpp
	g++ --std=c++14 -c librarian.cpp


run: main
	./main

clean:
	rm *.o
	rm main
