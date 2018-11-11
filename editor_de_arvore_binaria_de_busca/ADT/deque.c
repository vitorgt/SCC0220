#include<stdio.h>
#include<stdlib.h>
#include"deque.h"

void push_frontDEQUE(deque *a, typeDEQUE data){
	nodeDEQUE *n = (nodeDEQUE *)malloc(sizeof(nodeDEQUE));
	n->data = data;
	n->next = a->head;
	n->prev = NULL;
	if(a->tail == NULL)
		a->head = a->tail = n;
	else{
		a->head->prev = n;
		a->head = n;
	}
}

void push_backDEQUE(deque *a, typeDEQUE data){
	nodeDEQUE *n = (nodeDEQUE *)malloc(sizeof(nodeDEQUE));
	n->data = data;
	n->prev = a->tail;
	n->next = NULL;
	if(a->head == NULL)
		a->head = a->tail = n;
	else{
		a->tail->next = n;
		a->tail = n;
	}
}

typeDEQUE pop_frontDEQUE(deque *a){
	if(a->head){
		typeDEQUE data = a->head->data;
		nodeDEQUE *n = a->head;
		if(a->head == a->tail)
			a->head = a->tail = NULL;
		else{
			a->head = a->head->next;
			a->head->prev = NULL;
		}
		free(n);
		return data;
	}
	return NULL;
}

typeDEQUE pop_backDEQUE(deque *a){
	if(a->head){
		typeDEQUE data = a->tail->data;
		nodeDEQUE *n = a->tail;
		if(a->head == a->tail)
			a->head = a->tail = NULL;
		else{
			a->tail = a->tail->prev;
			a->tail->next = NULL;
		}
		free(n);
		return data;
	}
	return NULL;
}

typeDEQUE peek_frontDEQUE(deque *a){
	return a->head->data;
}

typeDEQUE peek_backDEQUE(deque *a){
	return a->tail->data;
}

void createDEQUE(deque *a){
	a->head = NULL;
	a->tail = NULL;
}

void removeDEQUE(deque *a){
	while(a->head)
		pop_frontDEQUE(a);
}

void printDEQUE(deque a){
	nodeDEQUE *aux = a.head;
	while(aux){
		printf("%p ", (void *)aux->data);
		aux = aux->next;
	}
	printf("\n");
}
