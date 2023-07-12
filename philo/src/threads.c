/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:14:08 by mrony             #+#    #+#             */
/*   Updated: 2023/07/11 16:49:38 by mrony            ###   ########.fr       */
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
	t_info	*info;
	t_philo	*philo;
	int		i;

	philo = (t_philo *)data;
	info = philo->info;
	i = 0;
	while (1)
	{
		pthread_mutex_lock(&info->check);
		if (info->dead == DEAD)
		{
			pthread_mutex_unlock(&info->check);
			break ;
		}
		pthread_mutex_unlock(&info->check);
		ft_philo_eats(info, philo, &i);
		ft_philo_sleeps(info, philo);
		ft_philo_thinks(info, philo);
		i++;
	}
	return (NULL);
}

void	ft_check_pulse_2(t_info *info, t_philo *philos, int *i, bool *check)
{
	while (info->dead == ALIVE)
	{
		pthread_mutex_lock(&info->time);
		if ((ft_timestamp(info) - philos[*i].last_meal) >= info->die)
		{
			pthread_mutex_unlock(&info->time);
			break ;
		}
		pthread_mutex_unlock(&info->time);
		pthread_mutex_lock(&info->milkshake);
		if (info->dessert == info->n_philos)
		{
			pthread_mutex_unlock(&info->milkshake);
			*check = 1;
			break ;
		}
		pthread_mutex_unlock(&info->milkshake);
		*i += 1;
		if (*i == info->n_philos - 1 || info->n_philos == 1)
			*i = 0;
	}
}

void	ft_check_pulse(t_info *info, t_philo *philos)
{
	int		i;
	bool	check;

	i = 0;
	check = 0;
	ft_check_pulse_2(info, philos, &i, &check);
	if (check == 0)
		ft_print(info, i + 1, DIED);
	else
		printf(DONE, info->repeat);
	pthread_mutex_lock(&info->check);
	info->dead = DEAD;
	pthread_mutex_unlock(&info->check);
}

void	ft_launch_philos(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->n_philos)
		if (pthread_mutex_init(&info->forks[i], NULL) != 0)
			ft_pthread_err(info, INIMTX);
	i = -1;
	while (++i < info->n_philos)
		if (pthread_create(&info->philos[i].t_id, \
		NULL, ft_exec, &info->philos[i]) != 0)
			ft_pthread_err(info, INITRD);
	while (1)
	{
		pthread_mutex_lock(&info->check);
		if (info->dead == DEAD)
		{
			pthread_mutex_unlock(&info->check);
			break ;
		}
		pthread_mutex_unlock(&info->check);
		ft_check_pulse(info, info->philos);
	}
}
