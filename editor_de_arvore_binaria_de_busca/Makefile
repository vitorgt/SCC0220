all: abb


abb: abb.c bt.o deque.o
	gcc abb.c bt.o deque.o -o main -g
	rm *.o

deque.o: ADT/deque.c
	gcc ADT/deque.c -c -g

bt.o: ADT/bt.c deque.o
	gcc ADT/bt.c -c -g

run: abb
	./main

zip:
	zip Makefile.zip *.c *.h Makefile ADT/*

val: abb
	valgrind ./main -v --leak-check=full --track-origins=yes

