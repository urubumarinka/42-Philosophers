/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:41:51 by maborges          #+#    #+#             */
/*   Updated: 2025/08/06 19:04:09 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf
#include <stdlib.h> // malloc ; free
#include <unistd.h> // write, usleep
#include <stdbool.h>
#include <pthread.h> // threads: create join detach ; mutex: init dstry (un)lock
#include <sys/time.h> // gettimeofday
#include <limits.h> //INT_MAX

// COLORS

#define RESET		"\033[0m"
#define BLACK		"\033[30m"
#define RED		"\033[31m"
#define GREEN		"\033[32m"
#define YELLOW		"\033[33m"
#define BLUE		"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN		"\033[36m"
#define WHITE		"\033[37m"

typedef pthread_mutex_t	t_mtx;
typedef struct s_table	t_table;

//STRUCT FORK

typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}	t_fork;

//STRUCT PHILOSOPHER use: ./philo 5 800 200 200 [5]

typedef struct s_philo
{
	int			id;
	long		nbr_meals;
	bool		full;
	long		last_meal; //time passed from last meal
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	thread_id; // a philo is a thread
	t_table		*table;
}	t_philo;

//STRUCT TABLE

typedef struct s_table
{
	long		philo_nbr;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		nbr_must_eat; //[opt arg] | FLAG if -1
	long		start_simulation;
	bool		end_simulation; //when philo dies or all philos full
	t_fork		*forks; //array of forks
	t_philo		*philos; //arrray of philos
}	t_table;

// Error Handlers and Free functions

void	error_msg(const char *error);
