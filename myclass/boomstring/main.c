#include"boom.h"

int main()
{
	int x;
	char a[20];
	WORD_NODE *root;
	root = creat();
	for(;;){	
		printf("input the value for fun()\n1: add\n2: del\n3: find\n");
		scanf("%d", &x);
		getchar();
		if(x == 1)
			add_words(root);
		if(x == 2){
			printf("please input the word:\n");
			gets(a);
			del_words(root, a);
		}
		if(x == 3){
			printf("please input the word:\n");
			gets(a);
			if(find_words(root, a))
				printf("exist\n");
			else printf("NONE\n");
		}
	}
	return 0;

}
