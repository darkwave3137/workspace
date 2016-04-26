#include<stdio.h>
#include<string.h>
int an[1510];
int r[1510];
int main()
{
	int a, b;
	while(scanf("%d%d", &a, &b) != EOF){
		int k = 0;
		memset(an, 0, 1010 * sizeof(int));
		memset(r, 0, 1010 * sizeof(int));
		int ans = 0;
		int start;
		int i = 0;
		int point = 0;
		int a_tt;
		for(int a_tmp = a;(a_tmp /= b) != 0; point++)
			;
/*		if(!point)
			point++;*/
		for(i = 0, a_tt = a; ; i++){
			r[i] = a_tt % b;
			if(r[i] == 0){
				ans = 1;
				an[i] = a_tt / b;
				break;
			}
		/*	if(a / b == 0){
				a *= 10;
				an[i] = 0;
				continue;
			}*/
			an[i] = a_tt / b;
			a_tt = r[i] * 10;
			for(int j = point; j < i; j++){
				if(r[i] == r[j]){
					start = j + 1;
					ans = 1;
					break;
				}
			}
			if(ans == 1 && r[i] != 0){
				if(!point)
					point++;
				printf("%d/%d = ", a, b);
				for(int i = 0; i < point; i++){
					printf("%d", an[i]);			
				}
				printf(".");
				for(int i = point; i < start; i++){
					printf("%d", an[i]);
				}
				printf("(");
				for(int j = start; j <= i; j++){
					printf("%d", an[j]);
					if(j - start >= 49){
						printf("...");
						break;
					}
				}
				printf(")\n");
				printf("   %d = number of digits in repeating cycle\n\n", i - start + 1);
				break;
			}
		}
		if(ans == 1 && r[i] == 0){
			if(!point)
				point++;
			printf("%d/%d = ", a, b);
			for(int i = 0; i < point; i++)
				printf("%d", an[i]);			
			
			printf(".");
			for(int i = point; r[i - 1] != 0; i++){
				printf("%d", an[i]);
			}
			printf("(0)\n");
			printf("   1 = number of digits in repeating cycle\n\n");
	
		}
	}
}
