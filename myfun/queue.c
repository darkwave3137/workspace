#include<stdio.h>
#include"queue.h"
#include<assert.h>
/*#define QUEUE_TYPE int*/
typedef struct QUEUE_NODE{
	QUEUE_TYPE value;
	struct QUEUE_NODE* next;
}queue_node;

static queue_node* front;
static queue_node* rear;

void insert(QUEUE_TYPE value)
{
	queue_node* new_node;
	new_node = malloc(sizeof(queue_node));
	if(new_node == NULL){
		exit(EXIT_FAILURE);
	}
	new_node -> value = value;
	new_node -> next = NULL;
	if(is_empty())
		rear = front = new_node;
	else {
		rear -> next = new_node;
		rear = new_node;
	}
}

void destory_queue(void)
{
	while(front != NULL){
		delete();
	}		
}

void delete(void)
{
	assert(!is_empty());
	queue_node* old_node = front;
	front = front -> next;
	free(old_node);
}

QUEUE_TYPE first(void)
{
	assert(!is_empty());
	return front -> value;
}

int is_empty(void)
{
	return front == NULL;
}

int main()
{
	while(1){
		int x, y;
		scanf("%d", &x);
		switch(x){
			case 1: scanf("%d", &y); insert(y); break;
			case 2: delete(); break;
			case 3: y = first(); printf("%d\n", y); break;
			case 4: destory_queue();
			case 0: return 0;
		}	
	}
}
