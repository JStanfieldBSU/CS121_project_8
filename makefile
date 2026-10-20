program: Address.o Date.o Student.o main.o
	g++ -g Address.o Date.o Student.o main.o -o program

main.o: Address.h Date.h Student.h main.cpp
	g++ -c -g main.cpp

Address.o: Address.h Address.cpp
	g++ -c -g Address.cpp

Date.o: Date.h Date.cpp
	g++ -c -g Date.cpp

Student.o: Address.h Date.h Student.h Student.cpp
	g++ -c -g Student.cpp

clean:
	rm *.o
	rm program

run: program
	./program

debug: program
	gdb program
