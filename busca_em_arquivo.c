#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(char **str1, char **str2){
	char *temp = (char *)malloc(sizeof(*str1) * sizeof(char));
	strcpy(temp, *str1);
	free(*str1);
	*str1 = (char *)malloc(sizeof(*str2) * sizeof(char));
	strcpy(*str1, *str2);
	free(*str2);
	*str2 = (char *)malloc(sizeof(temp) * sizeof(char));
	strcpy(*str2, temp);
	free(temp);
}

int partition (char **arr, int low, int high) {
	char pivot[50];
	strcpy(pivot, arr[high]);
	int i = (low - 1);
	for (int j = low; j <= high- 1; j++) {
		if(strcmp(arr[j], pivot) <= 0){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return i+1;
}

void quickSort(char **arr, int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void nextThree(char **data, char *word, int n){
	int i = 0;
	for(i = 0; i < n; i++)
		if(strcmp(word, data[i]) < 0)
			break;
	for(int j = 0; i < n && j < 3; i++, j++)
		printf("%s ", data[i]);
}

int main(){
	char *fn = NULL, *word = NULL, **search = NULL, **data = NULL;
	int n = 0, j = 0, *searchCounters = NULL, m = 0, wordCount = 0;
	FILE *f = NULL;
	scanf("%ms %d", &fn, &n);
	search = (char **)malloc(sizeof(char *) * n);
	searchCounters = (int *)calloc(sizeof(int), n);
	m = n;
	while(m) scanf("%ms", &search[--m]);
	f = fopen(fn, "r");
	free(fn);
	while(fscanf(f, "%ms", &word) != EOF) wordCount++;
	data = (char **)malloc(sizeof(char *) * wordCount);
	fseek(f, 0, SEEK_SET);
	j = 0;
	while(fscanf(f, "%ms", &word) != EOF){
		int wordLen = strlen(word);
		for(int i = 0; i < wordLen; i++){
			if(word[i] >= 'A' && word[i] <= 'Z')
				word[i] += ' ';//maiuscula para minuscula soma 32 (ie, ' ')
		}
		for(int i = 0; i < n; i++){
			if(!strcmp(word, search[i])){
				searchCounters[i]++;
			}
		}
		data[j++] = word;
	}
	quickSort(data, 0, wordCount-1);
	for(int i = n-1; i >= 0; i--){
		printf("%s %d ", search[i], searchCounters[i]);
		nextThree(data, search[i], wordCount);
		printf("\n");
	}
	fclose(f);
	return 0;
}
