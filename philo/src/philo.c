/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 09:29:01 by mrony             #+#    #+#             */
/*   Updated: 2023/06/23 17:53:51 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_init_error(char *str)
{
	ft_putstr_fd(MALERR, 2);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	ft_test(t_philo *philos)
{
	struct	timeval tv;
/* 	
	1. Setup a table of thread ID = the size is based on the nu of philos (malloc)
	2. Setup a table of thread ID = The size is based on the nu of philos (malloc)
	3. for both tables : ad them to the linked list of mallocs (bin)
	4. add links to each tab to the Philos struc;
*/
	(void)philos;
	while(1)
	{
		gettimeofday(&tv, NULL);
		printf("%ld\n", tv.tv_usec/10);
	}

}

int	main(int ac, char **av)
{
	t_philo	*philos;
	
	if (ac < 5 || ac > 6)
		return(ft_putstr_fd(INVARG, 2), ft_putstr_fd(USAGE, 2), 1);
	philos = ft_parsing(ac, av);
	ft_test(philos);
	(void)philos;
}