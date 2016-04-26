#include<stdio.h>
#include<stdlib.h>
struct TEST{
	int a;
	int b;
	int c;
	struct TESTL{
		int a;
		int b;
		int c;
	} testl;
};
int main()
{
	struct TEST *p;
	p = malloc(sizeof(struct TEST));
	printf("%d", (int)sizeof(*p));
	return 0;	
}
