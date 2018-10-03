#include<stdio.h>
#include<stdlib.h>
#include"backward.h"

int time = 0, ID = 0;

void initializeBACK(BACK *a){
	if(a){
		a->head = NULL;
		a->tail = NULL;
	}
}

void deleteBACK(BACK *a){
	if(a){
		nodeBACK *aux = a->head;
		while(aux){
			nodeBACK *tmp = aux;
			aux = aux->next;
			free(tmp);
		}
		initializeBACK(a);
	}
}

nodeBACK *searchBACK(int j, BACK *a){
	if(j < 0 || j >= ID) return NULL;
	nodeBACK *aux = a->head;
	int i = 0;
	for(i = 0; i < j && aux; i++)
		aux = aux->next;
	return aux;
}

void insertBACK(int key, int j, BACK *a){
	nodeBACK *new = (nodeBACK *)malloc(sizeof(nodeBACK));
	new->key = key;
	new->ID = ID++;
	new->time = time++;
	new->next = NULL;
	if(j == 0)
		new->back = NULL;
	else
		new->back = searchBACK(new->ID - j, a);
	if(!(a->head))
		a->head = new;
	else
		a->tail->next = new;
	a->tail = new;
}

void update_idsBACK(BACK *a){
	if(a->head){
		nodeBACK *aux = a->head;
		ID = 0;
		while(aux){
			aux->ID = ID++;
			aux = aux->next;
		}
	}
}

void remove_refBACK(nodeBACK *key, BACK *a){
	if(a->head){
		nodeBACK *aux = a->head;
		while(aux){
			if(aux->back == key){
				aux->back = NULL;
			}
			aux = aux->next;
		}
	}
}

void removeBACK(int key, BACK *a){
	if(a->head){
		nodeBACK *aux = a->head;
		if(a->head->key == key){
			time++;
			a->head = a->head->next;
			remove_refBACK(aux, a);
			free(aux);
			update_idsBACK(a);
			return;
		}
		while(aux){
			if(aux->next->key == key){
				time++;
				nodeBACK *fre = aux->next;
				aux->next = aux->next->next;
				remove_refBACK(fre, a);
				free(fre);
				update_idsBACK(a);
				return;
			}
			aux = aux->next;
		}
	}
}

void printBACK(BACK *a){
	nodeBACK *aux = a->head;
	if(!aux)
		printf("%d", -1);
	else
		while(aux){
			printf("[%d,%d", aux->key, aux->time);
			if(aux->back) printf(",%d", aux->back->ID);
			printf("] ");
			aux = aux->next;
		}
	printf("\n");
}
