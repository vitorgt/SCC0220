#ifndef BACKWARD_H
#define BACKWARD_H

typedef struct _nodeBACK{
	int key, time, ID;
	struct _nodeBACK *back, *next;
}nodeBACK;

typedef struct _BACK{
	nodeBACK *head, *tail;
}BACK;

void initializeBACK(BACK *a);
void deleteBACK(BACK *a);
nodeBACK *searchBACK(int j, BACK *a);
void insertBACK(int key, int j, BACK *a);
void update_idsBACK(BACK *a);
void remove_refBACK(nodeBACK *key, BACK *a);
void removeBACK(int key, BACK *a);
void printBACK(BACK *a);

#endif
