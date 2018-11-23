all: jogando_bolas


jogando_bolas: jogando_bolas.c bt.o deque.o
	gcc jogando_bolas.c bt.o deque.o -o main -g
	rm *.o

deque.o: ADT/deque.c
	gcc ADT/deque.c -c -g

bt.o: ADT/bt.c deque.o
	gcc ADT/bt.c -c -g

run: jogando_bolas
	./main

zip:
	zip Makefile.zip *.c *.h Makefile ADT/*

val: jogando_bolas
	valgrind ./main -v --leak-check=full --track-origins=yes

