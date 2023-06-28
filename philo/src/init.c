/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:01:29 by mrony             #+#    #+#             */
/*   Updated: 2023/06/28 16:14:47 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void ft_malloc_err(t_info *info, int stage)
{
	int i;

	i = stage;
	ft_putstr_fd(MALERR, 2);
	while (i > 0)
	{
		if (i == 1)
			free(info);
		if (i == 2)
			free(info->philos);
		i--;
	}
	if (stage == 0)
		ft_putstr_fd(INFERR, 2);
	else if (stage == 1)
		ft_putstr_fd(PTHERR, 2);
	else if (stage == 2)
		ft_putstr_fd(FRKERR, 2);
	exit(EXIT_FAILURE);
}

void ft_init(t_info *info)
{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	info->start = ft_gettime();
	philos = ft_calloc(info->n_philos, sizeof(t_philo));
	if (!philos)
		ft_malloc_err(info, 1);
	while (i < info->n_philos)
	{
		philos[i].id = i + 1;
		philos[i].info = info;
		philos[i].l_fork = i;
		philos[i].r_fork = i + 1 % info->n_philos;
		i++;
	}
	info->philos = philos;
	forks = ft_calloc(info->n_philos, sizeof(pthread_mutex_t));
	if (!forks)
		ft_malloc_err(info, 2);
	info->forks = forks;
}
