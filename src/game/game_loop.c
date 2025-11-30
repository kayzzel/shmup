/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:38:26 by gabach            #+#    #+#             */
/*   Updated: 2025/11/30 15:54:26 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
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

	counter = 0;
	ch = 0;
	projectiles = NULL;
	oponents = NULL;
	game->player = init_player();
	while (ch != 'q' && game->player.lives >= 0)
	{
		ch = getch();
		actualize_projectiles(&projectiles, counter);
		actualize_oponent(&oponents, counter, &projectiles);
		player_action(ch, &game->player, &projectiles);
		
		refresh();
		werase(game_win);
		render_projectiles(&projectiles);
		render_oponents(&oponents, &projectiles, &game->player);
		render_player(&game->player, &projectiles, &oponents);
		print_ui(*game, ch);
		limit_fps(FRAME_RATE);
		game->player.time = counter++;
	}
	ft_lstclear(&projectiles, free);
	ft_lstclear(&oponents, free);
	return (0);
}
