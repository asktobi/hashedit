#include <stdio.h>
#include <string.h>
#include <ncurses.h>

#include "find.h"

int main(int argc, char ** args)
{
	int i;
	initscr();
	noecho();
	cbreak();
	keypad(stdscr,true);
	raw();	
	clear();

	for (i = 0; i < 10; i++)
	{
		printw("%c",getch());
	}





	endwin();
}

