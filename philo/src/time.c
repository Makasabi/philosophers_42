/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:13:06 by mrony             #+#    #+#             */
/*   Updated: 2023/08/31 15:27:23 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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
		pthread_mutex_lock(&info->check);
		if (info->dead == DEAD)
		{
			pthread_mutex_unlock(&info->check);
			break ;
		}
		pthread_mutex_unlock(&info->check);
		if (ft_timestamp(info) - start >= sleep)
			break ;
		usleep(1000);
	}
}
