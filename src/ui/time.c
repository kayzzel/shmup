/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 11:08:38 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/30 18:55:40 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"
#include "ui.h"

void	print_time(t_game *game)
{
	char	time_str[20];

	int max_y, max_x;
	int total_seconds;
	total_seconds = game->player.time / FRAME_RATE;
	game->time_m = total_seconds / 60;
	game->time_s = total_seconds % 60;
	getmaxyx(time_win, max_y, max_x);
	mvwprintw(time_win, max_y / 2 - 1, max_x / 2 - 2, "TIME");
	sprintf(time_str, "%02d:%02d", game->time_m, game->time_s);
	mvwprintw(time_win, max_y / 2 + 1, max_x / 2 - 2, "%s", time_str);
	wrefresh(time_win);
}
