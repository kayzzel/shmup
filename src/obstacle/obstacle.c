/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:45:38 by gabach            #+#    #+#             */
/*   Updated: 2025/11/30 14:39:18 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"
#include "objects.h"
#include "obstacle.h"

void	actualize_obstacles(t_list **obstacles, int counter)
{
	t_list		*last;
	t_list		*current;
	t_obstacle	*obstacle;

	if (counter % (200 - OBSTACLE_SPAWN_RATE) == 0)
		spawn_obstacle(obstacles);
	if (*obstacles == NULL || !obstacles || counter % 5 != 0)
		return ;
	current = *obstacles;
	last = NULL;
	while (current)
	{
		obstacle = (t_obstacle *)current->content;
		if (obj_move(&(obstacle->y), &(obstacle->x), (obstacle->direction)) == -1)
			current = lstdel_relink(obstacles, current, last);
		else
		{
			last = current;
			current = current->next;
		}
	}
}

void	kill_obstacle(t_list **obstacles, int row, int col)
{
	t_list			*last;
	t_list			*current;
	t_obstacle	*obstacle;

	current = *obstacles;
	last = NULL;
	while (current)
	{
		obstacle = (t_obstacle *)current->content;
		if (obstacle->x == col && obstacle->y == row)
		{
			current = lstdel_relink(obstacles, current, last);
			return ;
		}
		else
		{
			last = current;
			current = current->next;
		}
	}
}

t_obstacle	*new_obstacle(int row, int col, char icon, char direction)
{
	t_obstacle	*obstacle;

	obstacle = malloc(sizeof(t_obstacle));
	if (!obstacle)
		return (NULL);
	obstacle->x = col;
	obstacle->y = row;
	obstacle->direction = direction;
	obstacle->icon = icon;
	return (obstacle);
}

void	spawn_obstacle(t_list **obstacles)
{
	t_obstacle	*obstacle;
	t_list		*list;
	int	end_rows, end_cols;

	getmaxyx(game_win, end_rows, end_cols);

	obstacle = new_obstacle(((rand() % (end_rows - 2)) + 1),
			end_cols - 2, '%', 'l');
	if (!obstacle)
		return ;
	list = ft_lstnew((void *)obstacle);
	if (!list)
	{
		free(obstacle);
		return ;
	}
	ft_lstadd_back(obstacles, list);
}

void	render_obstacles(t_list **obstacles, t_list **projectiles)
{
	t_list			*last;
	t_list			*current;
	t_obstacle	*obstacle;

	if (!obstacles || *obstacles == NULL)
		return ;
	current = *obstacles;
	last = NULL;
	while (current)
	{
		obstacle = (t_obstacle *)current->content;
		if (render_obj(obstacle->y, obstacle->x, obstacle->icon, 6) == -1)
			kill_projectile(projectiles, obstacle->y, obstacle->x);
		last = current;
		current = current->next;
	}
}
