#ifndef BACKWARD_H
#define BACKWARD_H

typedef struct _nodebackward{
	int key, time, ID;
	struct _backward *back, *next;
}nodebackward;

typedef struct _backward{
	nodebackward *head, *tail;
}backward;

#endif
