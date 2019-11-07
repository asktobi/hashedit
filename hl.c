#ifndef HL_C
#define HL_C

#include <ncurses.h>
#include <stdlib.h>
#include "find.c"

size_t MAX_LEN = 256;





char * hl_lex(char *buffer, char c)
{

#define STATUS_HELP

#ifdef STATUS_HELP
	printw("(%d)-> %c\n",c ,c);
#endif
	if (strlen(buffer) >= MAX_LEN )
	{
		MAX_LEN *= 2;
		char * nbuffer = (char *) malloc(sizeof(char) * MAX_LEN );
		strcpy(nbuffer, buffer);
		free(buffer);
		buffer = nbuffer;
	}

	switch (c)
	{
		case 7:          //Backspace
			
			break;
		case 10:         //Enter
			break;
		case '\t':       //Tab
			break;
		default:
			printw("%c",c);
			
	
	}
	
	
		
	refresh();	
	return NULL;
}

#endif
