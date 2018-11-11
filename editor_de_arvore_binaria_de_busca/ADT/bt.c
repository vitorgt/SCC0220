#include<stdio.h>
#include<stdlib.h>
#include"bt.h"

#define inf 0x7fffffff

void desalBT(bt *a){//desaloca a arvore inteira
	if(a){
		desalBT(a->l);
		desalBT(a->r);
		free(a);
	}
}

typeBT maxBT(bt *a){
	if(a){//se a for nao nulo
		while(a->r)//enquanto existirem filhos para a direita
			a = a->r;//a recebe o filho da direita
		return a->v;//por fim a tera o no mais a direita da arvore (max)
	}
	else//se a for nulo
		return inf;//retorna erro
}

bt *searcBT(bt *a, typeBT k){//procura o endereco do no com dada chave
	while(a){//enquanto a for nao nulo
		if(a->v == k)//se for o valor procurado
			return a;
		if(a->v > k)//se o no atual tiver uma chave maior que a procurada
			a = a->l;//vai para a esquerda
		else//senao vai para a direita
			a = a->r;
	}
	return NULL;
}

void printBT(bt *a, char o){//imprime a arvore (ou subarvore)
	if(a){
		if(o == 'E'){		//pre order
			printf(" %d", a->v);
			printBT(a->l, o);
			printBT(a->r, o);
		}
		else if(o == 'O'){	//post order
			printBT(a->l, o);
			printBT(a->r, o);
			printf(" %d", a->v);
		}
		else{			//in order
			printBT(a->l, o);
			printf(" %d", a->v);
			printBT(a->r, o);
		}
	}
}

bt *removBT(bt **a, typeBT k){
	bt *found = searcBT(*a, k);
	if(found){
		if(found->l == NULL && found->r == NULL){//se nao tem filhos
			if(found->p){//se tem pai (nao eh a raiz)
				if(found->p->l == found)
					found->p->l = NULL;
				else
					found->p->r = NULL;
			}
			else//se eh a raiz
				*a = NULL;//so esvazia a arvore
		}
		else if(found->l != NULL && found->r == NULL){//se so tem esquerda
			if(found->p){//se tem pai (nao eh a raiz)
				if(found->p->l == found)
					found->p->l = found->l;
				else
					found->p->r = found->l;
			}
			else//se eh a raiz
				*a = found->l;
		}
		else if(found->l == NULL && found->r != NULL){//se so tem direita
			if(found->p){//se tem pai (nao eh a raiz)
				if(found->p->l == found)
					found->p->l = found->r;
				else
					found->p->r = found->r;
			}
			else//se eh a raiz
				*a = found->r;
		}
		else if(found->l != NULL && found->r != NULL){//se tem os dois filhos
			typeBT tmp = maxBT(found->l);
			free(removBT(a, tmp));
			found->v = tmp;
		}
		return found;
	}
	return NULL;
}

void inserBT(bt **a, typeBT k){
	bt *newn = (bt *)calloc(1, sizeof(bt));
	newn->v = k;//recebe os dados
	if(!(*a))//se a raiz for nula (primeiro caso)
		*a = newn;
	else{
		bt *aux = *a;
		while(aux){
			if(aux->v > newn->v){//se o no a ser colocado for menor
				if(aux->l)//se existir filho para a direita
					aux = aux->l;//vai para a direita e reitera
				else{//se nao tiver filho para a esquerda
					aux->l = newn;//coloca o novo no aqui
					newn->p = aux;
					break;//finalizado
				}
			}
			else{//similar acima
				if(aux->r)
					aux = aux->r;
				else{
					aux->r = newn;
					newn->p = aux;
					break;
				}
			}
		}
	}
}
