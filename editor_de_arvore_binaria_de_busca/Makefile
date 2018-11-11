all: abb


abb: abb.c bt.o
	gcc abb.c bt.o -o main -g
	rm *.o

bt.o: ADT/bt.c
	gcc ADT/bt.c -c -g

run: abb
	./main

zip:
	zip Makefile.zip *.c *.h Makefile ADT/*

val: abb
	valgrind ./main -v --leak-check=full --track-origins=yes

