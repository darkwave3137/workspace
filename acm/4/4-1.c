#include<stdio.h>
#include<string.h>
int board[14][13];
void initialization(int (*board)[13])
{
	memset(board, 0, 14 * 13 * sizeof(int));
}

int red_gereral(int (*board)[13], int x, int y, int g_y)
{
	x++; y++;
	if(g_y + 1 == y)
		return 1;
	for(int i = x - 1; i >= 2; i--){
		if(board[i][y] < 100){
			board[i][y]++;
		}
		else break;
	}
	return 0;
}

void red_chariot(int (*board)[13], int x, int y)
{
	x++; y++;
/*	board[x - 1][y]++;
	board[x][y + 1]++;
	board[x][y - 1]++;	*/
	for(int i = y - 1; i > 1; i--){
			board[x][i]++;
			if(board[x][i] >= 100)
				break;
	}
	for(int i = y + 1; i < 11; i++){
		board[x][i]++;
		if(board[x][i] >= 100)
			break;
	}
	for(int i = x - 1; i > 1; i--){
		board[i][y]++;
		if(board[i][y] >= 100)
			break;	
}
	for(int i = x + 1; i < 12; i++){
		board[i][y]++;
		if(board[i][y] >= 100)
			break;
	}
}
void red_horse(int (*board)[13], int x, int y)
{
	x++; y++;
	if(board[x][y - 1] < 100){
		board[x - 1][y - 2]++;
   		board[x + 1][y - 2]++;
	}
	if(board[x - 1][y] < 100){
  	 	board[x - 2][y - 1]++;
   		board[x - 2][y + 1]++;
	}
   	if(board[x + 1][y] < 100){
		board[x + 2][y + 1]++;
   		board[x + 2][y - 1]++;
	}
	if(board[x][y + 1] < 100){
		board[x - 1][y + 2]++;
 	  	board[x + 1][y + 2]++;	
	}
}

void red_cannon(int (*board)[13], int x, int y)
{
	x++; y++;
	
	for(int i = y - 1, flag = 0; i >= 2; i--){
		if(board[x][i] >= 100 && !flag){
			flag = 1;
			continue;
		}
		if(board[x][i] >= 100 && flag){
		   board[x][i]++;
		   break;	
		}
		if(flag)
			board[x][i]++;
	}
	for(int i = y + 1, flag = 0; i < 11; i++){
		if(board[x][i] >= 100 && !flag){
			flag = 1;
			continue;
		}
		if(board[x][i] >= 100 && flag){
		   board[x][i]++;
		   break;
		}	
		if(flag)
			board[x][i]++;
	}
	for(int i = x - 1, flag = 0; i >= 2; i--){
		if(board[i][y] >= 100 && !flag){
			flag = 1;
			continue;
		}
		if(board[i][y] >= 100 && flag){
		   board[i][y]++;
		   break;
		}	   
		if(flag)
			board[i][y]++;
	}
	for(int i = x + 1, flag = 0; i < 12; i++){
		if(board[i][y] >= 100 && !flag){
			flag = 1;
			continue;
		}
		if(board[i][y] >= 100 && flag){
			board[i][y]++;
		   break;	
		}
		if(flag)
			board[i][y]++;
	}
}

int is_checkmate(int (*board)[13], int g_x, int g_y)
{
	int i = 1;
	g_x++; g_y++;
	for(i = 0; i < 13; i++){
		board[1][i] = 1;
	}
	if(/*board[g_x][g_y] == 0 ||*/ (board[g_x][g_y + 1] % 100 == 0 && g_y != 7) || (board[g_x][g_y - 1] % 100 == 0 && g_y != 5) || (board[g_x + 1][g_y] % 100 == 0 && g_x != 4) || (board[g_x - 1][g_y] % 100 == 0 && g_x != 2))
		i = 0;
	return i;
}

int main()
{
	int n, g_x, g_y;
	int flag = 0;
	while(scanf("%d%d%d", &n, &g_x, &g_y) && (n || g_x || g_y)){
		flag = 0;
		initialization(board);
		char _type[100] = {0};
	    int x[100] = {0}, y[100] = {0};
		int i = 0;
		while(n--){
		/*	char _type;
			int x, y;*/
			getchar();
			scanf("%c%d%d", &_type[i], &x[i], &y[i]);
			board[x[i] + 1][y[i] + 1] = 100;
			i++;
		}
		n = i;
		for(int i = 0; i < n; i++){
				switch(_type[i]){
				case 'G':flag = red_gereral(board, x[i], y[i], g_y); break;
				case 'R':red_chariot(board, x[i], y[i]); break;
				case 'H':red_horse(board, x[i], y[i]); break;
				case 'C':red_cannon(board, x[i], y[i]); break;
			}
		}
		if(is_checkmate(board, g_x, g_y) && !flag){
			printf("YES\n");
		}
		else printf("NO\n");

	}
	return 0;
}
