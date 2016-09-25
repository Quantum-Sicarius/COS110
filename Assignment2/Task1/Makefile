ofiles = main.o Cipher.o SubstitutionCipher.o Caesar.o OneTimePad.o

main: $(ofiles)
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -o main $(ofiles)

main.o: main.cpp
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -c main.cpp

Caesar.o: Caesar.cpp Caesar.h
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -c Caesar.cpp

SubstitutionCipher.o: SubstitutionCipher.h
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -c SubstitutionCipher.cpp

Cipher.o: Cipher.h Cipher.cpp
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -c Cipher.cpp

OneTimePad.o: OneTimePad.h OneTimePad.cpp
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -c OneTimePad.cpp

run: main
	./main

clean:
	rm *.o main *.tar.gz

compress:
	./compress.sh
