#ifndef BT_H
#define BT_H

typedef int typeBT;

typedef struct _bt{
	typeBT v;//value
	char f;//flag for left or right
	struct _bt *l, *r, *p;//left, right, parent
}bt;

void desalBT(bt *a);
typeBT maxBT(bt *a);
typeBT minBT(bt *a);
bt *searcBT(bt *a, typeBT k);
void printBT(bt *a, char o);
bt *removBT(bt **a, typeBT k);
void createFullBT(bt **a, int d);
void inserBT(bt **a, typeBT k);

#endif
