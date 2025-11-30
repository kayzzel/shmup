
#ifndef OPONENTS_H
# define OPONENTS_H

// INCLUDES

# include "linked_list.h"
# include "player.h"
# include "projectile.h"

// CONSTS

# define OPONENT_SPAWN_RATE 100   // 0 - 199      199 is the max rate
# define SHOOTING_RATE 80 // 0 - 99        99 is the max rate

// STRUCTS

typedef struct s_oponent
{
	int		x;
	int		y;
	char	icon;
	char	direction;
}			t_oponent;

// FUNCS

void		spawn_oponent(t_list **oponents);
t_oponent	*new_oponent(int row, int col, char icon, char direction);
void		actualize_oponent(t_list **oponents, int counter,
				t_list **projectiles);
void		kill_oponent(t_list **projectiles, int row, int col);
void	render_oponents(t_list **oponents, t_list **projectiles,
		t_player *player, t_list **explosions);

#endif
