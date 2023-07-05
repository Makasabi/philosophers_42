/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 09:29:01 by mrony             #+#    #+#             */
/*   Updated: 2023/07/05 16:24:19 by mrony            ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_info	*info;

	if (ac < 5 || ac > 6)
		return(ft_putstr_fd(INVARG, 2), ft_putstr_fd(USAGE, 2), 1);
	info = ft_parsing(ac, av);
	ft_init(info);
	ft_launch_philos(info);
	ft_end_philos(info);
	ft_finish_prog(info);
	return (0);
}