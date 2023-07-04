/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:14:08 by mrony             #+#    #+#             */
/*   Updated: 2023/07/04 18:35:58 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_pthread_err(t_info *info, char *err)
{
	free(info->philos);
	free(info->forks);
	free(info);
	ft_putstr_fd(err, 2);
	exit(EXIT_FAILURE);
}

void	*ft_exec(void *data)
{
	t_info *info;
	t_philo *philo;

	philo = (t_philo *)data;
	info = philo->info;
	if (philo->id % 2)
		ft_sleep(info, 200);
	while (info->dead == ALIVE)
	{
		ft_philo_eats(info, philo);
		philo->meals++;
		ft_philo_sleeps(info, philo);
		ft_philo_thinks(info, philo);
	}
	return (NULL);
}

void	ft_check_pulse(t_info *info, t_philo *philos)
{
	int i;

	i = 0;
	while (info->dead == ALIVE)
	{
		pthread_mutex_lock(&info->timecheck);
		if((ft_timestamp(info) - philos[i].last_meal) >= info->die)
		{
			pthread_mutex_unlock(&info->timecheck);
			break;
		}
		pthread_mutex_unlock(&info->timecheck);
		i++;
		if (i == info->n_philos - 1)
			i = 0;
	}
	ft_print(info, i + 1, DIED);
	pthread_mutex_lock(&info->timecheck);
	info->dead = DEAD;
	pthread_mutex_unlock(&info->timecheck);
}

void	ft_launch_philos(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->n_philos)
		if (pthread_mutex_init(&info->forks[i],NULL) != 0)
			ft_pthread_err(info, INIMTX);
	i = -1;
	while (++i < info->n_philos)
		if(pthread_create(&info->philos[i].t_id, \
		NULL, ft_exec, &info->philos[i]) != 0)
			ft_pthread_err(info, INITRD);
	while (info->dead == ALIVE)
		ft_check_pulse(info, info->philos);
}

void	ft_end_philos(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->n_philos)
		if(pthread_join(info->philos[i].t_id,NULL) != 0)
			ft_pthread_err(info, ERRJOI);
	i = -1;
	while (++i < info->n_philos)
		if (pthread_mutex_destroy(&info->forks[i]) != 0)
			ft_pthread_err(info, DESMTX);
	pthread_mutex_destroy(&info->get_forks);
	pthread_mutex_destroy(&info->print);
	pthread_mutex_destroy(&info->timecheck);
}