/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:58:28 by maborges          #+#    #+#             */
/*   Updated: 2025/08/25 14:17:09 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*dinner_sim(void *data)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)data;
	table = &philo->table;

	while (read_bool(&table->table_mutex, &table->all_threads_ready) != true)
		;
	while (read_bool(&table->table_mutex, &table->end_simulation) != true)
	{
		if(philo = full) // make thread safe
			break ;
		eat(philo);
		sleep(philo;)
		thinking(philo);

	}
	return (NULL);
}

static int	philos_and_monitor_create(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_nbr)
	{
		table->philos[i].last_meal = now_ms();
		if (safe_thread(table->philos[i].thread_id, dinner_sim, &table->philos[i], CREATE) != 0)
			return (1);
		usleep(100); // is this needed?
	}
	if (safe_thread(table->monitor, monitor, table, CREATE) != 0)
		return (1);
	return (0);
}

int	dinner_start(t_table *table)
{
	int	i;
	if (table->nbr_must_eat == 0)
		return (0);
	else if (table->philo_nbr == 1)
		one_philo_routine(table);
	else
		philos_and_monitor_create(table);
	table->start_simulation = now_ms();
	write_bool(&table->table_mutex, &table->all_threads_ready, true);
	philo_routine(table); //TODO create threads, monitor, join
	i = -1;
	while (++i < table->philo_nbr)
		safe_thread(&table->philos[i].thread_id, NULL, NULL, JOIN);




	// set all_ready flag. table->start_time (ms timestamp)
	//and an atomic/all_ready flag (or mutex+cond).
	//Threads busy-wait on all_ready or check
	//start_time != 0 before proceeding.

	return (0);
}
