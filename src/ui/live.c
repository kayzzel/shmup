/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 11:39:56 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/30 18:57:16 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "shmup.h"
#include "ui.h"

void	print_lives(t_game *game)

{
	int max_y, max_x;
	int score_len;
	char live_str[20];


	getmaxyx(lives_win, max_y, max_x);
	mvwprintw(lives_win, max_y / 2 - 1, max_x / 2 - 2, "LIVES");
	sprintf(live_str, "%d", game->player.lives);
	score_len = strlen(live_str);
	mvwprintw(lives_win, max_y / 2 + 1, max_x / 2 - (score_len / 2), "%d",
		game->player.lives);
}
