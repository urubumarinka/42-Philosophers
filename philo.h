/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:41:51 by maborges          #+#    #+#             */
/*   Updated: 2025/07/24 14:21:35 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf
#include <stdlib.h> // malloc ; free
#include <unistd.h> // write, usleep
#include <stdbool.h>
#include <pthread.h> // threads: create join detach ; mutex: init dstry (un)lock
#include <sys/time.h> // gettimeofday
#include <limits.h> //INT_MAX

typedef pthread_mutex_t	t_mtx;

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
