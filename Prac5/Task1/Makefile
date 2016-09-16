ofiles = main.o exception.o

main: $(ofiles)
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -static -o main $(ofiles)

main.o: main.cpp
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -c main.cpp

exception.o: Exception.cpp Exception.h
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -c Exception.cpp

run: main
	./main

clean:
	rm *.o main *.tar.gz

compress:
	./compress.sh
