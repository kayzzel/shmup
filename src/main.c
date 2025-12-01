/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:46:08 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/30 23:02:56 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "shmup.h"

int	main(void)
{
	t_game	game;

	init(&game);
	menu();
	game_loop(&game);
	finish(game);
	endwin();
	return (0);
}
