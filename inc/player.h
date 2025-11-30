/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:27:37 by gabach            #+#    #+#             */
/*   Updated: 2025/11/30 14:21:50 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

// INCLUDES

# include "linked_list.h"
# include <ncurses.h>
# include <stdlib.h>
# include <unistd.h>

// CONST

# define START_COL (COLS / 6 + 1)
# define START_LINE (1)
# define END_COL ((COLS / 6) * 6 - 2)
# define END_LINE (LINES - 2)
# define GAME_LIVES 3

// DECLARATION

typedef struct s_game	t_game;

// STRUCTS

typedef struct s_player
{
	int					x;
	int					y;
	char				icon;
	char				direction;
	int					lives;
	int					score;
	double				time;
	int					invincibility;
}						t_player;

// FUNCS

int						game_loop(t_game *game);
t_player				init_player(void);
void					player_action(int c, t_player *player,
							t_list **projectile);
void	render_player(t_player *player, t_list **projectiles, t_list **oponents);

#endif
