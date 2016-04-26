#include<stdio.h>
int main()
{	
	int n;
	char ch;
	scanf("%d", &n);
	getchar();
	for(int s = 0, i = 1; n > 0; n--){
		while((ch = getchar()) != '\n')
			if(ch == 'O')
				s += i++;
			else i = 1;
		printf("%d\n", s);
		s = 0;
		i = 1;
	}
	return 0;
}
