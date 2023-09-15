/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:13:06 by mrony             #+#    #+#             */
/*   Updated: 2023/09/01 16:05:03 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

long long int	ft_get_starttime(void)
{
	struct timeval	start;
	long long int	time;

	gettimeofday(&start, NULL);
	time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return (time);
}

long long int	ft_timestamp(t_info *info)
{
	struct timeval	now;
	long long int	timestamp;

	gettimeofday(&now, NULL);
	timestamp = (now.tv_sec * 1000) + (now.tv_usec / 1000) - info->start;
	return (timestamp);
}

void	ft_sleep(t_info *info, long long sleep)
{
	long long int	start;

	start = ft_timestamp(info);
	while (1)
	{
		sem_wait(info->check);
		if (info->dead == DEAD)
		{
			sem_post(info->check);
			break ;
		}
		sem_post(info->check);
		if (ft_timestamp(info) - start >= sleep)
			break ;
		usleep(1000);
	}
}
