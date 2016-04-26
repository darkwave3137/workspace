#include<stdio.h>
int main()
{
	int s = 0;
	for(int i = 1; i <= 3; i++)
		for(int j = 1; j <= 3; j++)
			for(int k = 1; k <= 3; k++)
				if(i != j && j != k && i != k)
					s = i * 100 + j * 10 + k,
					printf("%d %d %d\n", s, s * 2, s * 3);
	return 0;
}
