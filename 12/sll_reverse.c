#include<stdio.h>
#incldue<string.h>

typedef struct top{
	struct top * next;
	int value;
}singsll;

singsll root;


struct top * sll_reverse(struct top* first)
{
	singsll tmp, fir = first;
	while(first -> next != NULL	){
		tmp = first -> next -> next;
		first -> next -> next = first;
		if(tmp != NULL)
			first = tmp;
		else break;
	}
	fir -> next = NULL;
	first = first -> next;
	return first;
}

int main()
{
		
}
