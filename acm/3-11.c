#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(char *a, char *b);
int main()
{
	char a[200], b[200], at[200], bt[200];
	while(scanf("%s", a) != EOF){
		scanf("%s", b);
		memcpy(at, a, 200);
		memcpy(bt, b, 200);
		int an1, an2;
		an1 = cmp(a, b);
		an2 = cmp(bt, at);
		if(an2 < an1)
			an1 = an2;
		printf("%d\n", an1);
	}
	return 0;
}
		
int cmp(char *a, char *b)
{
		int an1 = 200;
		int len_a = strlen(a), len_b = strlen(b);
		for(int i = 0; i < len_a; i++)
			a[i] = a[i] - '0';
		for(int i = 0; i < len_b; i++)
			b[i] = b[i] - '0';
		int e = 0;
		int an = 0;
		for(e = 0; e < len_b; e++){
			for(int i = 0; i < len_a; i++){
				if(a[i] + b[i + e] > 3){
					an = 0;
					break;
				}
				if(e + i >= len_b || i == len_a - 1){
					an = 1;
					break;
				}
			}
			if(an)
				break;
		}
		if(an)
			if(e + len_a >= len_b)
				an1 =  e + len_a;
			else an1 =  len_b;
		else an1 = len_a + len_b;	
	return an1;
}
