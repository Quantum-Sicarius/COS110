ofiles = main.o Cipher.o CipherPipeline.o SubstitutionCipher.o OneTimePad.o Caesar.o TranspositionCipher.o RowsColumns.o ZigZag.o
CXX = clang++
flags = -Wall -Wextra -Werror -pedantic -std=c++11

main: $(ofiles)
	$(CXX) $(ofiles) $(flags) -o main

main.o: main.cpp Cipher.h
	$(CXX) $(flags) -c main.cpp

Cipher.o: Cipher.cpp Cipher.h
	$(CXX) $(flags) -c Cipher.cpp

CipherPipeline.o: CipherPipeline.cpp CipherPipeline.h Cipher.h
	$(CXX) $(flags) -c CipherPipeline.cpp

SubstitutionCipher.o: SubstitutionCipher.cpp SubstitutionCipher.h Cipher.h
	$(CXX) $(flags) -c SubstitutionCipher.cpp

OneTimePad.o: OneTimePad.cpp OneTimePad.h SubstitutionCipher.h Caesar.h
	$(CXX) $(flags) -c OneTimePad.cpp

Caesar.o: Caesar.cpp Caesar.h SubstitutionCipher.h
	$(CXX) $(flags) -c Caesar.cpp

TranspositionCipher.o: TranspositionCipher.cpp TranspositionCipher.h Cipher.h
	$(CXX) $(flags) -c TranspositionCipher.cpp

RowsColumns.o: RowsColumns.cpp RowsColumns.h TranspositionCipher.h
	$(CXX) $(flags) -c RowsColumns.cpp

ZigZag.o: ZigZag.cpp ZigZag.h TranspositionCipher.h
	$(CXX) $(flags) -c ZigZag.cpp

run: main
	./main

clean:
	rm *.o main *~
