#include<stdio.h>
#include<ctype.h>
int main()
{	
	char ch;
	double ch_1 = 0;
	int n;
	scanf("%d", &n);
	getchar();
	while(n--){
		double s = 0;
	    int	i = 0;
		ch_1 = 0;
		while((ch = getchar()) != '\n'){
			if(isalpha(ch)){
				if(!i)
					i = 1;
				s += ch_1 * (i - 1);
				switch(ch){
					case 'C': ch_1 = 12.01; break;
					case 'H': ch_1 = 1.008; break;
					case 'O': ch_1 = 16.00; break;
					case 'N': ch_1 = 14.01; break;
				};
				s += ch_1 * 1;
				i = 0;
			}
			else i = i * 10 + (ch - '0');
		/*	printf("%d", i);*/
		}
		if(i)
			s += ch_1 * (i - 1);
		printf("%.3f\n", s);
	}
	printf("\n");
}
