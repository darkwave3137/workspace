#include<stdio.h>
#include<string.h>
int main()
{
	char a[80];
	int n;
	scanf("%d", &n);
	getchar();
	while(n--){
		scanf("%s", a);
		int len = strlen(a);
		int i;
		int an = 0;
		for(i = 1; i <= len; i++){
			if(len % i == 0){
				an = 1;
				for(int j = i; j < len; j++){
					if(a[j % i] != a[j]){
						an = 0;
						break;
					}
				}
			}
			else continue;
			if(an)
				break;
		}
		printf("%d\n", i);
		if(n)
			printf("\n");
	}
	return 0;
}
