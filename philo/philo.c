/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 09:29:01 by mrony             #+#    #+#             */
/*   Updated: 2023/06/21 17:20:08 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

t_philo	*ft_parcing(int ac, char **args)
{
	t_philo philos;

	1. check if all digits
	2. less than 11 char
	3. atol
	4. fits in int min / int max
	5. cast as unsigned int
	6. store in struct.
	return (&philos);
}

int	main(int ac, char **av)
{
	t_philo	*philos;
	if (ac < 5 || ac > 6)
		return(ft_putstr_fd(INVARG, 2), ft_putstr_fd(USAGE, 2), 1);
	philos = ft_parsing(ac, av);
	if (!philos)
		return(ft_putstr_fd(INVARG, 2), 1);
}