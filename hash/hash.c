#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ADT/deque.h"

int id(char *line){
	if(line){
		int i = 0, sum = 0, size = strlen(line);
		for(i = 0; i < size; i++){
			if(i%2){
				sum += ((int)line[i]-'a')*23;
				//sum += (int)line[i]-'a';
			}
			else{
				sum += ((int)line[i]-'a')*17;
			}
			if(i%3){
				sum += ((int)line[i]-'a')*43;
			}
		}
		return sum;
	}
	return 0;
}

int main(){
	char op = 0, *buffer = NULL, **hash = NULL;
	while(op != 'f'){
		scanf("%c %m[^\r\n]%*[\r\n]", &op, &buffer);
		printf("%c\t%d\t%s\n", op, id(buffer), buffer);
		free(buffer);
		if(op == 'i'){
		}
		else if(op == 'b'){
		}
		else if(op == 'r'){
		}
	}
	return 0;
}
