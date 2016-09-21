ofiles = main.o xAxis.o

main: $(ofiles)
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -o main $(ofiles)

main.o: main.cpp
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -c main.cpp

xAxis.o: xAxis.cpp xAxis.h
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -c xAxis.cpp

run: main
	./main

clean:
	rm *.o main *.tar.gz

compress:
	./compress.sh
