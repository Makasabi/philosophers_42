/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_is_alone_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:33:04 by mrony             #+#    #+#             */
/*   Updated: 2023/09/01 16:20:45 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	*ft_philo_is_alone(void *data)
{
	t_info	*info;
	t_philo	*philo;

	philo = (t_philo *)data;
	info = philo->info;
	sem_wait(info->forks);
	ft_print(info, philo->id, FORK);
	ft_sleep(info, info->die);
	ft_print(info, philo->id, DIED);
	sem_post(info->forks);
	return (NULL);
}

void	ft_launch_one_philo(t_info *info)
{
	int	status;

	info->philos[0].pid = fork();
	if ((info->philos[0].pid <= 0))
		ft_fork_err(info, FRKERR);
	else if (info->philos[0].pid == 0)
		ft_philo_is_alone(&info->philos[0]);
	else if ((info->philos[0].pid > 0))
		waitpid(info->philos[0].pid, &status, 0);
	return ;
}
