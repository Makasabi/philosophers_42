/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:14:08 by mrony             #+#    #+#             */
/*   Updated: 2023/09/01 16:17:20 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

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
		sem_wait(info->check);
		if (info->dead == DEAD)
		{
			sem_post(info->check);
			break ;
		}
		sem_post(info->check);
		ft_philo_eats(info, philo);
		ft_philo_sleeps(info, philo);
		usleep(200);
		ft_philo_thinks(info, philo);
		i++;
	}
	return (NULL);
}

void	ft_check_pulse_2(t_info *info, t_philo *philos, int *i, bool *check)
{
	while (info->dead == ALIVE)
	{
		sem_wait(info->time);
		if ((ft_timestamp(info) - philos[*i].last_meal) >= info->die)
		{
			sem_post(info->time);
			break ;
		}
		sem_post(info->time);
		sem_wait(info->milkshake);
		if (info->dessert == info->n_philos)
		{
			sem_post(info->milkshake);
			*check = 1;
			break ;
		}
		sem_post(info->milkshake);
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
	sem_wait(info->check);
	info->dead = DEAD;
	sem_post(info->check);
}

void	ft_launch_philos(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->n_philos)
	{
		info->philos[i].pid = fork();
		if (info->philos[i].pid == -1)
			ft_fork_err(info, FRKERR);
		else if (info->philos[i].pid == 0)
			ft_exec(&info->philos[i]);
		else if (info->philos[i].pid > 0)
			i++;
	}
	while (1)
	{
		sem_wait(info->check);
		if (info->dead == DEAD)
		{
			sem_post(info->check);
			break ;
		}
		sem_post(info->check);
		ft_check_pulse(info, info->philos);
		usleep(500);
	}
}
