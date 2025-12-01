/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:44:24 by gabach            #+#    #+#             */
/*   Updated: 2025/11/30 10:02:39 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTILE_H
# define PROJECTILE_H

// INCLUDES

#include "linked_list.h"

// STRUCTS

typedef struct s_projectile
{
	int		x;
	int		y;
	char	icon;
	char	direction;
	int		color;
}				t_projectile;

// FUNCS

void	throw_projectile(int row, int column, char icon, char direction, int color, t_list **projectiles);
void	actualize_projectiles(t_list **projectiles, int counter);
void	kill_projectile(t_list **projectiles, int row, int col);
void	render_projectiles(t_list **projectiles);

#endif
