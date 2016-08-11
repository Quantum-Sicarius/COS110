rain.out: arrayUtilities.o  rainfall.cpp
	g++ --std=c++14 arrayUtilities.o  rainfall.cpp -o rain.out


arrayUtilities.o: arrayUtilities.cpp arrayUtilities.cpp
	g++ --std=c++14 -c arrayUtilities.cpp

run: rain.out
	./rain.out
