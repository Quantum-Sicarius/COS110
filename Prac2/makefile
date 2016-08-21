main.out: Adventurer.o  main.cpp
	g++ --std=c++14 Adventurer.o  main.cpp -o main.out


Adventurer.o: Adventurer.cpp
	g++ --std=c++14 -c Adventurer.cpp

run: main.out
	./main.out
