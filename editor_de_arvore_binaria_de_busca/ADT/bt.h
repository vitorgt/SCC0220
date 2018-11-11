#ifndef BT_H
#define BT_H

typedef int typeBT;

typedef struct _bt{
	typeBT v;//value
	struct _bt *l, *r, *p;//left, right, parent
}bt;

void desalBT(bt *a);
typeBT maxBT(bt *a);
bt *searcBT(bt *a, typeBT k);
void printBT(bt *a, char o);
bt *removBT(bt **a, typeBT k);
void inserBT(bt **a, typeBT k);

#endif