#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int qtd = 0;

typedef struct _athlete{
	char house;
	char *name;
	int id;
}athlete;

void mergeI(athlete *a, int l, int m, int r){
	qtd--;
	int i = 0, j = 0, k = l, n1 = m - l + 1, n2 = r - m;
	athlete L[n1], R[n2];
	for(i = 0; i < n1; i++)
		L[i] = a[l+i];
	for(i = 0; i < n2; i++)
		R[i] = a[m+1+i];
	i = 0;
	while(i < n1 && j < n2){
		if(L[i].id <= R[j].id)
			a[k++] = L[i++];
		else
			a[k++] = R[j++];
	}
	while(i < n1) a[k++] = L[i++];
	while(j < n2) a[k++] = R[j++];
}

void mergeN(athlete *a, int l, int m, int r){
	qtd--;
	int i = 0, j = 0, k = l, n1 = m - l + 1, n2 = r - m;
	athlete L[n1], R[n2];
	for(i = 0; i < n1; i++)
		L[i] = a[l+i];
	for(i = 0; i < n2; i++)
		R[i] = a[m+1+i];
	i = 0;
	while(i < n1 && j < n2){
		if(strcmp(L[i].name, R[j].name) <= 0)
			a[k++] = L[i++];
		else
			a[k++] = R[j++];
	}
	while(i < n1) a[k++] = L[i++];
	while(j < n2) a[k++] = R[j++];
}

void mergesort(athlete *a, int l, int r, char op){
	if(l < r){
		int m = (l+r-1)/2;
		mergesort(a, l, m, op);
		mergesort(a, m+1, r, op);
		if(qtd > 0){
			if(op == 'I') mergeI(a, l, m, r);
			else mergeN(a, l, m, r);
		}
	}
}

int main(){
	int i = 0, countF = 0, countC = 0;
	char *buffer = NULL, op = 0;
	athlete a[400];

	scanf("%m[^\r\n]%*[\r\n]", &buffer); free(buffer);
	for(i = 0; scanf("%d %m[^\r\n]%*[\r\n]", &a[i].id, &a[i].name) == 2; i++)
		a[i].house = 'F';
	countF = i;

	scanf("%m[^\r\n]%*[\r\n]", &buffer); free(buffer);
	for(; scanf("%d %m[^\r\n]%*[\r\n]", &a[i].id, &a[i].name) == 2; i++)
		a[i].house = 'C';
	countC = i - countF;

	scanf("%c%ms %d", &op, &buffer, &qtd); free(buffer);
	mergesort(a, 0, countC + countF - 1, op);

	for(i = 0; i < (countC + countF); i++){
		printf("%s %d %s\n", a[i].house == 'C' ? "CAASO" : "FEDERAL", a[i].id, a[i].name);
		free(a[i].name);
	}

	return 0;
}
