#ifndef MAIN_C
#define MAIN_C


#include <stdio.h>
#include <string.h>
#include <ncurses.h>

#include "find.c"
#include "hl.c"

#define ST_QUIT -1


int main(int argc, char ** args)
{
	int c, status = 0;
	char * buffer;
	initscr();
	noecho();
	cbreak();
	keypad(stdscr,true);
	raw();	
	clear();
	struct db *maindb = c_db();

	while (status != ST_QUIT)
	{	
		buffer = hl_lex(getch());
		
		if (buffer != NULL)
		{
			if (buffer == "quit" ) { //Found Keyword
				break;
			} else if (buffer == "\n") { //Found new line

			} else { //Found no significant String
		
			}
		}

	}

	endwin();
}


#endif
