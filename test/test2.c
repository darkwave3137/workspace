#include<stdio.h>
#include<ctype.h>
int main()
{
	FILE *fp = fopen("/home/darkwave/workspace/test/file1", "rw");
	char ch;
	if(fp != NULL){
		while(isdigit(ch = getc(fp)))
			putchar(ch);
		ungetc(ch, fp);
		fseek(fp, -1, SEEK_CUR);
			putchar(ch);
			ch = getc(fp);
			putchar(ch);
			putchar(getc(fp));
			putchar(getc(fp));
			putchar(getc(fp));
			fclose(fp);
	}
	return 0;
}
