#include<stdio.h>
#include<stdlib.h>
#include"bt.h"
#include"deque.h"

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
		if(a){
			if(a->v == k)//se for o valor procurado
				return a;
			if(a->v > k)//se o no atual tiver uma chave maior que a procurada
				a = a->l;//vai para a esquerda
			else//senao vai para a direita
				a = a->r;
		}
		else{
			return NULL;
		}
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
		if(o == 'O'){		//post order
			printBT(a->l, o);
			printBT(a->r, o);
			printf(" %d", a->v);
		}
		if(o == 'N'){		//in order
			printBT(a->l, o);
			printf(" %d", a->v);
			printBT(a->r, o);
		}
		if(o == 'L'){		//breadth-first
			deque *tovisit = NULL, *visited = NULL;
			tovisit = (deque *)calloc(1, sizeof(deque));
			visited = (deque *)calloc(1, sizeof(deque));
			createDEQUE(tovisit);
			createDEQUE(visited);
			push_backDEQUE(tovisit, a);
			while(tovisit->head != NULL){
				bt *now = pop_frontDEQUE(tovisit);
				if(now->l) push_backDEQUE(tovisit, now->l);
				if(now->r) push_backDEQUE(tovisit, now->r);
				push_backDEQUE(visited, now);
			}
			while(visited->head != NULL)
				printf(" %d", ((bt *)pop_frontDEQUE(visited))->v);
			free(tovisit);
			free(visited);
		}
	}
}

bt *removBT(bt **a, typeBT k){
	bt *found = searcBT(*a, k);
	if(found){
		if(found->l == NULL && found->r == NULL){//se nao tem filhos
			if(found->p){//se tem pai (nao eh a raiz)
				if(found->p->l == found){
					found->p->l = NULL;
				}
				else{
					found->p->r = NULL;
				}
			}
			else{//se eh a raiz
				*a = NULL;//so esvazia a arvore
			}
		}
		else if(found->l != NULL && found->r == NULL){//se so tem esquerda
			if(found->p){//se tem pai (nao eh a raiz)
				if(found->p->l == found){
					found->p->l = found->l;
				}
				else{
					found->p->r = found->l;
				}
				found->l->p = found->p;
			}
			else{//se eh a raiz
				found->l->p = NULL;
				*a = found->l;
			}
		}
		else if(found->l == NULL && found->r != NULL){//se so tem direita
			if(found->p){//se tem pai (nao eh a raiz)
				if(found->p->l == found){
					found->p->l = found->r;
				}
				else{
					found->p->r = found->r;
				}
				found->r->p = found->p;
			}
			else{//se eh a raiz
				found->r->p = NULL;
				*a = found->r;
			}
		}
		else if(found->l != NULL && found->r != NULL){//se tem os dois filhos
			typeBT tmp = maxBT(found->l), bkp = found->v;
			if(tmp != inf){
				free(removBT(a, tmp));
				found->v = tmp;
				found = (bt *)calloc(1, sizeof(bt));
				found->v = bkp;
			}
			else
				return NULL;
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
				if(aux->l)//se existir filho para a esquerda
					aux = aux->l;//vai para a esquerda e reitera
				else{//se nao tiver filho para a esquerda
					aux->l = newn;//coloca o novo no aqui
					newn->p = aux;
					break;
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
