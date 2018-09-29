#ifndef FIFO_H
#define FIFO_H

typedef struct _fifotype{
	int x, y;
}fifotype;

typedef struct _nodeFIFO{
	fifotype data;
	struct _nodeFIFO *next;
}nodeFIFO;

typedef struct _fifo{
	nodeFIFO *head, *tail;
}fifo;

void insertFIFO(fifotype data, fifo *a);
fifotype removeFIFO(fifo *a);
void createFIFO(fifo *a);
int isemptyFIFO(fifo a);
fifotype topFIFO(fifo a);
void printFIFO(fifo a);

#endif
