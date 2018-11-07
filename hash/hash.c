#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ADT/deque.h"

#define MAX 2000

void removeHASH(deque *h){
	while(h->head){
		char *buffer = pop_frontDEQUE(h);
		if(buffer) free(buffer);
	}
}

void remove_itemHASH(deque *h, char *search){
	int i = countDEQUE(*h);
	while(i--){
		if(strcmp(h->head->data, search) == 0){
			pop_frontDEQUE(h);
		}
		else{
			push_backDEQUE(h, pop_frontDEQUE(h));
		}
	}
}

void printHASH(deque *h){
	for(int i = 0; i < MAX; i++){
		//printf("%4d:%s\n", i, h[i].head->data);
		printDEQUE(h[i]);
	}
	printf("\n");
}

int hash(char *line){
	if(line){
		int i = 0, sum = 0, size = strlen(line);
		for(i = 0; i < size; i++){
			if(i%2){
				sum += ((int)line[i]-'a')*23;
			}
			else{
				sum += ((int)line[i]-'a')*17;
			}
			if(i%3){
				sum += ((int)line[i]-'a')*43;
			}
		}
		return sum;
	}
	return 0;
}

int main(){
	char op = 0, *buffer = NULL;

	deque *h = (deque *)calloc(MAX, sizeof(deque));
	for(int i = 0; i < MAX; i++)
		createDEQUE(&h[i]);

	while(op != 'f'){
		scanf("%c %m[^\r\n]%*[\r\n]", &op, &buffer);
		printf("%c\t%d\t%s\n", op, hash(buffer), buffer);
		if(op == 'i'){
			push_backDEQUE(&h[hash(buffer)], buffer);
			printDEQUE(h[hash(buffer)]);
		}
		else if(op == 'b'){
			if(findDEQUE(h[hash(buffer)], buffer))
				printf("encontrado\n");
			else
				printf("nao encontrado\n");
			free(buffer);
		}
		else if(op == 'r'){
			remove_itemHASH(&h[hash(buffer)], buffer);
			free(buffer);
		}
		printHASH(h);
	}
	for(int i = 0; i < MAX; i++)
		removeHASH(&h[i]);
	free(h);
	return 0;
}
