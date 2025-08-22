/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:41:51 by maborges          #+#    #+#             */
/*   Updated: 2025/08/22 18:04:05 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//=============================================================================/
//								Librariy Headers                               /
//=============================================================================/

# include <stdio.h> //printf
# include <stdlib.h> // malloc ; free
# include <unistd.h> // write, usleep
# include <stdbool.h> // boolean
# include <pthread.h> // threads: create join detach ;mutex: init dstry (un)lock
# include <stdatomic.h> //
# include <sys/time.h> // gettimeofday
# include <limits.h> //INT_MAX
# include <errno.h> // handle system call errors

//=============================================================================/
//								ANSI SCAPE CODES                               /
//=============================================================================/

# define RESET		"\033[0m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

//=============================================================================/
//								VARIABLES & TYPEDEFS                           /
//=============================================================================/

typedef pthread_mutex_t	t_mtx;
typedef struct s_table	t_table;

//ENUMS
//Enum Mutexes
typedef enum opcode
{
	INIT,
	DESTROY,
	LOCK,
	UNLOCK,
	CREATE,
	JOIN,
	DETACH
}	t_opcode;

// to be send to syncronized log print
typedef enum e_action
{
	A_TAKE_FORK,
	A_EAT,
	A_SLEEP,
	A_THINK,
	A_DIED
}	t_action;

//=============================================================================/
//								STRUCTS                                        /
//=============================================================================/

//STRUCT FORK

typedef struct s_fork
{
	t_mtx	fork;
}	t_fork;

//STRUCT PHILOSOPHER use: ./philo 5 800 200 200 [5]

typedef struct s_philo
{
	int					id;
	long				meals_eaten;
	bool				full;
	long				last_meal; //time passed from last meal
	t_mtx				meal_lock;
	t_fork				*left_fork;
	t_fork				*right_fork;
	pthread_t			thread_id; // a philo is a thread
	t_table				*table;
}	t_philo;

//STRUCT TABLE

typedef struct s_table
{
	long				philo_nbr;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				nbr_must_eat; //[opt arg] | FLAG if -1
	long				start_simulation; // Start timestamp in miliseconds
	t_mtx				print_lock;
	_Atomic bool		end_simulation; //when philo dies or all philos full
	bool				all_threads_ready;
	t_fork				*forks; //array of forks
	t_philo				*philos; //array of philos
	pthread_t			*monitor;
}	t_table;

//=============================================================================/
//								FUNCTION PROTOTYPES                            /
//=============================================================================/

// Error Handlers, Free functions and safety handlers

void		error_msg(const char *error);
int			safe_mutex(t_mtx *mutex, t_opcode mtx_code);
int			safe_thread(pthread_t *thread, void *(*foo)(void *),
				void *data, t_opcode opcode);
void		*safe_malloc(size_t size);

// Utils functions

int			parsing_args(char **av, t_table *table);
long		ft_atol(char *str);

//Inits

int			data_init(t_table *table);
int			dinner_start(t_table *table);

// time + print helpers
// to be checked first

long		now_ms(void);
long		since_start_ms(t_table *table);
void		print_action(t_table *table, int philo_id, t_action action);
void		ft_usleep(long ms);


// Threads

void		*monitor(void *arg);
int			dinner_start(t_table *table);
void		one_philo_routine(t_table *table);
void		routine(t_table *table);


#endif
