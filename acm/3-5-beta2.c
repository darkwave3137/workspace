#include<stdio.h>
#include<string.h>
/*char cmd[1010];*/
int main()
{
	char a[5][7];
	int n = 0;
	char ch;
	while(++n){
		for(int i = 0; i < 5; i++){
			gets(a[i]);
			if(a[0][0] == 'Z')
				return 0;
		}
    	int space_x, space_y;
		for(int i = 0; i < 5; i++)
			for(int j = 0; j < 5; j++){
				if(a[i][j] == ' '){
					space_x = i;
					space_y = j;
				}
			}
		int flag = 1;
		while((ch = getchar()) != '0')
		/*int k = 0;
		while(~scanf("%c", &cmd[k]))
			if(cmd[k] != '0') k++;
			else break;
		cmd[k] = 0;
		getchar();*/
	/*	for(int i = 0; i < k; i++)*/
		{
			int x = 0, y = 0;
			switch(/*cmd[i]*/ch){
				case 'A': x--; break;
				case 'B': x++; break;
				case 'L': y--; break;
				case 'R': y++; break;
			}
			x = space_x + x;
			y = space_y + y;
			if(x > 4 || x < 0 || y > 4 || y < 0){
				flag = 0;
			/*	break;*/
				continue;
			}
			a[space_x][space_y] = a[x][y];
			a[x][y] = ' ';
			space_x = x;
			space_y = y;
		}
		while(getchar() != '\n')
			;
		printf("Puzzle #%d:\n", n);
		if(!flag){
			printf("This puzzle has no final configuration.\n");
		}
		else for(int i = 0; i < 5; i++)
				for(int j = 0; j < 5; j++){
					printf("%c", a[i][j]);
					if(j != 4)
						printf(" ");
					else printf("\n");
				}
		printf("\n");
	}
}
