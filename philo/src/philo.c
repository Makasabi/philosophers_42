/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 09:29:01 by mrony             #+#    #+#             */
/*   Updated: 2023/06/27 15:42:21 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_init_error(char *str)
{
	ft_putstr_fd(MALERR, 2);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	ft_malloc_err(t_info *info, int stage)
{
	while (stage > 0)
	{
		if(stage == 1)
			free(info->philos);
		stage--;
	}
	ft_putstr_fd(MALERR, 2);
	exit(EXIT_FAILURE);
}

void	ft_finish_prog(t_info *info)
{
	free(info->philos);
	free(info->forks);
	exit(EXIT_SUCCESS);
}

void	ft_test(t_info *info)
{
	/*
	struct	timeval tv;
	while(1)
	{
		gettimeofday(&tv, NULL);
		printf("%ld\n", tv.tv_usec/10);
	}
	*/
	t_philo			*philos;
	pthread_mutex_t	*forks;
	
	philos = ft_calloc(info->n_philos, sizeof(t_philo));
	if (!philos)
		ft_malloc_err(info, 0);
	info->philos = philos;
	forks = ft_calloc(info->n_philos, sizeof(pthread_mutex_t));
	if(!forks)
		ft_malloc_err(info, 1);
	info->forks = forks;
	
	ft_finish_prog(info);
}

int	main(int ac, char **av)
{
	t_info	info;
	
	if (ac < 5 || ac > 6)
		return(ft_putstr_fd(INVARG, 2), ft_putstr_fd(USAGE, 2), 1);
	info = ft_parsing(ac, av);
	/* 
		1. init all necessary data in info struct.
		2. init all necessary data in each philo strct.
		3. 
		
		
	*/
	ft_test(&info);
}