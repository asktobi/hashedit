#include <stdio.h>
#include <stdlib.h>
#include "find.c"

#define NAME_STR "helo"
#define TEST_STR "Text from first !"
#define NAME2_STR "hdlp"
#define TEST2_STR "Text from secound !"

int main(int argc, char **args){

	struct db *searchspace = (struct db *)malloc(sizeof(struct db));
	char * name = (char *) malloc(strlen(NAME_STR) * sizeof(char));
	char * test = (char *) malloc(strlen(TEST_STR) * sizeof(char));
	
	char * name2 = (char *) malloc(strlen(NAME2_STR) * sizeof(char));
	char * test2 = (char *) malloc(strlen(TEST2_STR) * sizeof(char));

	strcpy(name, NAME_STR);
	strcpy(test, TEST_STR);
	
	strcpy(name2, NAME2_STR);
	strcpy(test2, TEST2_STR);
	
	insert(searchspace,name,test);
	insert(searchspace,name2,test2);
	printf("(%s): %s\n",name,find(searchspace,name));
	printf("(%s): %s\n",name2,find(searchspace,name2));
	printf("(NOENTRY): %s\n",find(searchspace,"NOENTRY"));
	

	return 0;
}
