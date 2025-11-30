/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shmup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:50:08 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/30 15:37:49 by enchevri         ###   ########lyon.fr   */
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
# define MIN_HEIGHT 20
#define FRAME_RATE 120

// GLOBAL

extern WINDOW *stats_win, *game_win;
extern WINDOW *lives_win, *score_win, *time_win;

// STRUCTS

typedef struct s_game
{
	bool		fps_on;
	t_player	player;
}				t_game;

// FUNCS

void			init(void);

#endif
