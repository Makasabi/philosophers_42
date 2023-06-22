/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 09:29:01 by mrony             #+#    #+#             */
/*   Updated: 2023/06/22 16:54:35 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_philo	*philos;
	
	if (ac < 5 || ac > 6)
		return(ft_putstr_fd(INVARG, 2), ft_putstr_fd(USAGE, 2), 1);
	philos = ft_parsing(ac, av);
	(void)philos;
}