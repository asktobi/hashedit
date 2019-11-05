#include <stdio.h>
#include <string.h>

#include "find.c"


void main(){

	char test_str[256];

	do {
	scanf("%s",test_str);
	printf("(%s): %d\n",test_str,hash(SUM_H,test_str));

	}while (strcmp(test_str,"q"));

	return;


}
