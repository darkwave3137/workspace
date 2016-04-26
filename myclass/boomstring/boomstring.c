#include"boom.h"
int k = 0;
int add_words(Root root)
{
	int len = 0;
	char twords[20] = {0};
	WORD_NODE *this = root -> this_level;
	printf("plase input the word:\n");
	gets(twords);
	if(twords[19] != '\0' && twords[19] != 0){
		printf("Input error");
		return FALSE;
	}
	if(find_words(root, twords)){
		printf("the word is already exist");
		return FALSE;
	}
	len = strlen(twords);
	
	for(int i = 0; i < len - 1; i++){
		if(root -> this_level  == NULL){
			root -> this_level = creat_next();
		/*	root = (WORD_NODE*)malloc(sizeof(WORD_NODE));*/
			root -> this_level -> chr = (int)twords[i];
		/*	root -> this_level = NULL;
			root -> next_level = NULL;*/
			this = root -> this_level;
			i--;	
			continue;
		}
		while(this -> chr != twords[i]){
			if(this -> this_level != NULL){
				this = this -> this_level;
				continue;
			}
			this = this -> this_level = creat_next();
			this -> chr = twords[i];
		}
		if(i < len - 1){
			if(this -> next_level != NULL){
				this = this -> next_level;
				continue;
			}
			this = this -> next_level = creat_next();
			this -> chr = twords[i + 1];
		}
	}
}

int del_words(Root root, char *words)
{
	if(!find_words(root, words)){
		printf("not have such word\n");
		return FALSE;
	}
	WORD_NODE *this;
	this = root -> this_level;
	int len = strlen(words);
	WORD_NODE **p;
	p = malloc(sizeof(WORD_NODE) * len);

	for(int i = 0, j = 1; i < len; i++){
		k = i;
		/*if(i < len - 1){
			if(this -> next_level -> this_level== NULL){
				free(this);
			*	j = 0;*
				return TRUE;
			}
		}*/
		while(this -> chr != words[i]){
			this = this -> this_level;
			
			continue;
		}
		if(i == len - 1 && this -> next_level != NULL){
			i--;
			this = this -> this_level;
			continue;
		}
		if(i < len){	
			p[i] = this;
			if(i != len - 1)
				this = this -> next_level;
		continue;
		}
		
	}
	/*free(p[len -1]);*/
		p[len - 2] -> next_level = p[len - 1] -> this_level;
		free(p[len - 1]);
		for(int i = len - 2; i >= 0; i--){
			if(p[i] -> this_level != NULL || p[i] -> next_level != NULL){ 
				return TRUE;
		}
		else if(i - 1 >= 0){
			p[i - 1] -> next_level = p[i] -> this_level;
			free(p[i]);
		} 
		if(i = 0){
			free(p[i]);
			root -> this_level = NULL;
			return TRUE;
		}
			
	}
	return TRUE;


}
int set_words(char *words);

int find_words(Root root, char *words)
{
	int len = strlen(words);
	WORD_NODE *this = root -> this_level;
	if(this == NULL)
		return FALSE;
	if(len <= 0){
		printf("error");
		return FALSE;
	}
	for(int i = 0; i < len; i++){
		while(words[i] != this -> chr){
			if(this -> this_level == NULL)
				return FALSE;
			this = this -> this_level;
			
		}
		if(this  == NULL && i != len - 1)
		/*	else*/		
			return FALSE;
	
		if(this -> next_level != NULL && i != len - 1){
			this = this -> next_level;
		}
		else if(this -> next_level == NULL && i == len - 1)
				return TRUE;
		else 
			return FALSE;
	}

}

WORD_NODE *creat()
{
	WORD_NODE *root;
	root = malloc(sizeof(WORD_NODE));
	return root;
}

WORD_NODE *creat_next()
{
	WORD_NODE *next;
	next = malloc(sizeof(WORD_NODE));
	next -> this_level = NULL;
	next -> next_level = NULL;
	next -> chr = '\0';
	return next;
}
