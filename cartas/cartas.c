#include<stdio.h>
#include"ADT/deque.h"

int main(){
	int op = 0, buffer = 0;
	scanf("%d\n", &op);
	while(op--){
		int last = 0;
		deque d, ans;
		createDEQUE(&d);
		createDEQUE(&ans);
		while(1){
			scanf("%d", &buffer);
			if(buffer == 0) break;
			push_backDEQUE(&d, buffer);
		}
		while(d.head){
			if(d.head) push_backDEQUE(&ans, pop_frontDEQUE(&d));
			if(d.head) push_backDEQUE(&d, pop_frontDEQUE(&d));
		}
		last = pop_backDEQUE(&ans);
		printf("Cartas jogadas: ");
		printDEQUE(ans);
		printf("Carta restante: %d\n", last);
		removeDEQUE(&d);
		removeDEQUE(&ans);
	}
	return 0;
}
