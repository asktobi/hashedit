#ifndef HL_C
#define HL_C

#include <ncurses.h>
#include <stdlib.h>
#include "find.c"

#define MAX_LEN

char* hl_lex(char c)
{
	printw("%c",c);
	if (c == 'q')
		return "quit";
	refresh();	
	return NULL;
}

#endif
