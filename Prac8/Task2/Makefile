g++ = g++ -std=c++11 -g

main: animals.o main.o
	$(g++) main.o animals.o -o main

main.o: main.cpp
	$(g++) -c main.cpp

animals.o: animals.cpp animals.h
	$(g++) -c animals.cpp

run: main
	./main

clean:
	-rm *.o main