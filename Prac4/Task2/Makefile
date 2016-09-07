ofiles =  main-prac4-task2.o person.o student.o staff.o

main: $(ofiles)
	g++ -o main $(ofiles)

main-prac4-task2.o: main-prac4-task2.cpp
	g++ -c main-prac4-task2.cpp

person.o: person.cpp person.h
	g++ -c person.cpp

student.o: student.cpp student.h
	g++ -c student.cpp

staff.o: staff.cpp staff.h
	g++ -c staff.cpp

run: main
	./main

clean:
	rm *.o main rm *.tar.gz

compress:
	./compress.sh
