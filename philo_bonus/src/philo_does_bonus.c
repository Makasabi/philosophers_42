/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_does_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:38:10 by mrony             #+#    #+#             */
/*   Updated: 2023/09/01 16:14:47 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	ft_philo_eats(t_info *info, t_philo *philo)
{
	sem_wait(info->forks);
	sem_wait(info->forks);
	sem_wait(info->time);
	philo->last_meal = ft_timestamp(info);
	sem_post(info->time);
	philo->meals++;
	sem_wait(info->milkshake);
	if (philo->meals == info->repeat)
		info->dessert++;
	sem_post(info->milkshake);
	ft_print(info, philo->id, EATS);
	ft_sleep(info, info->eat);
	sem_post(info->forks);
	sem_post(info->forks);
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
	sem_wait(info->check);
	if (info->dead == ALIVE)
	{
		printf("%lld %d %s\n", ft_timestamp(info), p_id, str);
	}
	sem_post(info->check);
}
