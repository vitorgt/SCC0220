#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

int main(){
	int o = 0, n = 0, gc[2], lc[2], gm[2], lm[2], in[30004];
	char op[5], *line = NULL;

	scanf("%d %d", &o, &n);
	scanf("%m[^\r\n]%*[\r\n]", &line);
	scanop(o, line, op);
	scanin(n, in);

	int i = 0;
	for(i = 0; i < o; i++)
		printf("op[%d]=%c\n", i, op[i]);
	for(i = 0; i < n; i++)
		//printf("in[%d]=%d\n", i, in[i]);

	if(op[0] == 'I' || op[1] == 'I' || op[2] == 'I' || op[3] == 'I' || op[4] == 'I')
		//i();
	if(op[0] == 'B' || op[1] == 'B' || op[2] == 'B' || op[3] == 'B' || op[4] == 'B')
	if(op[0] == 'M' || op[1] == 'M' || op[2] == 'M' || op[3] == 'M' || op[4] == 'M')
	if(op[0] == 'H' || op[1] == 'H' || op[2] == 'H' || op[3] == 'H' || op[4] == 'H')
	if(op[0] == 'Q' || op[1] == 'Q' || op[2] == 'Q' || op[3] == 'Q' || op[4] == 'Q')

	return 0;
}
