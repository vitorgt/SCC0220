#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	long long x0 = 0, y0 = 0, coef[100], temp = 0, i = 0, slope = 0, linear = 0;
	for(i = 0; i < 100; i++) coef[i] = 0;
	scanf("%lld", &x0);
	while(scanf("%lld %lld", &coef[99], &temp) == 2)
		coef[temp] = coef[99];
	coef[99] = 0;
	y0 += coef[0]*pow(x0, 0);
	for(i = 1; i < 100; i++){
		y0 += coef[i]*(long long)pow(x0, i);
		slope += (coef[i]*i)*(long long)pow(x0, i-1);
	}
	printf("f'(x) =");
	temp = 1;
	for(i = 99; i > 0; i--){
		if(coef[i] != 0){
			if(!temp){
				printf(" %c ", coef[i] > 0 ? '+' : '-');
			}
			if(temp){
				temp = 0;
				if(coef[i] < 0) printf(" - ");
				else printf(" ");
			}
			printf("%lld", (long long)llabs(coef[i]*i));
			if(i > 1) printf("x");
			if(i > 2) printf("^%lld", i-1);
		}
	}
	printf("\ng(x) =");
	if(slope != 0){
		if(slope < 0) printf(" -");
		printf(" %lldx", (long long)llabs(slope));
	}
	linear = -slope*x0 + y0;
	if(linear != 0){
		if(linear < 0) printf(" -");
		printf(" %lld", (long long)llabs(linear));
	}
	printf("\n");
	return 0;
}
