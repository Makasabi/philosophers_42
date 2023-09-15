/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 09:29:01 by mrony             #+#    #+#             */
/*   Updated: 2023/09/01 16:12:23 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	ft_finish_prog(t_info *info)
{
	free(info->philos);
	sem_close(info->forks);
	sem_close(info->check);
	sem_close(info->time);
	sem_close(info->milkshake);
	free(info);
	exit(EXIT_SUCCESS);
}

void	ft_end_philos(t_info *info)
{
	int	i;
	int	status;

	i = -1;
	while (++i < info->n_philos)
	{
		waitpid(info->philos[i].pid, &status, 0);
		i++;
	}
	ft_finish_prog(info);
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
