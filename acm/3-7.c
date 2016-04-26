#include<stdio.h>
#include<string.h>
int a[1010][4];

int main()
{
	int k, m, n;
	scanf("%d", &k);
	while(k--){
		scanf("%d%d", &m, &n);
		getchar();
		memset(a, 0, n * 4 * sizeof(int));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				char ch;
				switch(ch = getchar()){
					case 'A': a[j][0]++; break;
					case 'C': a[j][1]++; break;
					case 'G': a[j][2]++; break;
					case 'T': a[j][3]++; break;
				}
			}
			getchar();
		}
		int an[1010] = {0};
		int s = 0;
		for(int i = 0; i < n; i++){
			int _tmp = a[i][3];
			for(int j = 3; j >= 0; j--){
				if(a[i][j] >= _tmp){
					_tmp = a[i][j];
					an[i] = j;
				}
			}
			s += m - a[i][an[i]];
		}
		for(int i = 0; i < n; i++){
			switch(an[i]){
				case 0: printf("A"); break;
				case 1: printf("C"); break;
				case 2: printf("G"); break;
				case 3: printf("T"); break;
			}
		}
		printf("\n%d\n", s);
	}
	return 0;
}
