#ifndef DEQUE_H
#define DEQUE_H

typedef void *typeDEQUE;

typedef struct _nodeDEQUE{
	typeDEQUE data;
	struct _nodeDEQUE *next, *prev;
}nodeDEQUE;

typedef struct _deque{
	nodeDEQUE *head, *tail;
}deque;

void push_frontDEQUE(deque *a, typeDEQUE data);
void push_backDEQUE(deque *a, typeDEQUE data);
typeDEQUE pop_frontDEQUE(deque *a);
typeDEQUE pop_backDEQUE(deque *a);
typeDEQUE peek_frontDEQUE(deque *a);
typeDEQUE peek_backDEQUE(deque *a);
void createDEQUE(deque *a);
void removeDEQUE(deque *a);
void printDEQUE(deque a);

#endif
