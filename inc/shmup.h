#ifndef SHMUP_H
# define SHMUP_H

# include <ncurses.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_game
{
	int	row;
	int	col;
}		t_game;

void	init(t_game *game);

#endif // !SHMUP_H