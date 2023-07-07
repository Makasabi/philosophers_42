/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_alone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:33:04 by mrony             #+#    #+#             */
/*   Updated: 2023/07/07 17:00:11 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*ft_philo_is_alone(void *data)
{
	t_info	*info;
	t_philo	*philo;

	philo = (t_philo *)data;
	info = philo->info;
	pthread_mutex_lock(&info->forks[philo->l_fork]);
	ft_print(info, philo->id, FORK);
	ft_sleep(info, info->die);
	ft_print(info, philo->id, DIED);
	pthread_mutex_unlock(&info->forks[philo->l_fork]);
	return (NULL);
}

void	ft_launch_one_philo(t_info *info)
{
	if (pthread_mutex_init(&info->forks[0], NULL) != 0)
		ft_pthread_err(info, INIMTX);
	if (pthread_create(&info->philos[0].t_id, \
	NULL, ft_philo_is_alone, &info->philos[0]) != 0)
		ft_pthread_err(info, INITRD);
	return ;
}
