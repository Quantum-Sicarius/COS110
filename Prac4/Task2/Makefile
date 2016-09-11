ofiles =  main-prac4-task2.o person.o student.o staff.o

main: $(ofiles)
	g++ -o main $(ofiles)

main-prac4-task2.o: main-prac4-task2.cpp
	g++ -Wall -Wextra -Werror -pedantic -std=c++11 -c -static main-prac4-task2.cpp

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
