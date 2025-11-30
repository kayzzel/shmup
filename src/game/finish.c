/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:39:53 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/30 19:00:06 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"

void	finish(t_game game)
{
	char	str1[128], str2[128];
	int win_height, win_width;
    
	timeout(-1);
	wclear(finish_win);
	render_box(finish_win, 2);
	sprintf(str1, "GG you survived %02d:%02d", game.time_m, game.time_s);
	sprintf(str2, "You killed %d enemies for a total of %d points",
		game.player.score, game.player.score * 100);
	getmaxyx(finish_win, win_height, win_width);
	mvwprintw(finish_win, win_height / 2 - 2, (win_width - strlen("FINISHED"))
		/ 2, "FINISHED");
	mvwprintw(finish_win, win_height / 2 - 1, (win_width - strlen(str1)) / 2,
		"%s", str1);
	mvwprintw(finish_win, win_height / 2, (win_width - strlen(str2)) / 2, "%s",
		str2);
	mvwprintw(finish_win, win_height / 2 + 2, (win_width
			- strlen("Press any key")) / 2, "Press any key");
	wrefresh(finish_win);
	getch();
}
