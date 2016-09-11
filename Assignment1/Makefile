ofiles = main.o lecturer_phd.o lecturer_msc.o learning_machine.o person.o student.o staff.o

main: $(ofiles)
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -o main $(ofiles)

main.o: main.cpp
	g++ --Wall -Wextra -Werror -pedantic -std=c++11 -c main.cpp

learning_machine.o: learning_machine.cpp learning_machine.h
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -c learning_machine.cpp

lecturer_msc.o: lecturer_msc.cpp lecturer_msc.h
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -c lecturer_msc.cpp

lecturer_phd.o: lecturer_phd.cpp lecturer_phd.h
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -c lecturer_phd.cpp

person.o: person.cpp person.h
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -c person.cpp

student.o: student.cpp student.h
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -c student.cpp

staff.o: staff.cpp staff.h
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -c staff.cpp

run: main
	./main

clean:
	rm *.o main *.tar.gz

compress:
	./compress.sh
