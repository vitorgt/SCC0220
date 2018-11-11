#include<stdio.h>
#include<stdlib.h>
#include"ADT/bt.h"
#include"ADT/deque.h"

int main(){
	int in = 0;
	char op = 0;
	bt *ward = NULL;
	scanf("%c", &op);
	while(op != 'X'){
		if(op == 'I'){
			scanf(" %d\n", &in);
			bt *found = searcBT(ward, in);
			if(found)
				printf("Chave existente\n");
			else
				inserBT(&ward, in);
		}
		else if(op ==  'D'){
			scanf(" %d\n", &in);
			bt *rm = removBT(&ward, in);
			if(rm){
				printf("%d\n", rm->v);
				free(rm);
			}
			else
				printf("Nao encontrado\n");
		}
		else if(op ==  'B'){
			scanf(" %d\n", &in);
			if(searcBT(ward, in))
				printf("Encontrado\n");
			else
				printf("Nao encontrado\n");
		}
		else if(op ==  'N'){
			printf("InOrdem: ");
			printBT(ward, op);
			printf("\n");
		}
		else if(op ==  'E'){
			printf("PreOrdem: ");
			printBT(ward, op);
			printf("\n");
		}
		else if(op ==  'O'){
			printf("PosOrdem: ");
			printBT(ward, op);
			printf("\n");
		}
		else if(op ==  'L'){
			printf("Largura: ");
			printBT(ward, op);
			printf("\n");
		}
		else if(op ==  'Y'){
			printf("InOrdem: ");
			printBT(ward, 'N');
			printf("\n");
			printf("PreOrdem: ");
			printBT(ward, 'E');
			printf("\n");
			printf("PosOrdem: ");
			printBT(ward, 'O');
			printf("\n");
			printf("Largura: ");
			printBT(ward, 'L');
			printf("\n");
		}
		scanf("%c", &op);
	}
	desalBT(ward);//desaloca toda a arvore
	return 0;
}
