/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 09:29:01 by mrony             #+#    #+#             */
/*   Updated: 2023/07/07 16:55:26 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_finish_prog(t_info *info)
{
	free(info->philos);
	free(info->forks);
	free(info);
	exit(EXIT_SUCCESS);
}

void	ft_end_philos(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_philos)
	{
		if (pthread_join(info->philos[i].t_id, NULL) != 0)
			ft_pthread_err(info, ERRJOI);
		i++;
	}
	i = -1;
	while (++i < info->n_philos)
		if (pthread_mutex_destroy(&info->forks[i]) != 0)
			ft_pthread_err(info, DESMTX);
	pthread_mutex_destroy(&info->check);
	pthread_mutex_destroy(&info->milkshake);
}

int	main(int ac, char **av)
{
	t_info	*info;

	if (ac < 5 || ac > 6)
		return (ft_putstr_fd(INVARG, 2), ft_putstr_fd(USAGE, 2), 1);
	info = ft_parsing(ac, av);
	ft_init(info);
	if (info->n_philos == 1)
		ft_launch_one_philo(info);
	else
		ft_launch_philos(info);
	ft_end_philos(info);
	ft_finish_prog(info);
	return (0);
}
