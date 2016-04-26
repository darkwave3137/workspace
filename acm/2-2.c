#include<stdio.h>
int main()
{
	int a, b, c, d, e = 1;
	while(scanf("%d%d%d", &a, &b, &c) != EOF){
		for(int i = 1;;i++){
			if((d = (i * 7 + c)) % 5 == b)
				if(d > 100 || d < 10){
					printf("Case %d:No answer\n", e);
					break;
				}
				else if(d % 3 == a){
						printf("Case %d: %d\n", e, d);
						break;
					 }		
		}
		e++;
	}	
	return 0;
}
