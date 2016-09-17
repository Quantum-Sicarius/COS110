ofiles = main.o Exception.o CharString.o

main: $(ofiles)
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -static -o main $(ofiles)

main.o: main.cpp
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -c main.cpp

Exception.o: Exception.cpp Exception.h
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -c Exception.cpp

CharString.o: CharString.cpp CharString.h
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -c CharString.cpp

debug: $(ofiles)
	g++ -g -Wall -Wextra -Werror -pedantic -std=c++11 -static -o main $(ofiles)

run: main
	./main

clean:
	rm *.o main *.tar.gz

compress:
	./compress.sh
