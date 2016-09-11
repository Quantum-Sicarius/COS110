ofiles = main.o Hobbit.o Spell.o Wizard.o

main: $(ofiles)
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -o main $(ofiles)

main.o: main.cpp
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -c main.cpp

Hobbit.o: Hobbit.cpp Hobbit.h
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -c Hobbit.cpp

Spell.o: Spell.cpp Spell.h
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -c Spell.cpp

Wizard.o: Wizard.cpp Wizard.h
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -c Wizard.cpp

run: main
	./main

clean:
	rm *.o main *.tar.gz

compress:
	./compress.sh
