all: main


main: lista_backward.c backward.o
	gcc lista_backward.c backward.o -o main -g
	rm *.o

backward.o: ADT/backward.c
	gcc ADT/backward.c -c -g

run: main
	./main

zip:
	zip Makefile.zip *.c *.h Makefile ADT/*

val: main
	valgrind ./main -v --leak-check=full --track-origins=yes

