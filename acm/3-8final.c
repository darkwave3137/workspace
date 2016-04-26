#include<stdio.h>
#include<string.h>
int an[2020];
int r[2020];
int main()
{
	int a, b;
	while(scanf("%d%d", &a, &b) != EOF){
		memset(an, 0, 1010 * sizeof(int));
		memset(r, 0, 1010 * sizeof(int));
		int tmp_a = a;
		int ans = 0;
		int i = 0;
		int count;
		for( i = 0; ; i++){
			r[i] = tmp_a % b;
			an[i] = tmp_a / b;
			if(r[i] == 0){
				ans = 2;
				break;
			}
			tmp_a = r[i] * 10;
			for(int j = 0; j < i; j++){
				if(r[j] == r[i]){
					ans = 1;
					count = i - j;
					break;
				}
			}
			if(ans)
				break;
		}
		printf("%d/%d = %d.", a, b, an[0]);
		if(ans == 1){
			for(int j = 0; j < 50 && j < i; j++){
				if(r[j] == r[i]){
					printf("(");
				}
				printf("%d", an[j + 1]);
			}
			if(i > 49){
				printf("...");
			}
			printf(")\n   %d = number of digits in repeating cycle\n\n", count);
		}
		if(ans == 2){
			for(int j = 0; j < i; j++){
				printf("%d", an[j + 1]);
			}
			printf("(0)\n   1 = number of digits in repeating cycle\n\n");
		}
	}
	return 0;
}

