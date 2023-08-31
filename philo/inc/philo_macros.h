/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_macros.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:50:20 by mrony             #+#    #+#             */
/*   Updated: 2023/08/31 11:54:24 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_MACROS_H
# define PHILO_MACROS_H

////////////////////// MACRO //////////////////////

# define INVARG "\033[1;35m🦖 Invalid Argument(s) 🦖\n\033[1;0m"
# define USAGE "\033[0;34mUsage: ./philo <number_of_philosophers> \
<time_to_die> <time_to_eat> <time_to_sleep> \
[<number_of_time_each_philosopher_must_eat>]\n\033[1;0m"
# define EMPTY "\033[0;33mAt least one argument is empty.\033[0m\n"
# define DIGIT "\033[0;33mArgument is not a positive digit.\033[0m\n"
# define INTERR "\033[0;33mArgument does't fit into an int.\033[0m\n"
# define PHILIM "\033[0;33mNumber of philosophers exceeds limit.\033[0m\n"
# define DIEVAL "\033[0;33mTime to die is below limit.\033[0m\n"
# define EATVAL "\033[0;33mTime to eat is below limit.\033[0m\n"
# define SLPVAL "\033[0;33mTime to sleep is below limit.\033[0m\n"

# define MALERR "\033[1;35m🦖 Malloc failled 🦖\n\033[1;0m"
# define INFERR "\033[0;33mInfo struct init failled.\033[0m\n"
# define PTHERR "\033[0;33mPhilo struct table init failled.\033[0m\n"
# define FRKERR "\033[0;33mFork mutex table init failled\033[0m\n"

# define THRERR "\033[1;35m🦖 Thread failled 🦖\n\033[1;0m"
# define INIMTX "\033[0;33mError initiating mutex\033[0m\n"
# define INITRD "\033[0;33mError creating thread\033[0m\n"
# define ERRJOI "\033[0;33mError joining thread\033[0m\n"
# define DESMTX "\033[0;33mError destroying mutex\033[0m\n"

# define FORK "has taken a fork"
# define EATS "is eating"
# define SLPS "is sleeping"
# define THKS "is thinking"
# define DIED "\033[0;31mdied\033[0m"
# define DONE "\033[0;32mPhilosophers all ate at least %d times\033[0m\n"

# define ALIVE 0
# define DEAD 1

#endif