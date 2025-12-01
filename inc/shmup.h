/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shmup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:50:08 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/30 23:02:42 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHMUP_H
# define SHMUP_H

// INCLUDES

# include "player.h"
# include "ui.h"
# include <ncurses.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// DEFINE

# define STAT_WIDTH (COLS / 6)
# define GAME_WIDTH (5 * STAT_WIDTH)
# define MIN_WIDTH 80
# define MIN_HEIGHT 15
# define FRAME_RATE 60
# define BOX_SIZE 10

# define SHMUP_0 "   __ _         _                           \n"
# define SHMUP_1 "  / _| |       | |                          \n"
# define SHMUP_2 " | |_| |_   ___| |__  _ __ ___  _   _ _ __  \n"
# define SHMUP_3 " |  _| __| / __| '_ \\| '_ ` _ \\| | | | '_ \\ \n"
# define SHMUP_4 " | | | |_  \\__ \\ | | | | | | | | |_| | |_) |\n"
# define SHMUP_5 " |_|  \\__| |___/_| |_|_| |_| |_|\\__,_| .__/ \n"
# define SHMUP_6 "       ______                        | |    \n"
# define SHMUP_7 "      |______|                       |_|    \n"

// GLOBAL

extern WINDOW *stats_win, *game_win, *menu_win, *finish_win;
extern WINDOW *lives_win, *score_win, *time_win;

// STRUCTS

typedef struct s_game
{
	bool		fps_on;
	t_player	player;
	char		*time;
	int			time_m;
	int			time_s;
	int			y_max;
	int			x_max;
}				t_game;

// FUNCS

void			init(t_game *game);
void			finish(t_game game);
int				menu();

#endif
