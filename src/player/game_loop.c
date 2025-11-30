/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:38:26 by gabach            #+#    #+#             */
/*   Updated: 2025/11/30 13:21:48 by gabach           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"
#include "objects.h"
#include "projectile.h"
#include "player.h"
#include "oponents.h"
#include <ncurses.h>

int	game_loop(t_player *player)
{
	int			counter = 0;
	int			ch = 0;
	t_list		*projectiles = NULL;
	t_list		*oponents = NULL;

	*player = init_player();
	while (ch != 'q')
	{
		ch = getch();

		actualize_projectiles(&projectiles, counter);
		actualize_oponent(&oponents, counter, &projectiles);
		player_action(ch, player, &projectiles);

		werase(game_win);

		wattron(game_win, COLOR_PAIR(1));
		box(game_win, ACS_VLINE, ACS_HLINE);
		wattroff(game_win, COLOR_PAIR(1));

		render_projectiles(&projectiles);
		render_oponents(&oponents, &projectiles, player);
		render_obj(player->y, player->x, player->icon);

		print_fps(ch);
		wrefresh(game_win);
		counter++;
	}
	ft_lstclear(&projectiles, free);
	ft_lstclear(&oponents, free);
	return (0);
}
