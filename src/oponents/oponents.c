/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oponents.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 21:24:20 by gabach            #+#    #+#             */
/*   Updated: 2025/11/30 10:11:51 by gabach           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include <stdlib.h>
#include "oponents.h"

void	actualize_oponent(t_list **oponents, int counter, t_list **projectiles)
{
	t_list		*last;
	t_list		*current;
	t_oponent	*oponent;

	if (counter % (100) == 0)
		spawn_oponent(oponents);
	if (*oponents == NULL || !oponents || counter % 10 != 0)
		return ;
	current = *oponents;
	last = NULL;
	while (current)
	{
		oponent = (t_oponent*)current->content;
		if ((rand() % 100 + 1) % 20 == 0)
			throw_projectile((oponent->y), (oponent->x), '-', (oponent->direction), projectiles);
		if (obj_move(&(oponent->y), &(oponent->x), (oponent->direction)) == -1)
			current = lstdel_relink(oponents, current, last);
		else
			current = current->next;
		last = current;
	}
}

void	kill_oponent(t_list **oponents, int row, int col)
{
	t_list		*last;
	t_list		*current;
	t_oponent	*oponent;

	current = *oponents;
	last = NULL;
	while (current)
	{
		oponent = (t_oponent*)current->content;
		if (oponent->x == col && oponent->y == row)
		{
			current = lstdel_relink(oponents, current, last);
			return;
		}
		else
			current = current->next;
		last = current;
	}
}

t_oponent	*new_oponent(int row, int col, char icon, char direction)
{
	t_oponent *oponent;

	oponent = malloc(sizeof(t_oponent));
	if (!oponent)
		return (NULL);
	oponent->x = col;
	oponent->y = row;
	oponent->direction = direction;
	oponent->icon = icon;
	return (oponent);
}

void	spawn_oponent(t_list **oponents)
{
	t_oponent	*oponent;
	t_list		*list;

	//oponent = new_oponent(((rand() % (END_LINE - START_LINE)) + START_LINE), END_COL, '&', 'l');
	oponent = new_oponent(1, 25, '&', 'l');
	if (!oponent)
		return ;
	list = ft_lstnew((void*)oponent);
	if (!list)
	{
		free(oponent);
		return ;
	}
	ft_lstadd_back(oponents, list);
}

void	render_oponents(t_list **oponents, t_list **projectiles, t_player *player)
{
	t_list		*last;
	t_list		*current;
	t_oponent	*oponent;

	if (!oponents || *oponents == NULL)
		return ;
	current = *oponents;
	last = NULL;
	while (current)
	{
		oponent = (t_oponent*)current->content;
		if (render_obj(oponent->y, oponent->x, oponent->icon) == - 1)
		{
			current = lstdel_relink(oponents, current, last);
			kill_projectile(projectiles, oponent->y, oponent->x);
			(player->score)++;
		}
		else
			current = current->next;
		last = current;
	}
}
