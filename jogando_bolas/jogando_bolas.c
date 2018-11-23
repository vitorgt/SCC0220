#include<stdio.h>
#include<stdlib.h>
#include"ADT/bt.h"

int main(){
	int d = 0, b = 0, last = 0;;
	bt *ward = NULL, *aux = NULL;
	scanf("%d %d", &d, &b);
	createFullBT(&ward, d);
	while(b--){
		int count = d-1;
		aux = ward;
		while(count--){
			aux->f = !(aux->f);
			if(aux->f){//go left
				aux = aux->l;
			}else{//go right
				aux = aux->r;
			}
		}
		last = aux->v+(1<<(d-1));
		//printf("Bola #%3d: parou %3d\n", b, aux->v+(1<<(d-1)));
	}
	printf("%d\n", last);
	desalBT(ward);//desaloca toda a arvore
	return 0;
}
