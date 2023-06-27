#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct s_info	t_info;
typedef struct s_philo	t_philo;

typedef struct s_philo
{
	pthread_t	philo_id;
	int			l_fork;
	int			r_fork;
	int			philo_nu;
	t_info		*info;
}	t_philo;

typedef struct s_info
{
	int				n_philos;
	int				die;
	int				eat;
	int				sleep;
	int				repeat;
	t_philo			*philos;
	pthread_mutex_t	*forks;
}	t_info;

void	*ft_exec(void *data)
{
	t_info	*info;
	t_philo	*philo;

	philo = (t_philo *)data;
	info = philo->info;
	printf("This is Philo nu %d\n", philo->philo_nu);
	if (philo->philo_nu % 2 == 0)
	{
		// get fork - mutex 
		if (!pthread_mutex_lock(&info->forks[philo->l_fork]))
		{
			printf("Philo nu %d picked up left fork\n", philo->philo_nu);
			if (!(pthread_mutex_lock(&info->forks[philo->r_fork])))
			{
				// unlock getfork - mutex
				printf("Philo nu %d picked up right fork\n", philo->philo_nu);
				printf("Philo nu %d is eating\n", philo->philo_nu);
				usleep(info->eat);
			}
		}
	}
	else
	{
		if (!pthread_mutex_lock(&info->forks[philo->r_fork]))
		{
			printf("Philo nu %d picked up right fork\n", philo->philo_nu);
			if (!(pthread_mutex_lock(&info->forks[philo->l_fork])))
			{
				printf("Philo nu %d picked up left fork\n", philo->philo_nu);
				printf("Philo nu %d is eating\n", philo->philo_nu);
				usleep(info->eat);
			}
		}
	}
	pthread_mutex_unlock(&info->forks[philo->r_fork]);
	printf("Philo nu %d released right fork\n", philo->philo_nu);
	pthread_mutex_unlock(&info->forks[philo->l_fork]);
	printf("Philo nu %d released left fork\n", philo->philo_nu);
	}

int	main()
{
	t_info	info;
	t_philo	*philos;
	int i;

	i = 0;
	info.n_philos = 5;
	info.die = 800;
	info.eat = 200;
	info.sleep = 200;
	info.repeat = 0;
	philos = malloc(sizeof(t_philo) * info.n_philos);
	info.philos = philos;
	info.forks = malloc(sizeof(pthread_mutex_t) * info.n_philos);

	while(i < info.n_philos)
	{
		philos[i].philo_nu = i+1;
		philos[i].info = &info;
		philos[i].l_fork = i;
		philos[i].r_fork = i + 1 % info.n_philos;
		pthread_mutex_init(&info.forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < info.n_philos)
	{
		pthread_create(&philos[i].philo_id, NULL, ft_exec, &info.philos[i]);
		i++;
	}
	i--;
	while(i >= 0)
	{
		pthread_join(philos[i].philo_id, NULL);
		i--;
	}
	free(philos);
	free(info.forks);
}