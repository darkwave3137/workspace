#include<stdio.h>
#include<string.h>
#define N 12
int board[N][N];
int gx[] = /*{1, -1, 0, 0}*/{-1, 1, 0, 0};
int gy[] = /*{0, 0, 1, -1}*/{0, 0, -1, 1};
int hcx[] = /*{2, 2, 1, 1, -1, -1, -2, -2}*/{-2, -1, -2, -1 , 1, 2, 1, 2};
int hcy[] = /*{-1, 1, -2, 2, -2, 2, -1, 1}*/{-1, -2, 1, 2, -2, -1, 2, 1};
int hncx[] = /*{1, 1, 1, 1, -1, -1, -1, -1}*/{-1, -1, -1, -1, 1, 1, 1, 1};
int hncy[] = /*{-1, 1, -1, 1, -1, 1, -1, 1}*/{-1, -1, 1, 1, -1, -1, 1, 1};
int cr[2], cc[2];
int check(int x, int y)
{
	if(x < 1 || x > 3 || y < 4 || y > 6) return 1;
/*	int flag = 0;*/
	for(int i = y - 1; i > 0; i--){
		if(board[x][i]){
			if(board[x][i] == 'R'/* && !flag*/)
				return 1;
			else break;/* if(!flag){
				flag = 1; 
				continue;
			}
		if(flag)
			if(board[x][i] == 'C')
				return 1;
			else break;*/
		}
	}
/*	flag = 0;*/
	for(int i = y + 1; i < 10; i++){
		if(board[x][i]){
			if(board[x][i] == 'R'/* && !flag*/)
				return 1;
			else break;/*if(!flag){
				flag = 1; 
				continue;
			}
		if(flag)
			if(board[x][i] == 'C')
				return 1;
			else break;*/
		}
	}
	for(int i = x - 1; i > 0; i--){
		if(board[i][y]){
			if(board[i][y] == 'R'/* && !flag*/)
				return 1;
			else break;
		}
	}
/*	flag = 0;*/
	for(int i = x + 1; i < 11; i++){
		if(board[i][y]){
			if((board[i][y] == 'R' || board[i][y] == 'G')/* && !flag*/)
				return 1;
			else break;/*if(!flag){
				flag = 1;
				continue;
			}
		if(flag)
			if(board[i][y] == 'C')
				return 1;
			else break;*/
		}
	}
	int cnt;
	for(int k = 0; k < 2; ++k){
		if(cr[k] == x){
			for(int j = y - 1, cnt = 0; j > cc[k]; --j)if(board[x][j]) ++cnt;
			if(cnt == 1) return 1;
			for(int j = y + 1, cnt = 0; j < cc[k]; ++j)if(board[x][j]) ++cnt;
			if(cnt == 1) return 1;
		}
		if(cc[k] == y){
			for(int i = x - 1, cnt = 0; i > cr[k]; --i)if(board[i][y]) ++cnt;
			if(cnt == 1) return 1;
			for(int i = x + 1, cnt = 0; i < cr[k]; ++i)if(board[i][y]) ++cnt;
			if(cnt == 1) return 1;
		}
	}
	for(int i = 0; i < 8; i++){
		int hx = x + hcx[i], hy = y +hcy[i];
	/*	if(hx > 0 && hy > 0 && hx < 11 && hy < 10)*/
		if(hx < 1 || hx > 10 || hy < 1 || hy > 9) continue; 
		if(board[hx][hy] == 'H')
				if(!board[x + hncx[i]][y + hncy[i]])
					return 1;
	}
	return 0;
}

int main()
{
	int x, y, g_x, g_y, n;
	while(scanf("%d%d%d", &n, &g_x, &g_y), n || g_x || g_y){
		memset(board, 0, N * N * sizeof(int));
		cr[0] = cc[0] = cr[1] = cc[1] = 0;
		while(n--){
		/*	getchar();*/
			char _type[5];
			scanf("%s%d%d", _type, &x, &y);
			if(_type[0] == 'C'){
				if(cr[0]) cr[1] = x, cc[1] = y;
				else cr[0] = x, cc[0] = y;
			}
			board[x][y] = _type[0];
		}
		int an = 0;
		for(int i = 0; i < 4; i++){
	/*		if(g_x + gx[i] > 0 && g_x + gx[i] < 4 && g_y + gy[i] > 3 && g_y + gy[i] < 7 )*/
				an += check(g_x + gx[i], g_y + gy[i]);
		/*	else an++;*/
		}
		if(an == 4)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
