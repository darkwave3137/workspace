#include<stdio.h>
int main()
{
	double i = 1;
	for(;i != 0; i /= 10){
		printf("%f\n", i);
	}
	return 0;
}
