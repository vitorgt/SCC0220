#include<stdio.h>
#include<stdlib.h>
#include"ADT/backward.h"

int main(){
	int i = 0, key = 0, back = 0;
	char op = 0;
	BACK bw;
	initializeBACK(&bw);
	while(op != 'f'){
		scanf("%c ", &op);
		if(op == 'i'){
			scanf("%d %d ", &key, &back);
			insertBACK(key, back, &bw);
		}
		if(op == 'r'){
			scanf("%d ", &key);
			removeBACK(key, &bw);
		}
	}
	printBACK(&bw);
	deleteBACK(&bw);
	return 0;
}
