main.o: linkedList.h linkTest.o
	clang++ -g -pedantic -Weverything -fsanitize=address -fstack-protector linkTest.o -o main.o

linkTest.o: linkTest.cpp
	clang++ -g -pedantic -Weverything -fsanitize=address -fstack-protector -c linkTest.cpp

clean:
	rm *.o main

run: main.o
	ASAN_OPTIONS=symbolize=1 ASAN_SYMBOLIZER_PATH=$(shell which llvm-symbolizer) ./main.o
