/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:27:37 by gabach            #+#    #+#             */
/*   Updated: 2025/11/29 17:45:05 by gabach           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

// FUNCS

int	obj_move(int *row, int *col, char direction);
int	render_obj(int row, int col, char icon, int color);

#endif
