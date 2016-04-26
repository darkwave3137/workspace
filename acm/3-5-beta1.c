#include<stdio.h>
#include<string.h>
typedef struct {
			int x;
			int y;
		}SPACE;
SPACE find_space(char a[5][5])
{
	SPACE space;
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++){
			if(a[i][j] == ' '){
				space.x = i;
				space.y = j;
				return space;
			}
		}
}

int main()
{	
	char a[5][5] = {0};
	int n = 0;
	char ch;
	int er = 0;
	while(++n){
		er = 0;
		memset(a, '\0', sizeof(a));
		for(int i = 0; i < 5; i++){
			scanf("%[^\n]", a[i]);
			while(getchar() != '\n')
				;
			if(a[0][0] == 'Z' && a[0][1] == '\0'){
				return 0;
			}			
		}
		SPACE space;   //space / 10 is h
		space = find_space(a);
	/*	SPACE new = space;*/
		while(er == 0 && (ch = getchar()) != '0'){
			switch(ch){
				case 'A':if(space.x == 0){er = 1; break;} a[space.x][space.y] = a[space.x - 1][space.y]; space.x = space.x - 1 ; a[space.x][space.y] = ' '; break;
				case 'B':if(space.x == 4){er = 1; break;} a[space.x][space.y] = a[space.x + 1][space.y]; space.x = space.x + 1 ; a[space.x][space.y] = ' '; break;
				case 'L':if(space.y == 0){er = 1; break;} a[space.x][space.y] = a[space.x][space.y - 1]; space.y = space.y - 1 ; a[space.x][space.y] = ' '; break;
				case 'R':if(space.y == 4){er = 1; break;} a[space.x][space.y] = a[space.x][space.y + 1]; space.y = space.y + 1 ; a[space.x][space.y] = ' ' ; break;
				case '\n': break;
				default: er = 1;
			}
		}
		char ac = '0';
		
		while(ch = getchar(), (ac != '0' || ch != '\n')){
			ac = ch;
			er = 1;
		}

		printf("Puzzle #%d:\n", n);
		if(er){
			printf("This puzzle has no final configuration.\n\n");
			continue;
		}
		else for(int i = 0; i < 5; i++)
				for(int j = 0 ; j < 5; j++){
					printf("%c", a[i][j]);
					if(j != 4)
						printf(" ");
					else if(i != 4)
						printf("\n");
					else printf("\n\n");
				}
	}
	return 0;
}
