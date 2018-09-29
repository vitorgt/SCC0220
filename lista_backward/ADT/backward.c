#include<stdio.h>
#include<stdlib.h>
#include"backward.h"

int time = 0, ID = 0;

nodebackward *searchBACK(int j, backward *a){
	if(j < 0 || j >= ID) return NULL;
	nodebackward *aux = a->head;
	int i = 0;
	for(i = 0; i < j && aux; i++)
		aux = aux->next;
	return aux;
}

void insertBACK(int key, int j, backward *a){
	nodebackward *new = (nodebackward *)malloc(sizeof(nodebackward));
	new->key = key;
	new->ID = ID++;
	new->time = time++;
	new->next = NULL;
	new->back = search(j - new->ID, a);
	if(!(a->head))
		a->head = new;
	else
		a->tail->next = new;
	a->tail = new;
}

void removeBACK(int key, backward *a){
	if(a->head){
		
	}
}
