#include<stdio.h>
#include<string.h>
int main()
{
	char a[31], _tmp[6];
	char ch, ac, ac1;
	int n = 1, space = 0, an, swap, _new, er = 1;
	char *s = " ";
	while(n++){
		ac = ac1 = '0';
		memset(a, '\0', sizeof(a));
		for(int i = 0; i < 5; i++){     //six string;
			scanf("%5[^\n]", _tmp);
		/*	printf("%s\n", _tmp);*/
/*			scanf(" ");*/
	/*		while((ch = getchar()) != '\n')
				;*/
			while(getchar() != '\n')
				;
			strncat(a, _tmp, 6);
			strncat(a, s, 1);
			if(a[0] == 'Z' && a[1] == ' ' && a[2] == '\0')
				return 0;
			/*for(int i = 0; i < strlen(_tmp); i++){
				if(_tmp[i] == 'Z')
					return 0;
			}*/
		}
			

		/*while((ch = getchar() != '\n'))
			;*/
	

		for(int i = 0;;i++){
			if((i + 1) % 6 != 0 && a[i] == ' '){
				space = i;
				break;
			}
		}
/*		printf("%d\n", space);*/
		an = 1;
		swap = 0;
		er = 1;
		while((ch = getchar()) != '0'){
			switch(ch){
				case 'A': swap = -6; break;
				case 'B': swap = 6; break;
				case 'L': swap = -1; break;
				case 'R': swap = 1; break;
		/*	case ' ': */
				case '\n':continue;
				default: er = 0;/* break;*/
			}
			if(((_new = space + swap) + 1) % 6 == 0 || _new < 0 || _new > 28){
				an = 0;
				break;
			}
			a[space] = a[_new];
			a[_new] = ' ';
			space = _new;
		}
		while(ch = getchar(), ac != '0' || ch != '\n'){
			ac = ch;
			er = 0;
		}
			
			
	/*	if(!er)
			goto error;*/
/*		printf("%s", _tmp);*/
		                  //why????
	/*	printf("%s\n", a);*/
		printf("Puzzle #%d:\n", n - 1);
	/*	if(!er){
			while
		}*/
		if(!an || !er){
/*	error:*/printf("This puzzle has no final configuration.\n\n");
			continue;
		}
		for(int i = 0; i < 30; i++){
			if((i + 1) % 6 == 0){
				printf("\n");
				continue;
			}
			printf("%c", a[i]);
			if((i + 1) % 6 < 5 && (i + 1) % 6 != 0)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
