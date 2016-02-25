#include "network.h"
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

/*
 * Parse the response header for content length.  To be used with flex lexer
 */
#define BUFSIZE 100
int get_num(char *text)
{
	char *stop;
	char c;
	int i;
	int num;

	char number[BUFSIZE];
	for(i = 0; i < strlen(text); ++i){
		c = text[i];
		if(c == ':')
			break;

	}
	++i;

//	printf("TEXT: %s\n" , text);
	
	if(strlen(&text[i]) < BUFSIZE){
		strcpy(number , &text[i]);	
//		printf("%s\n" , number);	
		num = atoi(number);

//		printf("THE LENGTH IS %d\n" , num);

		return num;	
	}

	else
		return -1;	
}


