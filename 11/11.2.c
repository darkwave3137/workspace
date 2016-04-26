#include<stdio.h>
#include<stdlib.h>

int *re()
{
	int n;
	int *p;
	int i = 0;
	scanf("%d", &n);
	p = malloc(n * sizeof(int));
	for( p[i++] = n; i < n; i++){
		scanf("%d", &p[i]);
	}
	return p;
}

int main()
{
	int *p;
	p = re();
	for(int i = 0; i < sizeof(p) / sizeof(int); i++){
		printf("%d ", (int)sizeof(p));
	}
	return 0;
}
