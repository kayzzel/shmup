/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_box.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 11:33:40 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/30 16:41:15 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"

void	render_box(WINDOW *win, int color)
{
	wattron(win, COLOR_PAIR(color));
	box(win, ACS_VLINE, ACS_HLINE);
	wattroff(win, COLOR_PAIR(color));
}
