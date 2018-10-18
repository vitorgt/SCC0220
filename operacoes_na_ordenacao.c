#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int data[5][2];// Cs and Ms of each sorting algorithm following IBMHQ (see printdata)

void scanop(int o, char *line, char *op){
	int i = 0, j = 0, len = strlen(line);
	op[i++] = line[0];
	if(o == 1) return;
	for(j = 0; i < o && j < len; j++)
		if(line[j] == ' ' && (j+1) < len)
			op[i++] = line[j+1];
}

void scanin(int n, int *in){
	int i = 0;
	n++;
	while(n--)
		scanf("%d", &in[i++]);
}

void copy_arr(int n, int *in, int *out){
	int i = 0;
	for(; i < n; i++)
		out[i] = in[i];
}

void printv(int n, int *v){
	int i = 0;
	for(; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");
}

void printdata(){
	printf("I: %10dC %10dM\n", data[0][0], data[0][1]);
	printf("B: %10dC %10dM\n", data[1][0], data[1][1]);
	printf("M: %10dC %10dM\n", data[2][0], data[2][1]);
	printf("H: %10dC %10dM\n", data[3][0], data[3][1]);
	printf("Q: %10dC %10dM\n", data[4][0], data[4][1]);
}

void i(int *v, int n){
	int i = 1, j = 0, k = 0;
	for(; i < n; i++){
		k = v[i];
		j = i - 1;
		while(j >= 0 && v[j] > k){ data[0][0]++;
			v[j+1] = v[j]; data[0][1]++;
			j = j - 1;
		}
		v[j+1] = k; data[0][1]++;
	}
}

void b(int *v, int n){
	int i = 0, j = 0;
	for(; i < n-1; i++)
		for(j = 0; j < n-i-1; j++)
			if(v[j] > v[j+1]){ data[1][0]++;
				int t = v[j];
				v[j] = v[j+1]; data[1][1]++;
				v[j+1] = t; data[1][1]++;
			}
}

void merge(int *v, int l, int mid, int r){
}

void m(int *v, int l, int r){
	if(l < r){
		int mid = l+(r-1)/2;
		m(v, l, mid);
		m(v, mid+1, r);
		merge(v, l, mid, r);
	}
}

int main(){
	int o = 0, n = 0, in[30004], sort[30004];
	char op[5], *line = NULL;

	for(; o < 5; o++)
		op[o] = in[o] = sort[o] = 0;
	for(; o < 30004; o++)
		in[o] = sort[o] = 0;

	scanf("%d %d\n", &o, &n);
	scanf("%m[^\r\n]%*[\r\n]", &line);
	scanop(o, line, op);
	free(line);
	scanin(n, in);

	if(op[0] == 'I' || op[1] == 'I' || op[2] == 'I' || op[3] == 'I' || op[4] == 'I'){
		copy_arr(n, in, sort);
		i(sort, n);
	}
	if(op[0] == 'B' || op[1] == 'B' || op[2] == 'B' || op[3] == 'B' || op[4] == 'B'){
		copy_arr(n, in, sort);
		b(sort, n);
	}
	if(op[0] == 'M' || op[1] == 'M' || op[2] == 'M' || op[3] == 'M' || op[4] == 'M'){
		copy_arr(n, in, sort);
		m(sort, 0, n-1);
	}
	if(op[0] == 'H' || op[1] == 'H' || op[2] == 'H' || op[3] == 'H' || op[4] == 'H'){
		copy_arr(n, in, sort);
	}
	if(op[0] == 'Q' || op[1] == 'Q' || op[2] == 'Q' || op[3] == 'Q' || op[4] == 'Q'){
		copy_arr(n, in, sort);
	}
	printdata();

	return 0;
}
