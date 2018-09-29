all: pintura_de_tela


pintura_de_tela: pintura_de_tela.c fifo.o
	gcc pintura_de_tela.c fifo.o -o main -g
	rm *.o

fifo.o: ADT/fifo.c
	gcc ADT/fifo.c -c

run: pintura_de_tela
	./main

zip:
	zip Makefile.zip *.c *.h Makefile ADT/*

val: pintura_de_tela
	valgrind ./main -v --leak-check=full --track-origins=yes

