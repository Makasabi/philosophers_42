/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 09:24:12 by mrony             #+#    #+#             */
/*   Updated: 2023/08/31 15:25:14 by mrony            ###   ########.fr       */
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
# include "philo_macros.h"

////////////////////// STRUCTS //////////////////////

typedef struct s_philo	t_philo;
typedef struct s_info	t_info;

typedef struct s_philo
{
	pthread_t		t_id;
	int				id;
	int				l_fork;
	int				r_fork;
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
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	check;
	pthread_mutex_t	time;
	pthread_mutex_t	milkshake;
	bool			dead;
}	t_info;

////////////////////// FUNCTIONS //////////////////////

/* utils.c */
void		ft_putstr_fd(char *str, int fd);
int			ft_is_digit(char *str);
int			ft_strlen(char *str);
long		ft_atol(const char *str);
void		*ft_calloc(size_t nmemb, size_t size);

/* init.c */
t_info		*ft_parsing(int argc, char **args);
void		ft_init(t_info *info);

/* errors.c */
void		ft_malloc_err(t_info *info, int stage);
void		ft_parsing_error(char *err, char *code, t_info *info);
void		ft_pthread_err(t_info *info, char *err);

/* time.c */
long long	ft_get_starttime(void);
long long	ft_timestamp(t_info *info);
void		ft_sleep(t_info *info, long long sleep);

/* threads.c */
void		ft_launch_philos(t_info *info);
void		*ft_exec(void *data);
void		ft_end_philos(t_info *info);
void		ft_check_pulse(t_info *info, t_philo *philos);

/* philo_does.c */
void		ft_philo_eats(t_info *info, t_philo *philo);
void		ft_philo_sleeps(t_info *info, t_philo *philo);
void		ft_philo_thinks(t_info *info, t_philo *philo);
void		ft_print(t_info *info, int p_id, char *str);

/* philo_is_alone.c */
void		*ft_philo_is_alone(void *data);
void		ft_launch_one_philo(t_info *info);

#endif