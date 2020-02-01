h65165
s 00007/00010/00002
d D 1.2 19/04/15 16:09:24 arslanr 2 1
c Project 2 version of makefile
e
s 00012/00000/00000
d D 1.1 19/03/10 14:59:29 arslanr 1 0
c date and time created 19/03/10 14:59:29 by arslanr
e
u
U
f e 0
t
T
I 1
D 2
Project1: homework3b.o dbfunctions.o
	gcc -o Project1 homework3b.o dbfunctions.o 

homework3b.o: homework3b.c dbfunctionsheaders.h record.h
	gcc -ansi -pedantic-errors -Wall -c homework3b.c

dbfunctions.o: dbfunctions.c dbfunctionsheaders.h record.h
	gcc -ansi -pedantic-errors -Wall -c dbfunctions.c

E 2
I 2
Project2: main.o llist.o
	g++ -o Project2 main.o llist.o
main.o: main.cpp llist.h record.h
	g++ -ansi -pedantic-errors -Wall -c main.cpp
llist.o: llist.cpp llist.h record.h
	g++ -ansi -pedantic-errors -Wall -c llist.cpp
E 2
clean:
D 2
	rm *.o Project1
E 2
I 2
	rm *.o Project2
E 2

E 1
