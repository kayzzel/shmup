/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:27:20 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/30 15:45:47 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"
#include "ui.h"
#include <sys/time.h>

long	time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	limit_fps(int max_fps)
{
	const long	target_frame_time = 1000000 / max_fps;
	static long	frame_start = 0;
	long		now;
	long		elapsed;
	long		sleep_time;

	now = time_in_ms();
	if (frame_start == 0)
		frame_start = now;
	elapsed = (now - frame_start) * 1000;
	sleep_time = target_frame_time - elapsed;
	if (sleep_time > 0)
		usleep(sleep_time);
	frame_start = time_in_ms();
}

void	print_fps(int ch)
{
	static long	frame_count = 0;
	static long	fps_start = 0;
	static int	fps = 0;
	static int	fps_visible = 1;
	long		now;

	now = time_in_ms();
	if (fps_start == 0)
		fps_start = now;
	if (ch == KEY_F(3))
		fps_visible = !fps_visible;
	if (fps_visible)
	{
		dprintf(2, "coucou\n");
		wattron(stats_win, COLOR_PAIR(2));
		mvwprintw(stats_win, 0, 1, "FPS: %3d", fps);
		wattroff(stats_win, COLOR_PAIR(2));
		wrefresh(stats_win);
	}
	frame_count++;
	if (now - fps_start >= 1000)
	{
		fps = frame_count;
		frame_count = 0;
		fps_start = now;
	}
}
