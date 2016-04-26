#include<stdio.h>
#include<string.h>
char s[101000];
char t[101000];
int main()
{
	while(scanf("%s%s", s, t) != EOF){
		int len_s = strlen(s);
		int ans = 1;
		for(int i = 0, j = 0; i < len_s; i++, j++){
			for(; t[j] != '\0'; j++){
				if(s[i] == t[j]){
					break;
				}
			}
				if(t[j] == '\0'){
					ans = 0;
					break;
				 }
		}	
		if(ans)
			printf("Yes\n");
		else printf("No\n");
		
	}
	return 0;
}
