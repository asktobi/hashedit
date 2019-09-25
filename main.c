#include <stdio.h>
#include <stdlib.h>
#include "find.c"

#define TEST_STR "shfkajsf"

int main(int argc, char **args){

	struct db *searchspace = (struct db *)malloc(sizeof(struct db));
	char * name = (char *) malloc(strlen(TEST_STR) * sizeof(char));
	strcpy(name, TEST_STR);
	insert(searchspace,name,name);
	void *got_name =  find(searchspace,name);
	printf("... %p ...\n",got_name);

	return 0;
}
