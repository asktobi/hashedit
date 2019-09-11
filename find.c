#include <stdint.h>
#include <string.h>

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


void *find(struct db *searchspace, char *entry_name)
{
	struct entry *found;
	uint16_t index = hash(SUM_H,entry_name);
	
	if ( (found = db->list[index] ))
	{
		printf("(find) : No entry found");
		return NULL;
	}

	if (strcmp(found->name,entry_name))
	{
		return found->ptr;
	}
	return NULL;
	
}


