ofiles = main.o RowsColumns.o TranspositionCipher.o ZigZag.o
main: $(ofiles)
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -o main $(ofiles)

main.o: main.cpp
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -c main.cpp

RowsColumns.o: RowsColumns.cpp RowsColumns.h
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -c RowsColumns.cpp

ZigZag.o: ZigZag.cpp ZigZag.h
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -c ZigZag.cpp

TranspositionCipher.o: TranspositionCipher.h TranspositionCipher.cpp
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -c TranspositionCipher.cpp

run: main
	./main

clean:
	rm *.o main *.tar.gz

compress:
	./compress.sh
