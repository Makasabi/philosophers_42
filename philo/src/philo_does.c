/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_does.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:38:10 by mrony             #+#    #+#             */
/*   Updated: 2023/07/04 17:53:25 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_philo_eats(t_info *info, t_philo *philo)
{
	if (info->dead == ALIVE)
	{
		pthread_mutex_lock(&info->get_forks);
		pthread_mutex_lock(&info->forks[philo->l_fork]);
		ft_print(info, philo->id, FORK);
		pthread_mutex_lock(&info->forks[philo->r_fork]);
		pthread_mutex_unlock(&info->get_forks);
		ft_print(info, philo->id, FORK);
		pthread_mutex_lock(&info->timecheck);
		philo->last_meal = ft_timestamp(info);
		pthread_mutex_unlock(&info->timecheck);
		ft_print(info, philo->id, EATS);
		ft_sleep(info, info->eat);
		pthread_mutex_unlock(&info->forks[philo->l_fork]);
		pthread_mutex_unlock(&info->forks[philo->r_fork]);
	}
}

void	ft_philo_sleeps(t_info *info, t_philo *philo)
{
	if (info->dead == ALIVE)
	{
		ft_print(info, philo->id, SLPS);
		ft_sleep(info, info->sleep);
	}
}

void	ft_philo_thinks(t_info *info, t_philo *philo)
{
	if (info->dead == ALIVE)
	{
		ft_print(info, philo->id, THKS);
	}
}

void	ft_print(t_info *info, int p_id, char *str)
{
	pthread_mutex_lock(&info->print);
	if (info->dead == ALIVE)
	{
		printf("%lld %d %s\n", ft_timestamp(info), p_id, str);
	}
	pthread_mutex_unlock(&info->print);
}