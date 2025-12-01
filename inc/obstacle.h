
#ifndef OBSTACLE_H
# define OBSTACLE_H

// INCLUDES

# include "linked_list.h"
# include "projectile.h"

// CONSTS

# define OBSTACLE_SPAWN_RATE 150   // 0 - 199      199 is the max rate

// STRUCTS

typedef struct s_obstacle
{
	int		x;
	int		y;
	char	icon;
	char	direction;
}			t_obstacle;

// FUNCS

void	actualize_obstacles(t_list **obstacles, int counter);
void	kill_obstacle(t_list **obstacles, int row, int col);
void	spawn_obstacle(t_list **obstacles);
void	render_obstacles(t_list **obstacles, t_list **projectiles);

#endif
