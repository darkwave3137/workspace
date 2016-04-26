#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void *my_calloc(size_t num_elements, size_t element_size)
{
	void *p = malloc(num_elements * element_size);
	memset(p, '0', num_elements * element_size);
	return p;
}

int main()
{
	int *p;
	p = my_calloc(2, sizeof(int));
	for(int i = 0; i < sizeof(p); i++){
		printf("%c", *(char *)p);
	}
	return 0;
}
