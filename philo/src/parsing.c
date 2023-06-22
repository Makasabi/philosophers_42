/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:14:42 by mrony             #+#    #+#             */
/*   Updated: 2023/06/22 18:02:39 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_parsing_error(char *str)
{
	ft_putstr_fd(INVARG, 2);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}


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

t_philo	*ft_parsing(int argc, char **args)
{
	t_philo	philos;
	t_philo *ptr;

	philos.philos = ft_checks(args[1]);
	philos.die = ft_checks(args[2]);
	philos.eat = ft_checks(args[3]);
	philos.sleep = ft_checks(args[4]);
	if (argc == 6)
		philos.repeat = ft_checks(args[5]);
	ptr = &philos;
	return (ptr);
}