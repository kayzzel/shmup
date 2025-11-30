/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scores.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 10:32:21 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/30 14:00:47 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"
#include "ui.h"

void	print_score(t_game game)
{
	int		score_len;
	char	score_str[20];
	int max_y, max_x;
    

	getmaxyx(score_win, max_y, max_x);
	mvwprintw(score_win, max_y / 2 - 1, max_x / 2 - 3, "SCORES");
	sprintf(score_str, "%d", game.player.score * 100);
	score_len = strlen(score_str);
	mvwprintw(score_win, max_y / 2 + 1, max_x / 2 - (score_len / 2), "%d",
		game.player.score);
	wrefresh(score_win);
}
