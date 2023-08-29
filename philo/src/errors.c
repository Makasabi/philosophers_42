/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:05:14 by mrony             #+#    #+#             */
/*   Updated: 2023/08/29 12:19:54 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_parsing_error(char *str)
{
	ft_putstr_fd(INVARG, 2);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	ft_malloc_err(t_info *info, int stage)
{
	int	i;

	i = stage;
	ft_putstr_fd(MALERR, 2);
	while (i > 0)
	{
		if (i == 1)
			free(info);
		if (i == 2)
			free(info->philos);
		i--;
	}
	if (stage == 0)
		ft_putstr_fd(INFERR, 2);
	else if (stage == 1)
		ft_putstr_fd(PTHERR, 2);
	else if (stage == 2)
		ft_putstr_fd(FRKERR, 2);
	exit(EXIT_FAILURE);
}
