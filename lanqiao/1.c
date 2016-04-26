#include<stdio.h>
int main()
{
	int n;
	int i = 1, j = 0, s;
	scanf("%d", &n);
	for(i = 1, j = 0; n > 1; n--){
 		s = i + j;	
		j = i;
		i = s;
	}
	printf("%d\n", s % 10007);
	return 0;
}
