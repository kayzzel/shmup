/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:31:56 by gabach            #+#    #+#             */
/*   Updated: 2025/11/30 14:33:22 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "oponents.h"
#include "projectile.h"
#include "objects.h"

t_player	init_player(void)
{
	t_player	player;

	player.x = START_COL + 5;
	player.y = LINES / 2;
	player.icon = '>';
	player.invincibility = 0;
	player.lives = GAME_LIVES;
	player.score = 0;
	player.direction = 'r';
	player.time = 0.0f;

	move(player.y, player.x);
	addch(player.icon);
	return (player);
}

void	player_action(int c, t_player *player, t_list **projectile)
{
	if (c != -1)
	{
		if (c == 'd')
		{
			obj_move(&player->y, &player->x, 'r');
			player->icon = '>';
			player->direction = 'r';
		}
		if (c == 'a')
		{
			obj_move(&player->y, &player->x, 'l');
			player->icon = '<';
			player->direction = 'l';
		}
		if (c == 'w')
		{
			obj_move(&player->y, &player->x, 'u');
			player->icon = '^';
			player->direction = 'u';
		}
		if (c == 's')
		{
			obj_move(&player->y, &player->x, 'd');
			player->icon = 'v';
			player->direction = 'd';
		}
		if (c == ' ')
			throw_projectile(player->y, player->x, 'o', player->direction, projectile);
	}
}

void	render_player(t_player *player, t_list **projectiles, t_list **oponents)
{
	if (render_obj(player->y, player->x, player->icon) == -1)
	{
		kill_projectile(projectiles, player->y, player->x);
		kill_oponent(oponents, player->y, player->x);
		if (player->invincibility == 0)
		{
			(player->lives)--;
			player->invincibility = 181;
		}
	}
	if (player->invincibility != 0)
		(player->invincibility)--;
}
