/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_does.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:38:10 by mrony             #+#    #+#             */
/*   Updated: 2023/08/31 15:25:13 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_philo_eats(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&info->forks[philo->l_fork]);
	ft_print(info, philo->id, FORK);
	pthread_mutex_lock(&info->forks[philo->r_fork]);
	ft_print(info, philo->id, FORK);
	pthread_mutex_lock(&info->time);
	philo->last_meal = ft_timestamp(info);
	pthread_mutex_unlock(&info->time);
	philo->meals++;
	pthread_mutex_lock(&info->milkshake);
	if (philo->meals == info->repeat)
		info->dessert++;
	pthread_mutex_unlock(&info->milkshake);
	ft_print(info, philo->id, EATS);
	ft_sleep(info, info->eat);
	pthread_mutex_unlock(&info->forks[philo->r_fork]);
	pthread_mutex_unlock(&info->forks[philo->l_fork]);
}

void	ft_philo_sleeps(t_info *info, t_philo *philo)
{
	ft_print(info, philo->id, SLPS);
	ft_sleep(info, info->sleep);
}

void	ft_philo_thinks(t_info *info, t_philo *philo)
{
	ft_print(info, philo->id, THKS);
	if (info->think > 15)
		ft_sleep(info, info->think);
}

void	ft_print(t_info *info, int p_id, char *str)
{
	pthread_mutex_lock(&info->check);
	if (info->dead == ALIVE)
	{
		printf("%lld %d %s\n", ft_timestamp(info), p_id, str);
	}
	pthread_mutex_unlock(&info->check);
}
