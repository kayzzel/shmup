#include "shmup.h"
#include <ncurses.h>
#include <stdio.h>
#include <time.h>

int	main(void)
{
	int		choice;
	int		ch;
	t_game	game;

	init(&game);
	clear();
	noecho();
	cbreak();
	halfdelay(1);
	while (true)
	{
		printw("Coucou\n");
		refresh();
	}
	endwin();
	return (0);
}
