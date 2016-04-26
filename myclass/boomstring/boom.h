#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct WORD_NODE1{
	char chr;
	struct WORD_NODE1 *this_level;
	struct WORD_NODE1 *next_level;
};

/*typedef struct WORD_NODE1 WORD_NODE;*/
#define WORD_NODE struct WORD_NODE1

typedef WORD_NODE* Root;

#define FALSE 0
#define TRUE 1

WORD_NODE *creat();
int add_words(Root root);
int del_words(Root root, char *words);
int set_words(char *words);
int find_words(Root root, char *words);
WORD_NODE* creat_next();
/*typedef struct WORD_NODE{
    char chr;
    struct WORD_NODE *this_level;
    struct WORD_NODE *next_level;
}WORD_NODE;


typedef WORD_NODE* Root;

#define FALSE 0
#define TRUE 1

WORD_NODE * creat_p();
int add_words(Root root);
int del_words(Root root, char *words);
int set_words(char *words);
int find_words(Root root, char *words);
WORD_NODE* creat_next();*/
