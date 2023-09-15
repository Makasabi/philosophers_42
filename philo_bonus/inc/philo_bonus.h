/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:45:31 by makasabi          #+#    #+#             */
/*   Updated: 2023/09/01 16:12:58 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

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
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <semaphore.h>
# include "philo_macros_bonus.h"

////////////////////// STRUCTS //////////////////////

typedef struct s_philo	t_philo;
typedef struct s_info	t_info;

typedef struct s_philo
{
	pid_t			pid;
	int				id;
	// int				l_fork;
	// int				r_fork;
	int				meals;
	long long int	last_meal;
	bool			status;
	t_info			*info;
}	t_philo;

typedef struct s_info
{
	int				n_philos;
	int				die;
	int				eat;
	int				sleep;
	int				think;
	int				repeat;
	long long		start;
	int				dessert;
	t_philo			*philos; //table of pointers to philo structs.
	sem_t			*forks;
	sem_t			*check;
	sem_t			*time;
	sem_t			*milkshake;
	// pthread_mutex_t	*forks;
	// pthread_mutex_t	check;
	// pthread_mutex_t	time;
	// pthread_mutex_t	milkshake;
	bool			dead;
}	t_info;

////////////////////// FUNCTIONS //////////////////////

void			ft_end_philos(t_info *info);
void			ft_finish_prog(t_info *info);
void			ft_fork_err(t_info *info, char *err);
void			ft_malloc_err(t_info *info, int stage);
void			ft_parsing_error(char *err, char *code, t_info *info);
void			*ft_exec(void *data);
void			ft_check_pulse(t_info *info, t_philo *philos);
void			ft_launch_philos(t_info *info);
t_info			*ft_parsing(int argc, char **args);
void			ft_init(t_info *info);
void			ft_philo_eats(t_info *info, t_philo *philo);
void			ft_philo_sleeps(t_info *info, t_philo *philo);
void			ft_philo_thinks(t_info *info, t_philo *philo);
void			ft_print(t_info *info, int p_id, char *str);
void			ft_launch_one_philo(t_info *info);
void			ft_sleep(t_info *info, long long sleep);
long long int	ft_timestamp(t_info *info);
long long int	ft_get_starttime(void);
void			ft_putstr_fd(char *str, int fd);
int				ft_is_digit(char *str);
int				ft_strlen(char *str);
long			ft_atol(const char *str);
void			*ft_calloc(size_t nmemb, size_t size);
#endif