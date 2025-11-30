/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabach <gabach@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:35:46 by gabach            #+#    #+#             */
/*   Updated: 2025/11/29 17:44:49 by gabach           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "shmup.h"

int	obj_move(int *row, int *col, char direction)
{
	int	end_rows, end_cols;
	getmaxyx(game_win, end_rows, end_cols);
	if (direction == 'r')
	{
		if (*col == end_cols - 2) return (-1);
		(*col)++;
	}
	else if (direction == 'l')
	{
		if (*col == 1) return (-1);
		(*col)--;
	}
	else if (direction == 'u')
	{
		if (*row == 1) return (-1) ;
		(*row)--;
	}
	else if (direction == 'd')
	{
		if (*row == end_rows - 2) return (-1) ;
		(*row)++;
	}
	return (0);
}

int	render_obj(int row, int col, char icon)
{
	chtype	ch;
	char	c;

	ch = mvwinch(game_win, row, col);
	c = ch & A_CHARTEXT;
	if (c != ' ')
	{
		mvwprintw(game_win, row, col, "%c", icon);
		return (-1);
	}
	mvwprintw(game_win, row, col, "%c", icon);
	return (0);
}
