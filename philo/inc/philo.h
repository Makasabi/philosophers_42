/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 09:24:12 by mrony             #+#    #+#             */
/*   Updated: 2023/06/23 17:57:21 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// INClUDES //

# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

// MACRO //

# define INVARG "\033[1;35m🦖 Invalid Argument(s) 🦖\n\033[1;0m"
# define USAGE "\033[0;34mUsage: ./philo <number_of_philosophers> \
<time_to_die> <time_to_eat> <time_to_sleep> \
[<number_of_time_each_philosopher_must_eat>]\n\033[1;0m"
# define EMPTY "\033[0;33mAt least one argument is empty.\033[0m\n"
# define DIGIT "\033[0;33mArgument is not a digit.\033[0m\n""" 
# define INTERR "\033[0;33mArgument does't fit into an int.\033[0m\n"

# define MALERR "\033[1;35m🦖 Malloc failled 🦖\n\033[1;0m"
# define PTHERR "\033[0;33mPthead_t table init failled\033[0m\n"
# define FRKERR "\033[0;33mFork table init failled\033[0m\n"

// STRUCTS //

typedef struct s_philo
{
	int			philos;
	int			die;
	int			eat;
	int			sleep;
	int			repeat;
	pthread_t	**philo_ids;
	int			*forks;
}	t_philo;

typedef struct s_bin
{
	void			*rubbish;
	struct s_bin	*next;
}	t_bin;

// FUNCTIONS //

/* parsing.c */
t_philo	*ft_parsing(int argc, char **args);

/* utils.c */
void	ft_putstr_fd(char *str, int fd);
int		ft_is_digit(char *str);
int		ft_strlen(char *str);
long	ft_atol(const char *str);

/* rubbish.c */
t_bin **ft_rubbish();
t_bin	*ft_binnew(void *content);
void	ft_binadd_front(t_bin **bin, t_bin *new);
void	ft_bindelone(t_bin *bin, void (*del)(void*));
void	ft_binclear(t_bin **bin, void (*del)(void*));
void	*ft_malloc(int size);

#endif