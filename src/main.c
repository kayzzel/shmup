/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:46:08 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/30 19:43:09 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"
#include "player.h"

void start(void)
{

}

int	main(void)
{
	t_game	game;

	init();
	start();
	game_loop(&game);
	finish(game);
	endwin();
	return (0);
}
