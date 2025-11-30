#ifndef EXPLOSION_H
# define EXPLOSION_H

// INCLUDES

# include "linked_list.h"
# include "shmup.h"

// STRUCTS

typedef struct	s_explosion
{
	int	row;
	int	col;
	int	step;
}				t_explosion;

// FUNCS

void	render_explosion(t_list **explosions);
t_explosion	*new_explosion(int row, int col);
void	spawn_explosion(t_list **explosions, int row, int col);
void	render_explosion(t_list **explosions);

#endif
