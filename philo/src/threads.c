/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:14:08 by mrony             #+#    #+#             */
/*   Updated: 2023/06/28 16:39:10 by mrony            ###   ########.fr       */
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
	philo->last_meal = ft_gettime;
	if ()

	return ((void *)data);
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
		if(pthread_create(&info->philos[i].t_id, \
			NULL, ft_exec, &info->philos[i]) != 0)
			ft_pthread_err(info, INITRD);
	i = -1;
	while (++i < info->n_philos)
		if(pthread_join(info->philos[i].t_id, NULL) != 0)
			ft_pthread_err(info, ERRJOI);
	i = -1;
	while (++i < info->n_philos)
		if (pthread_mutex_destroy(&info->forks[i]) != 0)
			ft_pthread_err(info, DESMTX);
	return ;
}