#include<stdio.h>
#include<stdlib.h>
#include"fifo.h"

void insertFIFO(fifotype data, fifo *a){
	nodeFIFO *new = (nodeFIFO *)malloc(sizeof(nodeFIFO));
	new->data = data;
	new->next = NULL;
	if(!(a->head))
		a->head = new;
	else
		a->tail->next = new;
	a->tail = new;
}

fifotype removeFIFO(fifo *a){
	if(!(a->head))
		printf("Nothing to remove\n");
	nodeFIFO *temp = a->head;
	fifotype resu = a->head->data;
	a->head = a->head->next;
	free(temp);
	return resu;
}

void createFIFO(fifo *a){
	a->head = NULL;
	a->tail = NULL;
}

int isemptyFIFO(fifo a){
	if(!(a.head)) return 1;
	return 0;
}

fifotype topFIFO(fifo a){
	if(!(a.head)){
		printf("Nothing\n");
		fifotype re;
		re.x = 0; re.y = 0;
		return re;
	}
	return a.head->data;
}

void printFIFO(fifo a){
	//works only if fifotype is int
	nodeFIFO *aux = a.head;
	while(aux){
		//printf("%d ", aux->data);
		aux = aux->next;
	}
	printf("\n");
}

