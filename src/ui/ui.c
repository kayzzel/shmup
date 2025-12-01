/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 10:11:48 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/30 18:56:56 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"
#include "ui.h"

void	print_ui(t_game *game)
{
	print_score(game);
	print_time(game);
	print_lives(game);
	if (game->player.invincibility <= 0 || game->player.invincibility % 30 < 10)
	{
		render_box(score_win, 1);
		render_box(game_win, 1);
		render_box(time_win, 1);
		render_box(lives_win, 1);
	}
	else
	{
		render_box(score_win, 3);
		render_box(game_win, 3);
		render_box(time_win, 3);
		render_box(lives_win, 3);
	}
	wrefresh(score_win);
	wrefresh(time_win);
	wrefresh(lives_win);
	wrefresh(game_win);
}
