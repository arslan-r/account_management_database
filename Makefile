Project2: main.o llist.o
	g++ -o Project2 main.o llist.o
main.o: main.cpp llist.h record.h
	g++ -ansi -pedantic-errors -Wall -c main.cpp
llist.o: llist.cpp llist.h record.h
	g++ -ansi -pedantic-errors -Wall -c llist.cpp
clean:
	rm *.o Project2

