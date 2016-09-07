main: titleCase.o backwards.o filter.o main.cpp
	g++ --std=c++14 -static filter.o titleCase.o backwards.o main.cpp -o main

filter.o: filter.cpp
	g++ --std=c++14 -c filter.cpp

titleCase.o: titleCase.cpp
	g++ --std=c++14 -c titleCase.cpp

backwards.o: backwards.cpp
	g++ --std=c++14 -c backwards.cpp

run: main
	./main

clean:
	rm *.o
	rm main
	rm *.tar.gz

compress:
	./compress.sh
