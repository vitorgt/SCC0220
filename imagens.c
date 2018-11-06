#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _nodeQUAT{
	char c;//0 for black; 1 for white; 2 for 'parent node'
	struct _nodeQUAT *next[4];
}nodeQUAT;

typedef struct _quat{
	nodeQUAT *root;
}quat;

void removeQUAT(nodeQUAT *a){
	if(a){
		if(a->c == 2){
			removeQUAT(a->next[0]);
			removeQUAT(a->next[1]);
			removeQUAT(a->next[2]);
			removeQUAT(a->next[3]);
		}
		free(a);
	}
}

void parent_allocate_qt(nodeQUAT *p){
	int i = 0;
	p->c = 2;
	for(i = 0; i < 4; i++)
		p->next[i] = (nodeQUAT *)calloc(1, sizeof(nodeQUAT));
}

int curr = 0;

void fill_qt(nodeQUAT *p, char *txt){
	if(curr < strlen(txt)){
		if(txt[curr] == 'e'){
			p->c = 1;
		}
		else if(txt[curr] == 'f'){
			p->c = 0;
		}
		else if(txt[curr] == 'p'){
			int i = 0;
			parent_allocate_qt(p);
			for(i = 0; i < 4; i++){
				curr++;
				fill_qt(p->next[i], txt);
			}
		}
	}
}

int sum_qt(nodeQUAT *p, int power){
	if(p->c == 0)
		return power;
	else if(p->c == 1)
		return 0;
	return (
			sum_qt(p->next[0], power/4) +
			sum_qt(p->next[1], power/4) +
			sum_qt(p->next[2], power/4) +
			sum_qt(p->next[3], power/4)
	       );
}

void print_qt(nodeQUAT *p){
	if(p){
		//printf("%p(%d):", (void *)p, p->c);
		printf("(%d):", p->c);
		printf("(");
		print_qt(p->next[0]);
		print_qt(p->next[1]);
		print_qt(p->next[2]);
		print_qt(p->next[3]);
		printf(") ");
		/*
		   if(p->c == 2){
		   printf("(");
		   print_qt(p->next[0]);
		   print_qt(p->next[1]);
		   print_qt(p->next[2]);
		   print_qt(p->next[3]);
		   printf(") ");
		   }
		   else{
		   printf("%c ", p->c?'w':'b');
		   }
		 */
	}
}

void combine_qt(nodeQUAT *a, nodeQUAT *b, nodeQUAT *c){//a + b = c
	if(a && b && c){
		if(a->c == 0 || b->c == 0){//if any black
			c->c = 0;
		}
		else if(a->c == 1 && b->c == 1){//if both white
			c->c = 1;
		}
		else{
			int i = 0;
			c->c = 2;
			if(a->c == 1){//1 2
				b->c = 1;
				for(i = 0; i < 4; i++)
					c->next[i] = b->next[i];
			}
			else if(b->c == 1){//2 1
				a->c = 1;
				for(i = 0; i < 4; i++)
					c->next[i] = a->next[i];
			}
			else{//2 2
				parent_allocate_qt(c);
				for(i = 0; i < 4; i++)
					combine_qt(a->next[i], b->next[i], c->next[i]);
			}
		}
	}
}

int main(){
	int op = 0, counter = 1;
	char *buffer = NULL;
	scanf("%d\n", &op);
	quat a, b, c;
	while(op--){
		a.root = (nodeQUAT *)malloc(sizeof(nodeQUAT));
		b.root = (nodeQUAT *)malloc(sizeof(nodeQUAT));
		c.root = (nodeQUAT *)malloc(sizeof(nodeQUAT));
		parent_allocate_qt(c.root);

		scanf("%m[^\r\n]%*[\r\n]", &buffer);
		curr = 0;
		fill_qt(a.root, buffer);
		free(buffer);
/*
		printf("a\n");
		print_qt(a.root);
		printf("\n");
*/

		scanf("%m[^\r\n]%*[\r\n]", &buffer);
		curr = 0;
		fill_qt(b.root, buffer);
		free(buffer);
/*
		printf("b\n");
		print_qt(b.root);
		printf("\n");
*/

		combine_qt(a.root, b.root, c.root);
/*
		printf("c\n");
		print_qt(c.root);
		printf("\n");
		printf("a\n");
		print_qt(a.root);
		printf("\n");
		printf("b\n");
		print_qt(b.root);
		printf("\n");
*/

		printf("%d %d pixels pretos.\n", counter++, sum_qt(c.root, 1024));

		removeQUAT(c.root);
		removeQUAT(a.root);
		removeQUAT(b.root);
	}
	return 0;
}
