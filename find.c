#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define SUM_H 1

struct entry 
{
	char *name;
	struct entry *next;
	void *ptr;
};


struct db 
{

	struct entry *list[256];

};

uint8_t hash(int function, char* input)
{
	int i,acc = 0,len = strlen(input);
	for (i = 0;i <= len;i++)
	{
		acc += input[i];
	}

	return (uint8_t) acc;
}

struct entry *find_entry(struct db *searchspace, char *name)
{
	struct entry *found;
	uint8_t index = hash(SUM_H,name);
	
	if ( !searchspace->list[index])
	{
		printf("(find) : No entry found");
		return NULL;
	}

	//printf("%p == %p = %d", searchspace->list[index]->name, name, strcmp(searchspace->list[index]->name, name));

	if ((strcmp(searchspace->list[index]->name,name))== 0)
	{
		//printf("Found a match (%p)",searchspace->list[index]);
		return searchspace->list[index];
	}
	return NULL;
	
}
void *find(struct db *searchspace, char *name)
{
	struct entry *found;
	uint8_t index = hash(SUM_H,name);
	
	if ( !searchspace->list[index])
	{
		printf("(find) : No entry found\n");
		return NULL;
	}

	//printf("%p == %p = %d", searchspace->list[index]->name, name, strcmp(searchspace->list[index]->name, name));
	found = searchspace->list[index];
	do {
		if ((strcmp(found->name,name))== 0)
		{
			//printf("Found a match (%p)",searchspace->list[index]);
			return found->ptr;
		}

		if (found->next == NULL)
		{
			return NULL;
		}

		found = found->next;
	}while (1);
}

void insert(struct db *searchspace, char *name, void *ptr)
{
	uint8_t index = hash(SUM_H,name);
	struct entry *new_entry = (struct entry*) malloc(sizeof(struct entry*));
	
	
	new_entry->name = (char *) malloc(strlen(name) * sizeof(char));
	strcpy(new_entry->name,name);
	new_entry->ptr = ptr;

	new_entry->next = searchspace->list[index];
	searchspace->list[index] = new_entry;
	
	//printf("Inserted %s into the Database\n",(searchspace->list[index])->name);

	return;
}
