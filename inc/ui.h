/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 10:16:13 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/30 18:56:35 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_H
# define UI_H

// INCLUDES
# include "shmup.h"
# include "stdbool.h"
// CONST

// FUNCS

void	print_fps(int ch);
void	print_ui(t_game *game);
void	print_score(t_game *game);
void	print_time(t_game *game);
void	print_lives(t_game *game);
void	render_box(WINDOW *win, int color);
void	limit_fps(int sec);

#endif
