/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:38:26 by gabach            #+#    #+#             */
/*   Updated: 2025/11/30 18:54:44 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "obstacle.h"
#include "oponents.h"
#include "player.h"
#include "projectile.h"
#include "shmup.h"
#include "ui.h"

int	game_loop(t_game *game)
{
	int		counter;
	int		ch;
	t_list	*projectiles;
	t_list	*oponents;
	t_list	*obstacles;

	counter = 0;
	ch = 0;
	projectiles = NULL;
	oponents = NULL;
	obstacles = NULL;
	game->player = init_player();
	while (ch != 'q' && game->player.lives >= 0)
	{
		ch = getch();
		actualize_projectiles(&projectiles, counter);
		actualize_oponent(&oponents, counter, &projectiles);
		actualize_obstacles(&obstacles, counter);
		player_action(ch, &game->player, &projectiles);

		refresh();
		werase(game_win);
		render_projectiles(&projectiles);
		render_oponents(&oponents, &projectiles, &game->player);
		render_obstacles(&obstacles, &projectiles);
		render_player(&game->player, &projectiles, &oponents);
		print_ui(game);
		limit_fps(FRAME_RATE);
		game->player.time = counter++;
	}
	ft_lstclear(&projectiles, free);
	ft_lstclear(&obstacles, free);
	ft_lstclear(&oponents, free);
	return (0);
}
