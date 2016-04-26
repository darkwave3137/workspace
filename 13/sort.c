#include<stdio.h>
#include<string.h>
#include<ctype.h>
int split(void *root, int low, int high, int size, int(*cmp)(void const*, void const*));
void sort(void *root, int len, int size, int (*cmp)(void const* , void const *))
{
	int low = 0, high = len - 1;
	int middle_c;
	char *c_root;
	if(low >= high)
		return;
	middle_c = split(root, low, high, size, cmp);
	c_root = ((char *)root + (middle_c + 1) * size);
	if(middle_c > 0)
		sort(root, middle_c, size, cmp);
	sort(/*(char *)root + (middle_c + 1) * size*/c_root, high + 1 - (int)(c_root - (char *)root) / size/*保持函数格式*/, size, cmp);
		
}
int split(void *root, int low, int high, int size,  int (*cmp)(void const * , void const *))
{
	char middle[size/* / (sizeof(char) * 8)*/];
	memcpy(middle, ((char *)root + low * size), size);
	for(;;){
		if(low >= high)
			break;
		while(low < high && cmp(middle, ((char *)root + high * size)) < 0){
			high--;
		}
		memcpy(((char *)root + low++ * size),((char *)root + high * size), size);
		if(low >= high)
			break;
		while(low < high && cmp(middle, ((char *)root + low * size)) > 0){
			low++;
		}
		/*if(cmp(((char *)root + low * size), ((char *)root + high * size)) == 0 && high != 0)
			high--;*/
		memcpy(((char *)root + high/*--*/ * size), ((char *)root + low * size), size);
	}
	memcpy(((char *)root + high * size), middle, size);
	return high;/*(int)(middle - (char *)root) / size;*/
}
int int_cmp(void const *a, void const *b)
{
	return *(int *)a - *(int *)b;	
}
int str_cmp(void const *a, void const *b)
{
	return strcmp(*(char **)a, *(char **)b);
}
int cha_cmp(void const *a, void const *b)
{
	return *(char *)a - *(char *)b;
}


int main()
{
	char *a[4] = {"cc", "aabb", "aa", "bb"};
 	int b[5] = {4, 7, 8, 6, 6};
	sort(a, 4, sizeof(char *), str_cmp);
	printf("%s\n%s\n%s\n%s\n", a[0], a[1], a[2], a[3]);
/*	sort(b, 5, sizeof(int), cha_cmp);
	for(int i = 0; i < 5; i++){
		printf("%d\n", b[i]);
	}*/
	return 0;	
}	
