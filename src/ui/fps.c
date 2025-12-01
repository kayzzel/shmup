/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:27:20 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/30 17:11:47 by enchevri         ###   ########lyon.fr   */
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
