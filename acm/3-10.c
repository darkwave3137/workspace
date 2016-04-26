#include<stdio.h>
#include<string.h>
int main()
{
	int an[3][3] , h[3], w[3];
	int ex, a, b;
	int n = 0;
	while(1){
		int flag = 1;
		memset(an, 0, 9 * sizeof(int));
		for(int i = 0; i < 6; i++){
			if(scanf("%d%d", &a, &b) == EOF)
				return 0;
			if(b > a){
				ex = b;
				b = a;
				a = ex;
			}
			if(a == 0 || b == 0){
				flag = 0;
			}
			for(int i = 0; i < 3; i++){
				if(!an[i][0]){
					an[i][1] = a;
					an[i][2] = b;
					an[i][0]++;
					break;
				}
				if(a == an[i][1] && b == an[i][2] && an[i][0] != 2){
					an[i][0]++;
					break;
				}
			}
		}
		if(an[0][0] != 2 || an[1][0] != an[0][0] || an[2][0] != an[0][0]){
			flag = 0;
		}
		for(int i = 0; i < 3; i++){
			h[i] = an[i][1];			
			w[i] = an[i][2];
		}
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				if(h[i] == w[j]){
					h[i] = 0;
					w[j] = 0;
				}
				if(h[i] == h[j] && i != j){
					h[i] = h[j] = 0;
				}
				if(w[i] == w[j] && i != j){
					w[i] = w[j] = 0;
				}
			}
		}
		for(int i = 0; i < 3; i++){
			if(h[i] != 0 || w[i] != 0){
				flag = 0;
				break;
			}
		}
		if(flag){
			printf("POSSIBLE\n");
		}	
		else printf("IMPOSSIBLE\n");
	}
}
