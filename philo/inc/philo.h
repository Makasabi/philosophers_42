/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 09:24:12 by mrony             #+#    #+#             */
/*   Updated: 2023/07/04 14:40:36 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

////////////////////// INClUDES //////////////////////

# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdint.h>
# include <errno.h>
# include <stdbool.h>

////////////////////// MACRO //////////////////////

# define TRUE 1
# define FALSE 0

# define INVARG "\033[1;35m🦖 Invalid Argument(s) 🦖\n\033[1;0m"
# define USAGE "\033[0;34mUsage: ./philo <number_of_philosophers> \
<time_to_die> <time_to_eat> <time_to_sleep> \
[<number_of_time_each_philosopher_must_eat>]\n\033[1;0m"
# define EMPTY "\033[0;33mAt least one argument is empty.\033[0m\n"
# define DIGIT "\033[0;33mArgument is not a digit.\033[0m\n"""
# define INTERR "\033[0;33mArgument does't fit into an int.\033[0m\n"

# define MALERR "\033[1;35m🦖 Malloc failled 🦖\n\033[1;0m"
# define INFERR "\033[0;33mInfo struct init failled.\033[0m\n"
# define PTHERR "\033[0;33mPhilo struct table init failled.\033[0m\n"
# define FRKERR "\033[0;33mFork mutex table init failled\033[0m\n"

# define INIMTX "\033[1;35m🦖 Thread failled 🦖\n\033[1;0m\
				\033[0;33mError initiating mutex\033[0m\n"
# define INITRD "\033[1;35m🦖 Thread failled 🦖\n\033[1;0m\
				\033[0;33mError creating thread\033[0m\n"
# define ERRJOI "\033[1;35m🦖 Thread failled 🦖\n\033[1;0m\
				\033[0;33mError joining thread\033[0m\n"
# define DESMTX "\033[1;35m🦖 Thread failled 🦖\n\033[1;0m\
				\033[0;33mError destroying mutex\033[0m\n"

# define FORK "has taken a fork"
# define EATS "is eating"
# define SLPS "is sleeping"
# define THKS "is thinking"
# define DIED "died"
////////////////////// STRUCTS //////////////////////

typedef struct s_philo	t_philo;
typedef struct s_info	t_info;

typedef struct s_philo
{
	pthread_t	t_id;
	int			id;		//init
	int			l_fork;	//init
	int			r_fork;	//init
	int			meals;	//init 0
	long long int	last_meal;	//init
	t_info		*info;	//init
}	t_philo;

typedef struct s_info
{
	int				n_philos;	//parsing
	int				die;	//parsing
	int				eat;	//parsing
	int				sleep;	//parsing
	int				repeat;	//parsing
	long long		start;	//init
	t_philo			*philos;//init
	pthread_mutex_t	*forks;	//init
	pthread_mutex_t	get_forks;
	pthread_mutex_t	timecheck;
	pthread_mutex_t print; // to protect my prints
	bool			dead; // + mutex on dead
}	t_info;

////////////////////// FUNCTIONS //////////////////////

/* parsing.c */
t_info	*ft_parsing(int argc, char **args);

/* utils.c */
void	ft_putstr_fd(char *str, int fd);
int		ft_is_digit(char *str);
int		ft_strlen(char *str);
long	ft_atol(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);

/* init.c */
void	ft_init(t_info *info);
void	ft_init_error(char *str);
void	ft_malloc_err(t_info *info, int stage);

/* time.c */
long long	ft_get_starttime();
long long	ft_timestamp(t_info *info);
void	ft_sleep(t_info *info, long long sleep);
void	ft_print(t_info *info, int p_id, char *str);


/* threads.c */
void	ft_launch_philos(t_info *info);
void	*ft_exec(void *data);
void	ft_pthread_err(t_info *info, char *err);
void	ft_end_philos(t_info *info);


/* philo_does.c */
void	ft_philo_eats(t_info *info, t_philo *philo);
void	ft_philo_sleeps(t_info *info, t_philo *philo);
void	ft_philo_thinks(t_info *info, t_philo *philo);

#endif