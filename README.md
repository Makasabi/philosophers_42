# philosophers_42

1. Parsing :
	- number_of_philosophers = number of forks
	- time_to_die -> in milliseconds: max time since begining of program or beining of previous meal a philo can go w/out eating.
	- time_to_eat -> tiime a philo spends eating.
	- time_to_sleep -> time a philo spends sleeping.
	- [number_of_times_each_philosopher_must_eat]

	5 or 6 ac.

	Checks to be done whlle parsing args.
	-> only unsigned integer !
	-> is charset ? '0' -> '9'
	-> 11 char check ?
	-> Atol
	-> int max / int min
	-> cast as unsigned int

	-> stuct with all info : philos; t_die; t_eat; t_sleep; cycle.

Ex : 3 205 100 100

2.	Utils
	-> Garbage collector
	-> each philo be launche as a thread.
	-> mutex on each fork ->
	-> memset ?

3. Major steps
	-> launch counter : from launch of process ?
	-> check args (see parsing)
	-> malloc a tab of number of forks.
	-> In a loop, launch each philo as a thread (each philo declares a variable (flag->alive/dead));
	-> function to be executed in each thread : Mutex fork left and fork right; time to eat; release mutx; time to sleep;
		->conition to mutex : Both fork (pos-1 & pos) are available - otherwise wait. -> Get forks mutex
	-> main thread must show when a philosopher dies.
	-> each philosopher is in an infinite loop where they eat & sleep for a given amount of time and end up dying if the time to die counter is 0;
	-> print relevant information about each philo

4. QUESTION : How to count time in each thread ? or globally ? DONE = FT SLEEP

5. Exit program if 1 philo is dead OR if the number of required occurence happened.
	unlock and destroy all mutex;


https://www.codequoi.com/threads-mutex-et-programmation-concurrente-en-c/

int pthread_create(pthread_t *restrict thread, const pthread_attr_t *restrict attr, void *(*start_routine)(void *), void *restrict arg);

test for data race :
-> compilaton flag : gcc -fsanitize=thread -g <prog.c>
(warning appears upon execution)
--> provides location of data race.

Test to detect thread errors
-> execution through : valgrind --tool=helgrind ./programme.

-> valgrind --tool=helgrind --ignore-thread-creation=yes --log-file=log.txt ./philo args

-> valgrind --tool=drd ./programme.

/!\ Do not use Valgrind & fsanitize together /!\

Mutex :



https://www.codequoi.com/creer-et-tuer-des-processus-fils-en-c/
pid_t	fork(void);
	-> fork process: Parent process creates a child process which is an exact copy of the REST of the parent process but with its own RAM space.
	RETURN values :
		-> Parent = child's PID;
		-> Child = 0;
		-> Error = -1

To see a zombie process :
ps aux | grep <PID> | grep z+

<sys/wait.h>
pid_t	wait(int *status);
pid_t	witPID(pid_t pid, int *statusm it options);

waitpid(-1, status, 0) = wait(status)

valgrind : --child-silent-ater-fork=yes

Useful test
5 800 200 200
no one should die
5 600 150 150
no one should die
4 410 200 200
no one should die
100 800 200 200
no one should die
105 800 200 200
no one should die
200 800 200 200
no one should die


1 800 200 200
a philo should die
4 310 200 100
a philo should die
4 200 205 200
a philo should die

5 800 200 200 7
no one should die, simulation should stop after 7 eats
4 410 200 200 10
no one should die, simulation should stop after 10 eats
-5 600 200 20
should error and not run (no crashing)
4 -5 200 200
should error and not run (no crashing)
4 600 -5 200
should error and not run (no crashing)
4 600 200 -5
should error and not run (no crashing)
4 600 200 200 -5
should error and not run (no crashing)


04/07/2023 
TO DO
	-> 1 Philo scenario
	-> End program when number of meals reached
//	-> Unlock all Mutex when one philo dies
//	-> Clear all Datarace
//	-> Implement 1 variable status in each philo and main thread will check for status of each 