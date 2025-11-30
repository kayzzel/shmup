/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:00:17 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/30 22:29:10 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"
#include <ncurses.h>

WINDOW *stats_win, *game_win, *menu_win, *finish_win;
WINDOW *lives_win, *score_win, *time_win;

void	init_colors(void)
{
	start_color();
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_WHITE);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_GREEN, COLOR_BLACK);
	init_pair(6, COLOR_YELLOW, COLOR_BLACK);
}

void	init_windows(void)
{
	menu_win = subwin(stdscr, MIN_HEIGHT, MIN_WIDTH, (LINES - MIN_HEIGHT) / 2,
			(COLS - MIN_WIDTH) / 2);
	finish_win = subwin(stdscr, MIN_HEIGHT, MIN_WIDTH, (LINES - MIN_HEIGHT) / 2,
			(COLS - MIN_WIDTH) / 2);
	if (LINES % 3 != 0)
		game_win = subwin(stdscr, LINES - 1, GAME_WIDTH, 0, STAT_WIDTH);
	else
		game_win = subwin(stdscr, LINES, GAME_WIDTH, 0, STAT_WIDTH);
	stats_win = subwin(stdscr, LINES, STAT_WIDTH, 0, 0);
	lives_win = subwin(stats_win, LINES / 3, STAT_WIDTH, 0, 0);
	score_win = subwin(stats_win, LINES / 3, STAT_WIDTH, LINES / 3, 0);
	time_win = subwin(stats_win, LINES / 3, STAT_WIDTH, LINES / 3 * 2, 0);
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

void	init(t_game *game)
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
	cbreak();
	keypad(stdscr, true);
	game->time_m = 0;
	game->time_s = 0;
	game->player = init_player();
	curs_set(0);
}
