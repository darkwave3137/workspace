#include<stdio.h>
#include<stdlib.h>
int main()
{
	double s, n, m;
   	int	kase = 1;
	for(;;kase++){
		
		scanf("%lf%lf", &n, &m);
		if(n == 0)
			exit(0);
		for(s = 0;; n++){
			if(n > m)
				break;
			s += 1 / (n * n); 
		}
		printf("Case %d: %.5f\n", kase, s);
	}
	return 0;
}
