# philosophers_42

1. Parsing :
	number_of_philosophers = number of forks
	time_to_die -> in milliseconds: max time since begining of program or beining of previous meal a philo can go w/out eating.
	time_to_eat -> tiime a philo spends eating.
	time_to_sleep -> time a philo spends sleeping.
	[number_of_times_each_philosopher_must_eat]

	Checks to be done whlle parsing args.
	-> only unsigned integer !
	-> is charset ? '0' -> '9'
	-> 11 char check
	-> Atol
	-> int maax / int min

	-> stuct with all info : philos; t_die; t_eat; t_sleep; cycle.

Ex : 3 205 100 100

2.	Utils
	-> Garbage collector.
	-> memset
	-> each philo to get