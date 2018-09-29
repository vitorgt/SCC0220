#include<stdio.h>
#include<stdlib.h>
#include"ADT/fifo.h"

typedef struct _newcolor{
	char c;
	int x, y;
}newcolor;

void allocM(char ***m, int l, int c){
	int i = 0;
	*m = (char **)calloc(l, sizeof(char *));
	for(; i < l; i++)
		*(*m + i) = (char *)calloc(c, sizeof(char));
}

void printM(char **m, int l, int c){
	int i = 0, j = 0;
	for(; i < l; i++){
		for(j = 0; j < c; j++)
			printf("%c", m[i][j]);
		printf("\n");
	}
}

void freeM(char ***m, int l){
	int i = 0;
	for(; i < l; i++)
		free(*(*m + i));
	free(*m);
}

void floodM(char **m, int l, int c, newcolor nc){
	fifo f;
	createFIFO(&f);
	char floodinicial = m[nc.y][nc.x];
	fifotype in; in.x = nc.x; in.y = nc.y;
	insertFIFO(in, &f);
	while(f.head){
		in = removeFIFO(&f);
		if(m[in.y][in.x] == floodinicial){
			m[in.y][in.x] = nc.c;
			fifotype card;
			if(in.x+1 < c){
				card.x = in.x+1; card.y = in.y;
				insertFIFO(card, &f);
			}
			if(in.x-1 >= 0){
				card.x = in.x-1; card.y = in.y;
				insertFIFO(card, &f);
			}
			if(in.y+1 < l){
				card.x = in.x; card.y = in.y+1;
				insertFIFO(card, &f);
			}
			if(in.y-1 >= 0){
				card.x = in.x; card.y = in.y-1;
				insertFIFO(card, &f);
			}
		}
	}
}

int main(){
	char **layer = NULL, *buffer = NULL;
	int c = 0, r = 0, i = 0, j = 0;
	newcolor nc;
	scanf("%d %d\n", &r, &c);
	allocM(&layer, r, c);
	for(i = 0; i < r; i++){
		for(j = 0; j < c; j++){
			scanf("%c", &layer[i][j]);
		}
		scanf(" ");//reads invisible caracters for line feed
	}
	while(scanf("%d %d %c", &nc.y, &nc.x, &nc.c) == 3){
		floodM(layer, r, c, nc);
		printM(layer, r, c);
	}
	freeM(&layer, r);
	return 0;
}
