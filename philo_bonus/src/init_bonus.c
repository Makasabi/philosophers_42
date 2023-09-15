/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:01:29 by mrony             #+#    #+#             */
/*   Updated: 2023/09/01 16:24:58 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

int	ft_checks(char *arg, t_info *info)
{
	long	tmp;

	tmp = 0;
	if (arg[0] == '\0')
		ft_parsing_error(INVARG, EMPTY, info);
	if (ft_is_digit(arg) == 1)
		ft_parsing_error(INVARG, DIGIT, info);
	if (ft_strlen(arg) > 11)
		ft_parsing_error(INVARG, INTERR, info);
	tmp = ft_atol(arg);
	if (tmp < 0 || tmp > 2147483647)
		ft_parsing_error(INVARG, INTERR, info);
	return ((int)tmp);
}

t_info	*ft_parsing(int argc, char **args)
{
	t_info	*info;

	info = ft_calloc(1, sizeof(t_info));
	if (!info)
		ft_malloc_err(info, 0);
	info->n_philos = ft_checks(args[1], info);
	if (info->n_philos > 200)
		ft_parsing_error(INVARG, PHILIM, info);
	info->die = ft_checks(args[2], info);
	if (info->die < 60)
		ft_parsing_error(INVARG, DIEVAL, info);
	info->eat = ft_checks(args[3], info);
	if (info->eat < 60)
		ft_parsing_error(INVARG, EATVAL, info);
	info->sleep = ft_checks(args[4], info);
	if (info->sleep < 60)
		ft_parsing_error(INVARG, SLPVAL, info);
	info->think = (info->die - info->eat - info->sleep) * 2 / 3;
	if (argc == 6)
		info->repeat = ft_checks(args[5], info);
	return (info);
}

void	ft_init_each_philo(t_info *info, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < info->n_philos)
	{
		philos[i].id = i + 1;
		philos[i].info = info;
		// philos[i].l_fork = i;
		// philos[i].r_fork = (i + 1) % info->n_philos;
		// if (i == info->n_philos - 1)
		// {
		// 	philos[i].r_fork = i;
		// 	philos[i].l_fork = (i + 1) % info->n_philos;
		// }
		i++;
	}
}

void	ft_init(t_info *info)
{
	t_philo	*philos;
	sem_t	*forks;
	// pthread_mutex_t	*forks;

	info->start = ft_timestamp(info);
	philos = ft_calloc(info->n_philos, sizeof(t_philo));
	if (!philos)
		ft_malloc_err(info, 1);
	info->dead = ALIVE;
	ft_init_each_philo(info, philos);
	info->philos = philos;
	forks = sem_open("forks", O_CREAT, O_RDWR, info->n_philos);
	// forks = ft_calloc(info->n_philos, sizeof(pthread_mutex_t));
	// if (!forks)
	// 	ft_malloc_err(info, 2);
	info->forks = forks;
	info->check = sem_open("check", O_CREAT, O_RDWR, 1);
	info->time = sem_open("time", O_CREAT, O_RDWR, 1);
	info->milkshake = sem_open("milkshake", O_CREAT, O_RDWR, 1);
	// pthread_mutex_init(&info->check, NULL);
	// pthread_mutex_init(&info->time, NULL);
	// pthread_mutex_init(&info->milkshake, NULL);
}
