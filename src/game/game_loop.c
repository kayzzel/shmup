/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:38:26 by gabach            #+#    #+#             */
/*   Updated: 2025/11/30 23:06:46 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "explosion.h"
#include "objects.h"
#include "obstacle.h"
#include "oponents.h"
#include "player.h"
#include "projectile.h"
#include "shmup.h"
#include "ui.h"
#include <stdio.h>

int	game_loop(t_game *game)
{
	int		max_y;
	int		max_x;
	int		counter;
	int		ch;
	t_list	*projectiles;
	t_list	*oponents;
	t_list	*obstacles;
	t_list	*explosions;

	counter = 0;
	ch = 0;
	projectiles = NULL;
	oponents = NULL;
	obstacles = NULL;
	explosions = NULL;
	while (game->player.lives >= 0)
	{
		getmaxyx(stdscr, max_y, max_x);
		if (max_y != game->y_max || max_x != game->x_max)
			break ;
		ch = getch();
		if (ch == 27)
			if (menu() == 1)
				break ;
		actualize_projectiles(&projectiles, counter);
		actualize_oponent(&oponents, counter, &projectiles);
		actualize_obstacles(&obstacles, counter);
		player_action(ch, &game->player, &projectiles);
		refresh();
		werase(game_win);
		render_projectiles(&projectiles);
		render_explosion(&explosions);
		render_oponents(&oponents, &projectiles, &game->player, &explosions);
		render_obstacles(&obstacles, &projectiles);
		render_player(&game->player, &projectiles, &oponents);
		print_ui(game);
		limit_fps(FRAME_RATE);
		game->player.time = counter++;
	}
	ft_lstclear(&projectiles, free);
	ft_lstclear(&obstacles, free);
	ft_lstclear(&oponents, free);
	ft_lstclear(&explosions, free);
	return (0);
}
