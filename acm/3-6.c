#include<stdio.h>
#include<string.h>
#define MAXR 1010
#define MAXC 1010
char puzzle[MAXR][MAXC];
int an[1010][3];
int main()
{
	int r, c;
	int n = 0;
	while(++n){
		if(scanf("%d", &r) == 1 && r == 0){
			break;
		}
		scanf("%d", &c);
		getchar();
		for(int i = 0; i < r; i++){
			gets(puzzle[i]);
		}
		int s = 0;
		int sizean = r * c;
		memset(an, 0, sizean * sizeof(int) * 3);
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				if(puzzle[i][j] != '*'){	
					if(j == 0 || puzzle[i][j - 1] == '*'){
						an[s][0] += 1;
						an[s][1] = i;
						an[s][2] = j;
					}
					if(i == 0 || puzzle[i - 1][j] == '*'){           //short-circuit logic
						an[s][0] += 2;
						an[s][1] = i;
						an[s][2] = j;
					}
					if(an[s][0] != 0){
						s++;
					}
				}
			}
		}
		s--;
		char ch;
		printf("puzzle #%d:\nAcross\n", n);
		for(int i = 0; i <= s; i++){
			int tmp_r = an[i][1], tmp_c = an[i][2];
			if(an[i][0] == 1 || an[i][0] == 3){
				printf("%3d.", i + 1);
				while((ch = puzzle[tmp_r][tmp_c]) != '*' && tmp_c < c){
					printf("%c", puzzle[tmp_r][tmp_c]);
					tmp_c++;
				}	
				printf("\n");	
			}
	
		}
		printf("Down\n");
		for(int i = 0; i <= s; i++){
			int tmp_r = an[i][1], tmp_c = an[i][2];
			if(an[i][0] == 2 || an[i][0] == 3){
				printf("%3d.", i + 1);
				while((ch = puzzle[tmp_r][tmp_c]) != '*' && tmp_r < r){
					printf("%c", puzzle[tmp_r][tmp_c]);
					tmp_r++;
				}	
				printf("\n");
			}
		}
	printf("\n");
	}
	return 0;	
}
