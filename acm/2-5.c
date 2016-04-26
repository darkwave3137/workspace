#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	double a, b, s;
	int c, kase = 1;
	for(;; kase++){
		scanf("%lf%lf%d", &a, &b, &c);
		if(b == 0 && a == 0 && c == 0)
			exit(0);
		printf("Case %d: %d"".", kase,(int)floor(s = a / b));
		for(int i = 0; i < c; i++){
			s *= 10;
			if(i < c - 1 ||(i == c - 1 && (int)(s * 10) % 10 < 5))
				printf("%d", (int)s % 10);
			else 
				printf("%d", (int)s % 10 + 1);
		}
		printf("\n");
	}
}
