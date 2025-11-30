/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:45:38 by gabach            #+#    #+#             */
/*   Updated: 2025/11/30 10:04:27 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "objects.h"
#include <stdlib.h>
#include "projectile.h"

void	actualize_projectiles(t_list **projectiles, int counter)
{
	t_list		*last;
	t_list		*current;
	t_projectile	*projectile;

	if (*projectiles == NULL || !projectiles || counter % 2 == 0)
		return ;
	current = *projectiles;
	last = NULL;
	projectile = (t_projectile*)current->content;
	while (current)
	{
		projectile = (t_projectile*)current->content;
		if (obj_move(&(projectile->y), &(projectile->x), (projectile->direction)) == -1)
			current = lstdel_relink(projectiles, current, last);
		else
			current = current->next;
		last = current;
	}
}

void	kill_projectile(t_list **projectiles, int row, int col)
{
	t_list		*last;
	t_list		*current;
	t_projectile	*projectile;

	current = *projectiles;
	last = NULL;
	while (current)
	{
		projectile = (t_projectile*)current->content;
		if (projectile->x == col && projectile->y == row)
		{
			current = lstdel_relink(projectiles, current, last);
			return;
		}
		else
			current = current->next;
		last = current;
	}
}

t_projectile	*new_projectile(int row, int col, char icon, char direction)
{
	t_projectile *projectile;

	projectile = malloc(sizeof(t_projectile));
	if (!projectile)
		return (NULL);
	projectile->x = col;
	projectile->y = row;
	projectile->direction = direction;
	projectile->icon = icon;
	return (projectile);
}

void	throw_projectile(int row, int column, char icon, char direction, t_list **projectiles)
{
	t_projectile	*projectile;
	t_list		*list;

	projectile = new_projectile(row, column, icon, direction);
	if (!projectile)
		return ;
	list = ft_lstnew((void*)projectile);
	if (!list)
	{
		free(projectile);
		return ;
	}
	ft_lstadd_back(projectiles, list);
}

void	render_projectiles(t_list **projectiles)
{
	t_list		*last;
	t_list		*current;
	t_projectile	*projectile;

	if (!projectiles || *projectiles == NULL)
		return ;
	current = *projectiles;
	last = NULL;
	while (current)
	{
		projectile = (t_projectile*)current->content;
		if (render_obj(projectile->y, projectile->x, projectile->icon) == - 1)
			current = lstdel_relink(projectiles, current, last);
		else
			current = current->next;
		last = current;
	}
}
