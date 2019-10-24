#include <stdio.h>
#include <string.h>
#include <ncurses.h>

#include "find.c"
#include "hl.c"


int main(int argc, char ** args)
{
	int i,c;
	initscr();
	noecho();
	cbreak();
	keypad(stdscr,true);
	raw();	
	clear();
	struct db *maindb = c_entry();

	for (i = 0; i < 10; i++)
	{
		c = getch();	
		hl_tick(getch(), maindb);
		

	}





	endwin();
}

