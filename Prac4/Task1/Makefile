main.out: titleCase.o backwards.o main.cpp
	g++ --std=c++14 -static titleCase.o backwards.o main.cpp -o main.out

#filter.o: filter.h
#	g++ --std=c++14 -c filter.h

titleCase.o: titleCase.cpp
	g++ --std=c++14 -c titleCase.cpp

backwards.o: backwards.cpp
	g++ --std=c++14 -c backwards.cpp

run: main.out
	./main.out

clean:
	rm *.o
	rm main
	rm *.tar.gz

compress:
	./compress.sh
