/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 11:08:38 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/30 16:38:23 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"
#include "ui.h"

void	print_time(t_game game)

{
	int max_y, max_x;
	int score_len;
	char score_str[20];

	getmaxyx(time_win, max_y, max_x);
	mvwprintw(time_win, max_y / 2 - 1, max_x / 2 - 2, "TIME");
	sprintf(score_str, "%f", game.player.time);
	score_len = strlen(score_str);
	mvwprintw(time_win, max_y / 2 + 1, max_x / 2 - (score_len / 2), "%f",
		game.player.time);
	wrefresh(time_win);
}
