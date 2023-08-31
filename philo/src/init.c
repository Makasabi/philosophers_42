/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makasabi <makasabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:01:29 by mrony             #+#    #+#             */
/*   Updated: 2023/08/30 16:32:17 by makasabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_checks(char *arg)
{
	long	tmp;

	tmp = 0;
	if (arg[0] == '\0')
		ft_parsing_error(EMPTY);
	if (ft_is_digit(arg) == 1)
		ft_parsing_error(DIGIT);
	if (ft_strlen(arg) > 11)
		ft_parsing_error(INTERR);
	tmp = ft_atol(arg);
	if (tmp < 0 || tmp > 2147483647)
		ft_parsing_error(INTERR);
	return ((int)tmp);
}

t_info	*ft_parsing(int argc, char **args)
{
	t_info	*info;

	info = ft_calloc(1, sizeof(t_info));
	if (!info)
		ft_malloc_err(info, 0);
	info->n_philos = ft_checks(args[1]);
	info->die = ft_checks(args[2]);
	info->eat = ft_checks(args[3]);
	info->sleep = ft_checks(args[4]);
	info->think = info->die - info->eat - info->sleep;
	if (argc == 6)
		info->repeat = ft_checks(args[5]);
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
		philos[i].l_fork = i;
		philos[i].r_fork = (i + 1) % info->n_philos;
		if (i == info->n_philos - 1)
		{
			philos[i].r_fork = i;
			philos[i].l_fork = (i + 1) % info->n_philos;
		}
		i++;
	}
}

void	ft_init(t_info *info)
{
	t_philo			*philos;
	pthread_mutex_t	*forks;

	info->start = ft_timestamp(info);
	philos = ft_calloc(info->n_philos, sizeof(t_philo));
	if (!philos)
		ft_malloc_err(info, 1);
	info->dead = ALIVE;
	ft_init_each_philo(info, philos);
	info->philos = philos;
	forks = ft_calloc(info->n_philos, sizeof(pthread_mutex_t));
	if (!forks)
		ft_malloc_err(info, 2);
	info->forks = forks;
	pthread_mutex_init(&info->check, NULL);
	pthread_mutex_init(&info->time, NULL);
	pthread_mutex_init(&info->milkshake, NULL);
}
