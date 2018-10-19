#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int data[5][2];// Cs and Ms of each sorting algorithm following IBMHQ (see printdata)

void scanop(char *line, char *op){
	int i = 0, len = strlen(line);
	for(i = 0; i < len; i++){
		if(i == 0 || (line[i] == ' ' && (i+1) < len)){
			if(line[i] == 'I') op[0] = 1;
			if(line[i] == 'B') op[1] = 1;
			if(line[i] == 'M') op[2] = 1;
			if(line[i] == 'H') op[3] = 1;
			if(line[i] == 'Q') op[4] = 1;
		}
	}
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

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

void I(int *v, int n){
	int i = 1, j = 0, k = 0;
	for(; i < n; i++){
		k = v[i];
		j = i - 1;
		data[0][0]++;
		while(j >= 0 && v[j] > k){ data[0][0]++;
			v[j+1] = v[j]; data[0][1]++;
			j = j - 1;
		}
		v[j+1] = k; data[0][1]++;
	}
}

void B(int *v, int n){
	int i = 0, j = 0;
	for(; i < n-1; i++)
		for(j = 0; j < n-i-1; j++){
			data[1][0]++;
			if(v[j] > v[j+1]){
				swap(&v[j], &v[j+1]); data[1][1] += 2;
			}
		}
}

void merge(int *v, int l, int m, int r){
	int i = 0, j = 0, k = 0;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	for(i = 0; i < n1; i++)
		L[i] = v[l+i];
	for(j = 0; j < n2; j++)
		R[j] = v[m + 1 + j];
	i = j = 0;
	k = l;
	while(i < n1 && j < n2){
		data[2][0]++;
		if(L[i] <= R[j]){
			v[k++] = L[i++]; data[2][1]++;
		}
		else{
			v[k++] = R[j++]; data[2][1]++;
		}
	}
	while(i < n1){
		v[k++] = L[i++]; data[2][1]++;
	}
	while(j < n2){
		v[k++] = R[j++]; data[2][1]++;
	}
}

void M(int *v, int l, int r){
	if(l < r){
		int m = (l+r)/2;
		M(v, l, m);
		M(v, m+1, r);
		merge(v, l, m, r);
	}
}

void heapify(int *v, int n, int i){
	int largest = i;
	int l = 2*i+1, r = 2*i+2;
	data[3][0]++;
	if(l < n && v[l] > v[largest]){
		largest = l;
	}
	data[3][0]++;
	if(r < n && v[r] > v[largest]){
		largest = r;
	}
	if(largest != i){
		swap(&v[i], &v[largest]); data[3][1] += 2;
		heapify(v, n, largest);
	}
}

void H(int *v, int n){
	int i = 0;
	for(i = (n/2)-1; i >= 0; i--)
		heapify(v, n, i);
	for(i = n-1; i >= 0; i--){
		swap(&v[0], &v[i]); data[3][1] += 2;
		heapify(v, i, 0);
	}
}

void Q(int *v, int l, int r){
	if(l < r){
		int L = l, R = r;
		int pivot = v[(l+r)/2];
		while(L <= R){
			data[4][0]++;
			while(v[L] < pivot){ data[4][0]++;
				L++;
			}
			while(v[R] > pivot){ data[4][0]++;
				R--;
			}
			if(L <= R){
				swap(&v[L], &v[R]); data[4][1] += 2;
				L++; R--;
			}
		}
		Q(v, l, R);
		Q(v, L, r);
	}
}

char *menorC(char *op){
	int p = data[0][0], d = 0, i = 0;
	for(i = 0; i < 5; i++){
		if(data[i][0] < p && op[i]){
			p = data[i][0];
			d = i;
		}
	}
	if(d == 0) return "INSERTIONSORT";
	if(d == 1) return "BUBBLESORT";
	if(d == 2) return "MERGESORT";
	if(d == 3) return "HEAPSORT";
	if(d == 4) return "QUICKSORT";
	else return "NONE";
}

char *maiorC(char *op){
	int p = data[0][0], d = 0, i = 0;
	for(i = 0; i < 5; i++){
		if(data[i][0] > p && op[i]){
			p = data[i][0];
			d = i;
		}
	}
	if(d == 0) return "INSERTIONSORT";
	if(d == 1) return "BUBBLESORT";
	if(d == 2) return "MERGESORT";
	if(d == 3) return "HEAPSORT";
	if(d == 4) return "QUICKSORT";
	else return "NONE";
}

char *menorM(char *op){
	int p = data[0][1], d = 0, i = 0;
	for(i = 0; i < 5; i++){
		if(data[i][1] < p && op[i]){
			p = data[i][1];
			d = i;
		}
	}
	if(d == 0) return "INSERTIONSORT";
	if(d == 1) return "BUBBLESORT";
	if(d == 2) return "MERGESORT";
	if(d == 3) return "HEAPSORT";
	if(d == 4) return "QUICKSORT";
	else return "NONE";
}

char *maiorM(char *op){
	int p = data[0][1], d = 0, i = 0;
	for(i = 0; i < 5; i++){
		if(data[i][1] > p && op[i]){
			p = data[i][1];
			d = i;
		}
	}
	if(d == 0) return "INSERTIONSORT";
	if(d == 1) return "BUBBLESORT";
	if(d == 2) return "MERGESORT";
	if(d == 3) return "HEAPSORT";
	if(d == 4) return "QUICKSORT";
	else return "NONE";
}

int main(){
	int o = 0, n = 0, *in = NULL, *sort = NULL;
	char op[5], *line = NULL;

	scanf("%d %d\n", &o, &n);
	scanf("%m[^\r\n]%*[\r\n]", &line);
	scanop(line, op);
	free(line);

	in = (int *)calloc(n, sizeof(int));
	sort = (int *)calloc(n, sizeof(int));
	scanin(n, in);

	if(op[0]){
		copy_arr(n, in, sort);
		I(sort, n);
	}
	if(op[1]){
		copy_arr(n, in, sort);
		B(sort, n);
	}
	if(op[2]){
		copy_arr(n, in, sort);
		M(sort, 0, n-1);
	}
	if(op[3]){
		copy_arr(n, in, sort);
		H(sort, n);
	}
	if(op[4]){
		copy_arr(n, in, sort);
		Q(sort, 0, n-1);
	}

	//printdata();

	free(in);
	free(sort);

	printf("Menor C: %s\n", menorC(op));
	printf("Maior C: %s\n", maiorC(op));
	printf("Menor M: %s\n", menorM(op));
	printf("Maior M: %s\n", maiorM(op));

	return 0;
}
