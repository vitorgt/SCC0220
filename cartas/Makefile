all: cartas


cartas: cartas.c deque.o
	gcc cartas.c deque.o -o main -g
	rm *.o

deque.o: ADT/deque.c
	gcc ADT/deque.c -c -g

run: cartas
	./main

zip:
	zip Makefile.zip *.c *.h Makefile ADT/*

val: cartas
	valgrind ./main -v --leak-check=full --track-origins=yes

