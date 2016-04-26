#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	int a[10] = {0};
	scanf("%d", &n);
	getchar();
	while(n--){
		int i;
		scanf("%d", &i);
		for(;i != 0;i--){
			int s = i;
			while(s){
				a[s % 10]++;
				s /= 10;
			}
		}	
		for(int i = 0; i < 9; i++){
			printf("%d ", a[i]);
		}
		printf("%d", a[9]);
		printf("\n");
		memset(a, 0, 10 * sizeof(int));
	}
	return 0;
}
