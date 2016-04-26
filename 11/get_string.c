#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *get_string()
{
	
	char *p, ch;
	int n = 50, i = 0;
	p = malloc(n * sizeof(char));
	printf("fuck zhangzhe");
	while((ch = getchar()) != '\n'){
		
		if(i == n){
			
			n *= 2;
			p = realloc(p, n);
		}
		p[i++] = ch;
	}
	p[i] = '\0';
	return p;

}

int main()
{
	char *p;
	p = get_string();
	printf("%s", p);
	free(p);
	return 0;
}
