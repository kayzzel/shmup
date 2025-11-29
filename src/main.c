#include "shmup.h"
#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>

int	gaming(t_game *game)
{
	game->player.live = 3;
	game->player.score = 500;
	while (1)
	{
		print_fps();
	}
}

int	main(void)
{
	t_game	game;

	init();
	gaming(&game);
	endwin();
	return (0);
}
