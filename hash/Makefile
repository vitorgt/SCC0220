all: hash


hash: hash.c deque.o
	gcc hash.c deque.o -o main -g
	rm *.o

deque.o: ADT/deque.c
	gcc ADT/deque.c -c -g

run: main
	./main

zip:
	zip Makefile.zip *.c *.h Makefile ADT/*

val: main
	valgrind ./main -v --leak-check=full --track-origins=yes

