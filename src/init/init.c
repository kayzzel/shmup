/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:00:17 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/30 17:11:15 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"

WINDOW *stats_win, *game_win;
WINDOW *lives_win, *score_win, *time_win;

void	init_colors(void)
{
	start_color();
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_WHITE);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_GREEN, COLOR_BLACK);
}

void	init_windows(void)
{
	stats_win = subwin(stdscr, LINES, STAT_WIDTH, 0, 0);
	lives_win = subwin(stats_win, LINES / 3, STAT_WIDTH, 0, 0);
	score_win = subwin(stats_win, LINES / 3, STAT_WIDTH, LINES / 3, 0);
	time_win = subwin(stats_win, LINES / 3, STAT_WIDTH, LINES / 3 * 2, 0);
	if (LINES % 3 != 0)
		game_win = subwin(stdscr, LINES - 1, GAME_WIDTH, 0, STAT_WIDTH);
	else
		game_win = subwin(stdscr, LINES, GAME_WIDTH, 0, STAT_WIDTH);
}
int	check_terminal_scale(void)
{
	int	n;

	n = 0;
	if (LINES < MIN_HEIGHT)
	{
		endwin();
		printf("Error\nYour terminal is to small in height\n");
		n++;
	}
	if (COLS < MIN_WIDTH)
	{
		endwin();
		printf("Error\nYour terminal is to small in width\n");
		n++;
	}
	return (n);
}

void	init(void)
{
	initscr();
	if (check_terminal_scale())
	{
		endwin();
		exit(1);
	}
	if (has_colors() == FALSE)
	{
		endwin();
		printf("Error\nYour terminal does not support color\n");
		exit(1);
	}
	init_colors();
	init_windows();
	initscr();
	noecho();
	timeout(0);
	cbreak();
	keypad(stdscr, true);
	curs_set(0);
}
